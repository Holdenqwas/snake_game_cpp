#!/bin/bash

g++ -c main.cpp GameLogic/Controller.cpp GameLogic/Snake.cpp GameLogic/utils.cpp

echo "Compile object file - Done!"
g++ main.o Controller.o Snake.o utils.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
echo "Compile app - Done!"
./sfml-app
