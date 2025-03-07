#ifndef TESTTRANSMIT_T
#define TESTTRANSMIT_T

#include <string>
#include <exchange/communications/communication.h>
#include "exchange/transmits/jsonTransmit.h"
#include "utils/storageTypes.h"

class TestTransmit : public JsonTransmit
{
    public:
        OperationResult send(std::string message, moduleAddress moduleAddress) override;
        OperationResult send(std::shared_ptr<Message> message) override;
        OperationResult receive(std::shared_ptr<Message> message) override;
};

#endif