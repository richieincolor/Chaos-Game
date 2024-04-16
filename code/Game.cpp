#include "Game.h"

// PRIVATE FUNCTIONS
void Game::initVars()
{
    this->window = nullptr;
    srand(time(nullptr));
    //this->testcircle.getFillColor(Color::Black);
}

void Game::initWindow()
{
    this->vm.width = 800;
    this->vm.height = 600;
    //this->vm.getFullscreenModes();
    this->window = new RenderWindow(this->vm, "Testing");
    this->window->setFramerateLimit(400);
}

void Game::addDot()
{
    //Vector2i pos = Mouse::getPosition();
    Vector2i pos;
    pos.x = this->ev.mouseButton.x;
    pos.y = this->ev.mouseButton.y;
    this->dots.push_back(pos);
    CircleShape temp = CircleShape(2, 30);
    temp.setPosition(pos.x, pos.y);
    temp.setFillColor(Color::Black);
    circles.push_back(temp);
}

void Game::addDot(Vector2i pos)
{
    this->dots.push_back(pos);
    CircleShape temp = CircleShape(2,30);
    temp.setPosition(pos.x, pos.y);
    temp.setFillColor(Color::Black);
    circles.push_back(temp);
}

void Game::printDots(){
    for(Vector2i i : this->dots){
        cout << i.x << ", " << i.y << endl;
    }
}

void Game::autoPopulate()
{
    if(this->dots.size()>=3 && this->dots.size()<1000000){
        int r = this->getRand();
        Vector2i rando = this->dots[r];
        Vector2i last = this->dots.back();
        Vector2i temp;
        temp.x = (last.x + rando.x)/2;
        temp.y = (last.y + rando.y)/2;
        this->addDot(temp);
    }
}

void Game::initCircles()
{
    //CircleShape* c = new CircleShape;
}

int Game::getRand()
{
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
    
    for(CircleShape c : this->circles){
        this->window->draw(c);
    }
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
    this->autoPopulate();
}

// ACCESSORS
bool Game::running() const
{
    return this->window->isOpen();
}
