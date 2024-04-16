#pragma once

// Libraries
#include <iostream>
#include <sstream>
#include <string>
// #include <vector>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
// #include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


class Game {

private:
    // Vars
    RenderWindow* window;
    VideoMode vm;
    Event ev;
    // Private Functions
    void initVars();
    void initWindow();
public:
    // Constructor/Destructor
    Game(/* args */);
    ~Game();

    // Public Functions
    void update();
    void render();
    void pollEvents();

    // Accessors
    const bool running() const;

};


       