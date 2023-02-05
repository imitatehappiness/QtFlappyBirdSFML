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
        game.cpp \
        inputmanager.cpp \
        main.cpp \
        statemachine.cpp

RESOURCES += \
    resources/resourses.qrc

HEADERS += \
    assetmanager.h \
    game.h \
    inputmanager.h \
    state.h \
    statemachine.h

