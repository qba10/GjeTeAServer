#include "objectmanager.h"
namespace SSJServer {


    void ObjectManager::addObjectToObjectsList(Object * object)
    {
        DataContainer::ObjectLists.push_back(object);
    }

    ObjectManager::ObjectManager()
        {



    }

    void ObjectManager::CreatePlayer(string PlayerId)
    {
        MainPlayer *obiekt = new MainPlayer();
        obiekt->setPlayerId(PlayerId);
        ObjectManager::addObjectToObjectsList(obiekt);
        DataContainer::PlayerList[PlayerId] = obiekt;
    }
}
