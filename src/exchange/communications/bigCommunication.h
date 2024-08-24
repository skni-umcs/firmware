#ifndef BIGCOMMUNICATION_H
#define BIGCOMMUNICATION_H

#include "sensor.h"
#include <vector>
#include <exchange/transmits/bigTransmit.h>

class BigCommunication : public Communication {
    std::vector<std::unique_ptr<BigTransmit>> transmitTo;
    public:
        OperationResult getNotified(std::string message) override;
        OperationResult transmit(std::string message) override;
        virtual OperationResult subscribe(std::unique_ptr<BigTransmit> bigTransmit) = 0;
        virtual OperationResult unsubscribe(std::unique_ptr<BigTransmit> bigTransmit) = 0;
};

#endif