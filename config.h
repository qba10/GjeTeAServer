#ifndef CONFIG_H
#define CONFIG_H
#include "loader.h"
namespace SSJServer{
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
    _createBullet

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

};
enum ObjectType{
    _Object,
    _InteractiveObject,
    _StaticObject,
    _DynamicObject,
    _MainPlayer,
    _Player,
    _Bullet

};
    class Object;
    class Config
    {
    public:
       static size_t RotationSpeed;
    };
}

#endif // CONFIG_H
