#ifndef WIFITRANSMIT_H
#define WIFITRANSMIT_H

#include <string>
#include <exchange/communications/communication.h>
#include "transmit.h"
#include "jsonTransmit.h"
#include "utils/storageTypes.h"

class WifiTransmit : public JsonTransmit
{
    public:
        OperationResult send(std::string message, moduleAddress destinationNode) override;
        OperationResult send(std::shared_ptr<Message> message) override;
        OperationResult receive(std::shared_ptr<Message> message) override;
};

#endif