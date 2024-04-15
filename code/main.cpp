#include <iostream>
#include <sstream>
#include <string>
// #include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
// #include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
    // Window
    RenderWindow window(VideoMode(800, 600), "Testing");
    Event ev;

    // Game Loop
    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (ev.key.code == Keyboard::Escape)
                {
                    window.close();
                }
                if (ev.key.code == Keyboard::Up)
                    cout << "You have pressed the up key\n";
                break;
            }
        }
    }
}