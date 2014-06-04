#ifndef OBJECT_H
#define OBJECT_H
#include "datacontainer.h"
namespace SSJServer{


    class Object
    {
    protected:

        Point mapPosition;
        bool activity;


    public:
        Object();
        Object(double x, double y);
        Object(Point);
        Point getMapPosition();
        void setMapPosition(double x, double y);
        void setMapPosition(Point screenPosition);
        virtual void update() = 0;
        virtual Json::Value serialize() = 0;
        void setActivity(bool activity);
        bool isActive();
    };


}
#endif // OBJECT_H
