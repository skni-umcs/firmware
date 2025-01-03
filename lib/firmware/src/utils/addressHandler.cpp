
#include "addressHandler.h"
#include <WString.h>
#include <HardwareSerial.h>
#include <string>
#include "stringUtils.h"
#include <Preferences.h>

Preferences preferences;
std::shared_ptr<AddressHandler> AddressHandler::instance;

std::shared_ptr<AddressHandler> AddressHandler::getInstance() {
    if(!instance) {
        instance = std::shared_ptr<AddressHandler>{new AddressHandler()};
    }
    return instance;
}

void AddressHandler::saveAddress(moduleAddress address) {
    preferences.putUShort(PREFERENCES_ADDRESS_KEY, address);
}

moduleAddress AddressHandler::readAddress() {
    return preferences.getUShort(PREFERENCES_ADDRESS_KEY);
}

moduleAddress AddressHandler::getAddressFromUser() {
    String input = "";
    char character;
    while(true) {
        character = Serial.read();
        if(character != 255) {
            Serial.print(character);
            if(character == '\n') {
                break;
            }
            else {
                input += character;
            }
        }
    }
    int inputInt = std::stoi(fromWString(input));
    if(inputInt < MIN_MODULE_ADDRESS || inputInt > MAX_MODULE_ADDRESS) {
        throw std::range_error("incorrect address provided");
    }
    return (moduleAddress)inputInt;
}

void AddressHandler::initializeAddress() {
    preferences.begin("address");
    moduleAddress addressInMemory = readAddress();
    if(addressInMemory == 0) {
        Serial.printf(
            "What address should this module have? (no backspace allowed) (%d - %d)\n", 
            MIN_MODULE_ADDRESS, 
            MAX_MODULE_ADDRESS 
        );
        moduleAddress newAddress = getAddressFromUser();
        address = newAddress;
        saveAddress(newAddress);
    }
    else {
        address = addressInMemory;
    }
    Serial.printf("Module address: %d\n", address);
}
