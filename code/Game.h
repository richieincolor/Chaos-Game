#pragma once

// Libraries
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

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
    void addDot();
    void addDot(Vector2i pos);

    void printDots();
    void autoPopulate();

    int getRand();

    // Points
    vector<Vector2i> dots;


public:
    // Constructor/Destructor
    Game();
    ~Game();

    // Public Functions
    void update();
    void render();
    void pollEvents();

    // Accessors
    bool running() const;

};


       