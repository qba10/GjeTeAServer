#include "Weapon.h"
namespace SSJServer {

	Bullet* Weapon::CreateBullet(Point ownerPosition, Degrees ownerAngle, WeaponType type){
		BulletFactory::setOwnerPosition(ownerPosition);
		BulletFactory::setOwnerAngle(ownerAngle);
		switch(type){
		case Glock:
			return BulletFactory::CreateGlockBullet();
			break;
		case Uzi:
			return BulletFactory::CreateUziBullet();
			break;
		case Ak47:
			return BulletFactory::CreateAk47Bullet();
			break;
		case M16:
			return BulletFactory::CreateM16Bullet();
			break;
		case Shotgun:
			return BulletFactory::CreateShotgunBullet();
			break;
		case SniperRifle:
			return BulletFactory::CreateSniperRifleBullet();
			break;
		case Bazooka:
			return BulletFactory::CreateBazookaBullet();
			break;
		case Grenade:
			return BulletFactory::CreateGrenadeBullet();
			break;
		case Knife:
			return BulletFactory::CreateKnifeBullet();
			break;
		}
        return NULL;
	}

	void Weapon::Shoot(){
		
		this->timeBetweenBullets = this->clock.getElapsedTime();
		this->clock.restart();
		if(timeBetweenBullets.asSeconds() > this->fireRate){
			
            //LayerContainer::GetGameLayer("trzecia")->addObject(Weapon::CreateBullet(this->owner->getMapPosition(), this->owner->getAngle(), this->type));

		}
	}

	WeaponType Weapon::getName(){
		return this->type;
	}

	Weapon::Weapon(){
        this->ammo = maxAmmo;
		this->clock.restart();
    }

    void Weapon::Hit(){

    }

    void Weapon::HitByBlast(){

    }

    int Weapon::getMaxAmmo(){
        return this->maxAmmo;
    }

    int Weapon::getAmmo(){
        return this->ammo;
    }

    void Weapon::setMaxAmmo(int maxAmmo){
        this->maxAmmo = maxAmmo;
    }

    void Weapon::decreaseAmmo(){
        if(this->ammo > 0)
            this->ammo -= 1;
    }

    void Weapon::setAmmo(int ammo){
        this->ammo = ammo;
    }

    void Weapon::setReloadTime(int reloadTime){
        this->reloadTime = reloadTime;
    }

    void Weapon::setDamage(int damage){
        this->damage = damage;
    }

    void Weapon::setFireRate(int fireRate){
        this->fireRate = fireRate;
    }

	Weapon::~Weapon(){

	}



	void Weapon::update(){

	}

    void Weapon::SynchronizationObject(Json::Value){

    }
	Json::Value Weapon::serialize()
    {
		Json::Value object;
		object["objectName"] = _Weapon;
		object["mapPositionX"] =  this->getMapPosition().x;
		object["mapPositionY"] =  this->getMapPosition().y;
		object["activity"] = this->activity;
		object["name"] = this->name;

        return object;
    }

}

 