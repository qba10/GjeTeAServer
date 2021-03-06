TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /home/qba/SFML-2.1/include
LIBS += -L//home/qba/SFML-2.1/lib -lsfml-system-d -lsfml-graphics-d -lsfml-window-d -ljsoncpp -lsfml-network-d
SOURCES += main.cpp \
    clientlistener.cpp \
    gjeteaserver.cpp \
    loader.cpp \
    datacontainer.cpp \
    degrees.cpp \
    dynamicobject.cpp \
    interactiveobject.cpp \
    mainplayer.cpp \
    object.cpp \
    point.cpp \
    staticobject.cpp \
    config.cpp \
    objectmanager.cpp \
    Bullet.cpp \
    BulletFactory.cpp \
    Weapon.cpp \
    WeaponFactory.cpp \
    helpers.cpp

HEADERS += \
    gjeteaserver.h \
    loader.h \
    datacontainer.h \
    degrees.h \
    dynamicobject.h \
    interactiveobject.h \
    mainplayer.h \
    object.h \
    point.h \
    staticobject.h \
    config.h \
    objectmanager.h \
    Bullet.h \
    BulletFactory.h \
    Weapon.h \
    WeaponFactory.h \
    clientlistener.h \
    helpers.h

OTHER_FILES +=

