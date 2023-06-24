#!/bin/bash

g++ -c main.cpp

echo "Compile object file - Done!"
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
echo "Compile app - Done!"
./sfml-app
