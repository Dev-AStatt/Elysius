TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        devUtilities.h \
        engine/elysiusGameLoop.cpp \
        engine/graphicsEngine.cpp \
        libraries/olcPixelGameEngine.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
	engine/MenuStructure.h \
	engine/elysiusGameLoop.h \
	engine/gameConf.h \
	engine/graphicsEngine.h \
	engine/userInput.h \
	libraries/olcPixelGameEngine.h \
	structures/Epos.h \
	world/OrbitalObject.h \
	world/solarSystem.h \
	world/spacecraft.h \
	world/systemsManager.h
