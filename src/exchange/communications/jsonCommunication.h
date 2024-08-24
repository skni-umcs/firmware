#ifndef JSONCOMMUNICATION_H
#define JSONCOMMUNICATION_H

#include <vector>
#include <exchange/transmits/jsonTransmit.h>
#include "communication.h"
#include <memory>

class JsonCommunication : public Communication {
    
    protected:
        std::vector<std::unique_ptr<JsonTransmit>> transmitTo;
    public:
        static std::shared_ptr<JsonCommunication> create();
        OperationResult getNotified(std::string message) override;
        OperationResult transmit(std::string message) override;
        OperationResult subscribe(std::unique_ptr<JsonTransmit> transmit);
        OperationResult unsubscribe(std::unique_ptr<JsonTransmit> transmit);
};

#endif