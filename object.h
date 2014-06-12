#ifndef OBJECT_H
#define OBJECT_H
#include "datacontainer.h"
namespace SSJServer{


    class Object
    {
    protected:

        Point mapPosition;
        bool activity;
        bool syncEventActive;
        sf::Time syncPeriod;
        bool syncNow;
        sf::Time blockSyncTime;
    private:
        void setDefaultVar();

    public:
        Object();
        Object(float x, float y);
        Object(Point);
        Point getMapPosition();
        void setMapPosition(float x, float y);
        void setMapPosition(Point screenPosition);
        virtual void update() = 0;
        virtual Json::Value serialize() = 0;
        void setActivity(bool activity);
        bool isActive();
        void setSyncEvent(string);
        void setSyncPeriod(sf::Time);

		int syncId;  /* Unique Id used to identificate objects on server */
        bool isSyncNow() const;
        void setSyncNow(bool value);
        bool isSyncEventActive() const;
        void setSyncEventActive(bool value);
        void appendBlockSyncTime(sf::Time);
        sf::Time getBlockSyncTime() const;
        sf::Time getSyncPeriod() const;
        void setBlockSyncTime(const sf::Time &value);
        void setSyncNow();
    };


}
#endif // OBJECT_H
