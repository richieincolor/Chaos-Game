#include "Game.h"

// PRIVATE FUNCTIONS
void Game::initVars()
{
   this->window = nullptr; 
}

void Game::initWindow()
{
    this->vm.width = 800;
    this->vm.height = 600;
    this-> window = new RenderWindow(this->vm, "Testing");
}

// CONSTRUCTOR / DESTRUCTOR
Game::Game()
{
    this->initVars();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}


// FUNCTIONS
void Game::update()
{
    this->pollEvents();

    cout << "Mouse pos: " << Mouse::getPosition();
}

void Game::render(){
    this->window->clear(Color::Cyan);
    this->window->display();
}

void Game::pollEvents()
{
        while(this->window->pollEvent(this->ev))
        {
            switch (this->ev.type)
            {
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if (this->ev.key.code == Keyboard::Escape)
                {
                    this->window->close();
                }
                if (this->ev.key.code == Keyboard::Up)
                    cout << "You have pressed the up key\n";
                break;
            }
        }
}

// ACCESSORS
const bool Game::running() const
{
    return this->window->isOpen();
}
