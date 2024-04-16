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
    this->window = new RenderWindow(this->vm, "Testing");
}

void Game::addDot()
{
    this->dots.push_back(Mouse::getPosition());
}

void Game::addDot(Vector2i pos)
{
    this->dots.push_back(pos);
}

void Game::printDots(){
    for(Vector2i i : this->dots){
        cout << i.x << ", " << i.y << endl;
    }
}

void Game::autoPopulate()
{
    if(this->dots.size()>=3){
        int r = this->getRand();

    }
}

int Game::getRand()
{
    srand(time(nullptr));
    return rand()%3;
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
}

void Game::render()
{
    this->window->clear(Color::Cyan);
    this->window->display();
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
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
                this->printDots();
            break;
        case Event::MouseButtonPressed:
            if(this->dots.size()<3){
            this->addDot();
            }
            break;
        }
    }
}

// ACCESSORS
bool Game::running() const
{
    return this->window->isOpen();
}
