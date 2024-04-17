#include "Game.h"

// PRIVATE FUNCTIONS
void Game::initVars()
{
    srand(time(nullptr));
    
    this->window = nullptr;
    this->font = new Font;

    this->initFont();

    this->msg1 = nullptr;
    this->msg2 = nullptr;
    this->msg3 = nullptr;
    this->msg4 = nullptr;
    this->msg5 = nullptr;

    this->msg1 = new Text;
    this->msg2 = new Text;
    this->msg3 = new Text;
    this->msg4 = new Text;
    this->msg5 = new Text;

    this->msg1->setFont(*this->font);
    this->msg1->setCharacterSize(28);
    this->msg1->setFillColor(Color::White);
    this->msg1->setPosition(800, 50);
    this->msg1->setString("Hi. Try Clicking Anywhere.");

    this->msg2->setFont(*this->font);
    this->msg2->setCharacterSize(28);
    this->msg2->setFillColor(Color::White);
    this->msg2->setPosition(810, 50);
    this->msg2->setString("Click somewhere else.");

    this->msg3->setFont(*this->font);
    this->msg3->setCharacterSize(28);
    this->msg3->setFillColor(Color::White);
    this->msg3->setPosition(770, 50);
    this->msg3->setString("Excellent. How about a third click.");

    this->msg4->setFont(*this->font);
    this->msg4->setCharacterSize(28);
    this->msg4->setFillColor(Color::White);
    this->msg4->setPosition(600, 50);
    this->msg4->setString("I know I've asked a lot of you, but I think you've got one more click in you.");

    this->msg5->setFont(*this->font);
    this->msg5->setCharacterSize(28);
    this->msg5->setFillColor(Color::White);
    this->msg5->setPosition(900, 50);
    this->msg5->setString("look at them go");


        
}

void Game::initFont()
{
    if(!this->font->loadFromFile("fonts/InfoStory.ttf")){
        cout << "Error: Font not loaded.\n";
    }
}

void Game::initWindow()
{
    this->vm.width = 1920;
    this->vm.height = 1080;
    this->window = new RenderWindow(this->vm, "Testing");
    this->window->setFramerateLimit(400);
}

void Game::addDot()
{
    Vector2i pos;
    pos.x = this->ev.mouseButton.x;
    pos.y = this->ev.mouseButton.y;
    this->dots.push_back(pos);
    CircleShape temp = CircleShape(2, 30);
    temp.setPosition(pos.x, pos.y);
    temp.setFillColor(Color::White);
    circles.push_back(temp);
}

void Game::addDot(Vector2i pos)
{
    this->dots.push_back(pos);
    CircleShape temp = CircleShape(2,30);
    temp.setPosition(pos.x, pos.y);
    temp.setFillColor(Color(rand256(),rand256(),rand256()));
    circles.push_back(temp);
}

void Game::printDots(){
    for(Vector2i i : this->dots){
        cout << i.x << ", " << i.y << endl;
    }
}

void Game::autoPopulate()
{
    if(this->dots.size()>=4 && this->dots.size()<10000){
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
}

int Game::getRand()
{
    return rand()%3;
}

int Game::rand256(){
    return rand()%256;
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
    delete this->font;
    delete this->msg1;
    delete this->msg2;
    delete this->msg3;
    delete this->msg4;
    delete this->msg5;
}

// FUNCTIONS
void Game::update()
{
    this->pollEvents();
}

void Game::render()
{   
    // CLEAR
    this->window->clear(Color::Black);
    
    // DRAW
    drawCircles();
    drawText();

    // DISPLAY
    this->window->display();
}

void Game::drawText()
{
    if (this->dots.size() == 0)
    {
        this->window->draw(*this->msg1);
    }
    if (this->dots.size() == 1)
    {
        this->window->draw(*this->msg2);
    }
    if (this->dots.size() == 2)
    {
        this->window->draw(*this->msg3);
    }
    if (this->dots.size() == 3)
    {
        this->window->draw(*this->msg4);
    }
    if (this->dots.size() > 600 && this->dots.size() < 850)
    {
        this->window->draw(*this->msg5);
    }
}

void Game::drawCircles()
{
    for(CircleShape c : this->circles){
        this->window->draw(c);
    }
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
                // this->printDots();
            break;
        case Event::MouseButtonPressed:
            if(this->dots.size()<4){
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
