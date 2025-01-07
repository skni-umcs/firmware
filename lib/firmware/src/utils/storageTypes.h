#ifndef STORAGETYPES_H
#define STORAGETYPES_H

#include <string>
#include <vector>

#define INVALID_ADDRESS -1
#define INVALID_CRC -1;
#define INVALID_STRING "";
#define INVALID_VECTOR {};

typedef short moduleAddress;
const moduleAddress SERVER_ADDRESS = 0;

class Message {
    protected:
    std::vector<moduleAddress> senders;
    moduleAddress destination;
    std::string content;

    public:
        Message(std::string packet);
        Message(std::vector<moduleAddress> senders, moduleAddress destination, std::string content);
        std::vector<moduleAddress> getSenders();
        moduleAddress getDestination();
        std::string getContent();
        moduleAddress getOriginalSender();
};

class LoraMessage : public Message {
    public:
    LoraMessage(std::string packet);
};

#endif