#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "staticobject.h"
#include "mainplayer.h"
namespace SSJServer {

class ObjectManager
{
    private:
        static void addObjectToObjectsList(Object *);
    public:
        ObjectManager();
       static void CreatePlayer(string PlayerId);
    };
}
#endif // OBJECTMANAGER_H
