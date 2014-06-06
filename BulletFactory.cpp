#include "BulletFactory.h"
namespace SSJServer{
	Point BulletFactory::ownerPosition;

	void BulletFactory::setOwnerPosition(Point ownerPosition){
		BulletFactory::ownerPosition = ownerPosition;
	}

	Degrees BulletFactory::ownerAngle;

	void BulletFactory::setOwnerAngle(Degrees ownerAngle){
		BulletFactory::ownerAngle = ownerAngle;
	}


    Bullet* BulletFactory::CreateGlockBullet(){
        Bullet* GlockBullet = new Bullet();
        GlockBullet->name =				"Glock";
        GlockBullet->setType(           Glock);
        GlockBullet->range =			400;
        GlockBullet->setVelocity(		10);
        GlockBullet->damage =			25;
        GlockBullet->blastFire =		false;
        GlockBullet->blastRange =		0;
        GlockBullet->ownerPosition =	BulletFactory::ownerPosition;
        GlockBullet->setMapPosition(	BulletFactory::ownerPosition);
        GlockBullet->setAngle(			BulletFactory::ownerAngle);
        return GlockBullet;
    }
    Bullet* BulletFactory::CreateUziBullet(){
        Bullet* UziBullet = new Bullet();
        UziBullet->name =				"Uzi";
        UziBullet->setType(             Uzi);
        UziBullet->range =				500;
        UziBullet->setVelocity(			12);
        UziBullet->damage =				10;
        UziBullet->blastFire =			false;
        UziBullet->blastRange =			0;
        UziBullet->ownerPosition =		BulletFactory::ownerPosition;
        UziBullet->setMapPosition(		BulletFactory::ownerPosition);
        UziBullet->setAngle(			BulletFactory::ownerAngle);
        return UziBullet;
    }
    Bullet* BulletFactory::CreateAk47Bullet(){
        Bullet* Ak47Bullet = new Bullet();
        Ak47Bullet->name =				"Ak-47";
        Ak47Bullet->setType(            Ak47);
        Ak47Bullet->range =				800;
        Ak47Bullet->setVelocity(		18);
        Ak47Bullet->damage =			15;
        Ak47Bullet->blastFire =			false;
        Ak47Bullet->blastRange =		0;
        Ak47Bullet->ownerPosition =		BulletFactory::ownerPosition;
        Ak47Bullet->setMapPosition(		BulletFactory::ownerPosition);
        Ak47Bullet->setAngle(			BulletFactory::ownerAngle);
        return Ak47Bullet;
    }
    Bullet* BulletFactory::CreateM16Bullet(){
        Bullet* M16Bullet = new Bullet();
        M16Bullet->name =				"M-16";
        M16Bullet->setType(             M16);
        M16Bullet->range =				800;
        M16Bullet->setVelocity(			18);
        M16Bullet->damage =				12;
        M16Bullet->blastFire =			false;
        M16Bullet->blastRange =			0;
        M16Bullet->ownerPosition =		BulletFactory::ownerPosition;
        M16Bullet->setMapPosition(		BulletFactory::ownerPosition);
        M16Bullet->setAngle(			BulletFactory::ownerAngle);
        return M16Bullet;
    }
    Bullet* BulletFactory::CreateShotgunBullet(){
        Bullet* ShotgunBullet = new Bullet();
        ShotgunBullet->name =			"Shotgun";
        ShotgunBullet->setType(         Shotgun);
        ShotgunBullet->range =			300;
        ShotgunBullet->setVelocity(		14);
        ShotgunBullet->damage =			50;
        ShotgunBullet->blastFire =		true;
        ShotgunBullet->blastRange =		20;
        ShotgunBullet->ownerPosition =	BulletFactory::ownerPosition;
        ShotgunBullet->setMapPosition(	BulletFactory::ownerPosition);
        ShotgunBullet->setAngle(		BulletFactory::ownerAngle);
        return ShotgunBullet;
    }
    Bullet* BulletFactory::CreateSniperRifleBullet(){
        Bullet* SniperRifleBullet = new Bullet();
        SniperRifleBullet->name =		"Sniper rifle";
        SniperRifleBullet->setType(     SniperRifle);
        SniperRifleBullet->range =		1000;
        SniperRifleBullet->setVelocity(	16);
        SniperRifleBullet->damage =		100;
        SniperRifleBullet->blastFire =	false;
        SniperRifleBullet->blastRange =	0;
        SniperRifleBullet->ownerPosition =	BulletFactory::ownerPosition;
        SniperRifleBullet->setMapPosition(	BulletFactory::ownerPosition);
        SniperRifleBullet->setAngle(		BulletFactory::ownerAngle);
        return SniperRifleBullet;
    }
    Bullet* BulletFactory::CreateBazookaBullet(){
        Bullet* BazookaBullet = new Bullet();
        BazookaBullet->name =			"Bazooka";
        BazookaBullet->setType(         Bazooka);
        BazookaBullet->range =			600;
        BazookaBullet->setVelocity(		4);
        BazookaBullet->damage =			100;
        BazookaBullet->blastFire =		true;
        BazookaBullet->blastRange =		100;
        BazookaBullet->ownerPosition =	BulletFactory::ownerPosition;
        BazookaBullet->setMapPosition(	BulletFactory::ownerPosition);
        BazookaBullet->setAngle(		BulletFactory::ownerAngle);
        return BazookaBullet;
    }
    Bullet* BulletFactory::CreateGrenadeBullet(){
        Bullet* GrenadeBullet = new Bullet();
        GrenadeBullet->name =			"Grenade";
        GrenadeBullet->setType(         Grenade);
        GrenadeBullet->range =			500;
        GrenadeBullet->setVelocity(		6);
        GrenadeBullet->damage =			100;
        GrenadeBullet->blastFire =		true;
        GrenadeBullet->blastRange =		70;
        GrenadeBullet->ownerPosition =	BulletFactory::ownerPosition;
        GrenadeBullet->setMapPosition(	BulletFactory::ownerPosition);
        GrenadeBullet->setAngle(		BulletFactory::ownerAngle);
        return GrenadeBullet;
    }
    Bullet* BulletFactory::CreateKnifeBullet(){
        Bullet* KnifeBullet = new Bullet();
        KnifeBullet->name =				"Knife";
        KnifeBullet->setType(           Knife);
        KnifeBullet->range =			50;
        KnifeBullet->setVelocity(		0);
        KnifeBullet->damage =			35;
        KnifeBullet->blastFire =		false;
        KnifeBullet->blastRange =		0;
        KnifeBullet->ownerPosition =	BulletFactory::ownerPosition;
        KnifeBullet->setMapPosition(	BulletFactory::ownerPosition);
        KnifeBullet->setAngle(			BulletFactory::ownerAngle);
        return KnifeBullet;
    }

}
 
