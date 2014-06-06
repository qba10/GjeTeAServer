#include "objectmanager.h"
namespace SSJServer {

	int ObjectManager::nextId = 0;
    void ObjectManager::addObjectToObjectsList(Object * object)
    {
		for(int i = 0 ; i < DataContainer::ObjectLists.size() ; ++i)
		{
			if(DataContainer::ObjectLists[i]->isActive() == false)
			{
				for( map <string, Object*>::iterator it = DataContainer::PlayerList.begin() ; 
					it != DataContainer::PlayerList.end(); 
					it++)
				{
					if(it->second == DataContainer::ObjectLists[i]);
					DataContainer::PlayerList.erase(it);
					break;
				}
				delete DataContainer::ObjectLists[i];
				DataContainer::ObjectLists[i] = object;
				return;
			}
		}
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
		obiekt->syncId = nextId++;
    }

    void ObjectManager::CreateBullet(Json::Value parameters){
		Bullet* tmp;
		Point tmpPoint;
        tmpPoint.x = parameters[_J(_ownerPositionX)].asDouble();
        tmpPoint.y = parameters[_J(_ownerPositionY)].asDouble();
        Degrees tmpDegrees = parameters[_J(_ownerAngle)].asDouble();
		BulletFactory::setOwnerPosition(tmpPoint);
		BulletFactory::setOwnerAngle(tmpDegrees);
        switch(static_cast<WeaponType>(parameters[_J(_weaponType)].asInt())){
		case Glock:
			tmp = BulletFactory::CreateGlockBullet();
			break;
		case Uzi:
			tmp = BulletFactory::CreateUziBullet();
			break;
		case Ak47:
			tmp =  BulletFactory::CreateAk47Bullet();
			break;
		case M16:
			tmp =  BulletFactory::CreateM16Bullet();
			break;
		case Shotgun:
			tmp =  BulletFactory::CreateShotgunBullet();
			break;
		case SniperRifle:
			tmp =  BulletFactory::CreateSniperRifleBullet();
			break;
		case Bazooka:
			tmp =  BulletFactory::CreateBazookaBullet();
			break;
		case Grenade:
			tmp =  BulletFactory::CreateGrenadeBullet();
			break;
		case Knife:
			tmp =  BulletFactory::CreateKnifeBullet();
			break;
		}

		ObjectManager::addObjectToObjectsList(tmp);
		tmp->syncId = nextId++;
	}

    void ObjectManager::CreateWeapon(Json::Value parameters, string playerID){
/*		Weapon* tmp;
		Point tmpPoint;
        tmpPoint.x = parameters[_J(_ownerPositionX)].asDouble();
        tmpPoint.y = parameters[_J(_ownerPositionY)].asDouble();
		WeaponFactory::setOwner(dynamic_cast<DynamicObject*>(DataContainer::PlayerList.at(playerID)));
        switch(static_cast<WeaponType>(parameters[_J(_weaponType)].asInt())){
		case Glock:
			tmp = WeaponFactory::CreateGlockObject();
			break;
		case Uzi:
			tmp = WeaponFactory::CreateUziObject();
			break;
		case Ak47:
			tmp =  WeaponFactory::CreateAk47Object();
			break;
		case M16:
			tmp =  WeaponFactory::CreateM16Object();
			break;
		case Shotgun:
			tmp =  WeaponFactory::CreateShotgunObject();
			break;
		case SniperRifle:
			tmp =  WeaponFactory::CreateSniperRifleObject();
			break;
		case Bazooka:
			tmp =  WeaponFactory::CreateBazookaObject();
			break;
		case Grenade:
			tmp =  WeaponFactory::CreateGrenadeObject();
			break;
		case Knife:
			tmp =  WeaponFactory::CreateKnifeObject();
			break;
		}

		ObjectManager::addObjectToObjectsList(tmp);
        */
	}


}
 

