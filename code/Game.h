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


    Font* font;
    Text *msg1, *msg2, *msg3, *msg4, *msg5;

    // Private Functions
    void initVars();
    void initFont();
    void initWindow();
    void addDot();
    void addDot(Vector2i pos);

    void printDots();
    void autoPopulate();
    void initCircles();


    int getRand();

    // Points
    vector<Vector2i> dots;

    // Objects 
    vector<CircleShape> circles;

    CircleShape testcircle;


public:
    // Constructor/Destructor
    Game();
    ~Game();

    // Public Functions
    void update();
    void render();
    void drawText();
    void drawCircles();
    void pollEvents();

    // Accessors
    bool running() const;

};


       