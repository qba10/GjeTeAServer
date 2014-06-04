#ifndef DATACONTAINER_H
#define DATACONTAINER_H
#include "config.h"
namespace SSJServer {
    class DataContainer
    {
    public:
        static vector <Object*> ObjectLists;
        static sf::Time DeltaTime;
        static map <string, Object*> PlayerList;
    };
}
#endif // DATACONTAINER_H
