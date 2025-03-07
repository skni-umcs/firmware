#ifndef BIGCOMMUNICATION_H
#define BIGCOMMUNICATION_H

#include <vector>
#include <exchange/transmits/bigTransmit.h>
#include "utils/storageTypes.h"

class BigCommunication : public Communication {
    std::vector<std::shared_ptr<BigTransmit>> transmitTo;
    public:
        std::shared_ptr<Communication> create();
        OperationResult getNotified(std::shared_ptr<Message> message) override;
        OperationResult transmit(std::string message, moduleAddress destinationNode) override;
        virtual OperationResult subscribe(std::shared_ptr<BigTransmit> bigTransmit) = 0;
        virtual OperationResult unsubscribe(std::shared_ptr<BigTransmit> bigTransmit) = 0;
};

#endif