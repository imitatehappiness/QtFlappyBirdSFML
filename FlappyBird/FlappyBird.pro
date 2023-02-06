TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt console

LIBS += -L$$PWD/SFML/bin
CONFIG(release, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include

SOURCES += \
        assetmanager.cpp \
        bird.cpp \
        game.cpp \
        gameoverstate.cpp \
        gamestate.cpp \
        inputmanager.cpp \
        land.cpp \
        main.cpp \
        mainmenustate.cpp \
        pipe.cpp \
        splashstate.cpp \
        statemachine.cpp

HEADERS += \
    assetmanager.h \
    bird.h \
    defenitions.h \
    game.h \
    gameoverstate.h \
    gamestate.h \
    inputmanager.h \
    land.h \
    mainmenustate.h \
    pipe.h \
    splashstate.h \
    state.h \
    statemachine.h

RESOURCES += \
    resources/resourses.qrc
