#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

using namespace std;

//Описание базового класса Точка

 sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML");

class point
{
    protected:
        int x, y, color;
    
    public:
        point();
        point(int xx, int yy, int color);
        ~point(); 

        void draw(); 
        void hide();
        void move(int dxx, int dyy);
};

//Конструктор по умолчанию
point::point()
{
    x  = 500;
    y = 500;
    color = 1; 
}

//Конструктор с заданными x, y, color
point::point(int xx,int yy, int col)
{
    x  = xx;
    y = yy;
    color = col; 
}

// Деструктор - просто закрашивает точку чёрным
point::~point()
{
    x = 0;
    y = 0;
    color = 5;
}

// Функция вывода на экран 1-Красный, 2-Зелёный, 3-Синий, 4-Жёлтый, 5- Чёрный, Ост - белый.
void point::draw()
{
    switch(color)
    {
        case 1:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::Red);
            window.draw(&point, 5, sf::Points);
            break;
        }
        case 2:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::Green);
            window.draw(&point, 5, sf::Points);
            break;
        }
        case 3:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::Blue);
            window.draw(&point, 5, sf::Points);
            break;
        }
        case 4:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::Yellow);
            window.draw(&point, 5, sf::Points);
            break;
        }
        case 5:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::Black);
            window.draw(&point, 5, sf::Points);
            break;
        }
        default:
        {
            sf::Vertex point(sf::Vector2f(x,y), sf::Color::White);
            window.draw(&point, 5, sf::Points);
            break;
        }
    }
}

// Функция спрятать - меняет цвет на чёрный, лучше придумать что-то другое а =деструктор
void point::hide()
{
    color = 5;
}

// Функция Переместить - меняет коорд x,y.
void point::move(int dxx, int dyy)
{
    x+=dxx;
    y+=dyy;
}



//Описание класса Линия

class tline: public point
{
    protected:
        int dx, dy;

    public:
        tline();
        tline(int x1, int y1, int dxx, int dyy, int col);
        ~tline();

        void draw();
        void hide();
        void move(int dxx, int dyy);
        void rotate(double fi);
};

//Конструктор по умолчанию - красная линия в 400 пикс. посередине (горизонт)
tline::tline()
{
    x = 300;
    y = 500;
    dx = 400;
    dy = 0;
    color = 1;
}

// Конструктор с заданными параметрами
tline::tline(int x1, int y1, int dxx, int dyy, int col)
{
    x = x1;
    y = y1;
    dx = dxx;
    dy = dyy;
    color = col;
}

// Деструктор - делает черным, длина - 0, перемещ в угол
tline::~tline()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0; 
    color = 5;
}

// Функция вывода на экран
void tline::draw()
{
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(x,y);
    line[1].position = sf::Vector2f(x+dx,y+dy);

    switch(color)
    {
        case 1:
        {
            line[0].color = sf::Color::Red;
            line[1].color = sf::Color::Red;
            break;
        }
        case 2:
        {
            line[0].color = sf::Color::Green;
            line[1].color = sf::Color::Green;
            break;
        }
        case 3:
        {
            line[0].color = sf::Color::Blue;
            line[1].color = sf::Color::Blue;
            break;
        }
        case 4:
        {
            line[0].color = sf::Color::Yellow;
            line[1].color = sf::Color::Yellow;
            break;
        }
        case 5:
        {
            line[0].color = sf::Color::Black;
            line[1].color = sf::Color::Black;
            break;
        }
        default:
        {
            line[0].color = sf::Color::White;
            line[1].color = sf::Color::White;
            break;
        }
    }
    window.draw(line, 2, sf::Lines);
}

//Функция спрятать - меняет цвет на чёрный, лучше придумать что-то
void tline::hide()
{
    color = 5;
}

//Функция переместить, меняет коорд. первоначальной точки, соотв. смещает всю линию
void tline::move(int dxx, int dyy)
{
    x+=dxx;
    y+=dyy;
}

/*Функция Вращать - НЕ ПРИБАВЛЯЕТ УГОЛ ФИ!!!! - Меняет угол, на указанный
При этом точка начала и длина линии те же.(Начинается с 0 - справа,
движется по часовой стрелке по мере увеличения угла) Угол в градусах.*/
void tline::rotate(double fi)
{
    double PI = 3.14;
    double length = sqrt(dx*dx+dy*dy);
    dx=int(length*cos(fi*PI/180));
    dy=int(length*sin(fi*PI/180));
}

int main()
{
    point a1(200,300,1);
    point a2(700,300,2);
    point a3(300,700,3);
    point a4(700,700,4);
    a1.move(0,-200);
    a3.hide();
    
    tline l1 (400,500,200,0,3);
    tline l2 (300,400,200,200,2);
    tline l3 = tline();
    l2.rotate(45);
    l3.move(300,300);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }   

        window.clear();
        a1.draw();
        a2.draw();
        a3.draw();
        a4.draw();
        l1.draw();
        l2.draw();
        l3.draw();
        window.display();
    }

    return 0;
}
