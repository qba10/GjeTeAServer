#ifndef GJETEASERVER_H
#define GJETEASERVER_H
#include "objectmanager.h"
namespace SSJServer {
    class GjeTeAServer
    {
    private:
        sf::Packet packetToSend;
        Json::Value jsonToSend;
    public:
        GjeTeAServer();
        void Update();
        void CreatePacketToSend();
        sf::Packet getPacketToSend();
    };
}

#endif // GJETEASERVER_H
 