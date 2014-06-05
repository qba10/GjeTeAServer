#include "clientlistener.h"
#include "gjeteaserver.h"

int main()
{
    std::cout << "Server GjeTeA Running" << std::endl;

    bool done = false;

    SSJServer::ClientListener clientListener;
    SSJServer::GjeTeAServer GjeTeAServerObject;
    while(!done)
    {

        clientListener.Listener();
        GjeTeAServerObject.Update();
        clientListener.setPacketToSend(GjeTeAServerObject.getPacketToSend());
        clientListener.SenderToClients();



    }
    clientListener.CleanConnections();

    return 0;
}
 