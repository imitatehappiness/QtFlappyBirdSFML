
<p align="center">
  <a href="https://github.com/imitatehappiness/QtFlappyBirdSFML">
    <img src="https://cdn.worldvectorlogo.com/logos/flappy-bird.svg" alt="Logo" width="600" height="200">  
  </a>

  
  <h3 align="center"></h3>
</p>

# Flappy Bird Clone Game using C++/Qt and SFML

This project is a clone of the popular mobile game "Flappy Bird," implemented using C++ programming language with the Qt and SFML libraries. The game has been recreated as a fun learning exercise to explore C++ programming, game development, and the integration of Qt and SFML for creating interactive applications.
"Flappy bird" clone game using C++/Qt and SFML.

>**SFML:**  2.5.1 GCC 7.3.0 MinGW (SEH) - 64-bit
>
>**Compiler:**  MinGW 8.1.0 64-bit
>
>**Profile Qt:**  5.15.2 MinGW 64-bit

## Features
+ Simple and addictive gameplay inspired by the original "Flappy Bird" game.
+ Utilization of SFML for handling graphics and sound.
+ Implementation of basic physics for character movement, game controls, and scoring.

## How to build the project

Download the SFML library [here](https://www.sfml-dev.org/).

Can download precompiled SFML libraries, but if you have a compiler that is different from the one that these libraries were assembled, then nothing will work.  Assemble a library with that compiler, which you will build the project.

Add the SFML directory to the project root, which will contain three directories: ***lib, bin and include.***

### Connecting the SFML library to a project on Qt:
```
LIBS += -L$$PWD/SFML/bin
CONFIG(release, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include
```

```$$PWD``` - means the location of the pro project file, in which we register the project configuration and the connected files. 

### Turn off Shadow Build in Qt Creator

## Example
<p align="center">
  <img src="https://user-images.githubusercontent.com/79199956/217288394-d9f0beb4-1079-4283-9d8b-180487abe39b.gif" />
</p>




