#ifndef CONFIG_H
#define CONFIG_H
#include "loader.h"
namespace SSJServer{
#define _J(enum) intToString(enum)
    string intToString(int);
enum WeaponType{
    Glock,
    Uzi,
    Ak47,
    M16,
    Shotgun,
    SniperRifle,
    Bazooka,
    Grenade,
    Knife
};
enum RequestName{
    _synchronizeMainPlayer,
    _createMainPlayer,
    _createBullet,
    _createWeapon

};

enum JsonOption{
    _mapPositionX,
    _mapPositionY,
    _activity,
    _hp,
    _maxHP,
    _velocity,
    _angle,
    _targetAngle,
    _playerId,
    _ask,
    _parameters,
    _objectName,
    _name,
    _ownerPositionX,
    _ownerPositionY,
    _ownerAngle,
    _weaponType,
    _objectAmount,
    _synchronize,
	_syncId

};
enum ObjectType{
    _Object,
    _InteractiveObject,
    _StaticObject,
    _DynamicObject,
    _MainPlayer,
    _Player,
    _Bullet,
    _Weapon

};

    class Object;
    class Config
    {
    public:
       static size_t RotationSpeed;
    };
}


#endif // CONFIG_H
