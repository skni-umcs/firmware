#ifndef PACKETUTILS_H
#define PACKETUTILS_H

#include <string>
#include "storageTypes.h"
#include <ArduinoJson.h>
#include <FastCRC.h>

const char PACKET_BORDER = '~';
const char MAIN_JSON_BORDER = '^';
const char NODE_BORDER = '$';

const unsigned char DESTINATION_INDEX = 0;
const unsigned char ORIGINAL_SENDER_INDEX = 1;

enum class TransmissionCode : char {
    RESET = 'r',
    MESSAGE_TYPE = 't',
    MESSAGE = 'm'
};

class PacketMessage {
    TransmissionCode type;
    std::string message;

    public:
        PacketMessage(TransmissionCode type, std::string message);
        std::string getJson();
};

template<typename T>
std::string toHexString(T address);
std::string transmissionCodeFromEnum(TransmissionCode transmissionCode);
std::string createPacket(Message message);
moduleAddress getDestinationAddress(std::string packet);
std::vector<std::string> allAddressTableElements(std::string packet);
std::string nthLastAddressTableElement(std::vector<std::string> addressTableElements, unsigned char n);
moduleAddress nthLastAddress(std::vector<std::string> addressTableElements, unsigned char n);
std::vector<moduleAddress> getSenders(std::vector<std::string> addressTable);
std::string getPacketContent(std::string packet);
std::string getValidatedPart(std::string packet);
bool isCrcCorrect(std::string packet);
bool isPacketCorrect(std::string packet);

#endif