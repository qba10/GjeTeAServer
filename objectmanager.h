#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "staticobject.h"
#include "mainplayer.h"
#include "BulletFactory.h"

namespace SSJServer {

class ObjectManager
{
    private:
        static void addObjectToObjectsList(Object *);
    public:
	   static int nextId;
       ObjectManager();
       static void CreatePlayer(string PlayerId);
       static void CreateBullet(Json::Value);
       static void CreateWeapon(Json::Value, string playerID);
    };
}
#endif // OBJECTMANAGER_H
 

