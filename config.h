#ifndef CONFIG_H
#define CONFIG_H
#include "loader.h"
namespace SSJServer{
enum ObjectType{
        _Object,
        _InteractiveObject,
        _StaticObject,
        _DynamicObject,
        _MainPlayer,
        _Player

};
    class Object;
    class Config
    {
    public:
       static size_t RotationSpeed;
    };
}

#endif // CONFIG_H
