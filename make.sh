#/bin/sh
cd /home/aleksandr/Desktop/sfml
g++ -c main.cpp
g++ main.o -o sfml-app.exe -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
