#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML");

//----------------------------------------------------------
//----------Описание базового класса Точка------------------
//----------------------------------------------------------

//Переписываю базовый класс point в абстрактный класс grobject

class grobject
{
    protected:
        int x, y, color, visible;
        grobject();
        grobject(int xx,int yy);
        grobject(int xx, int yy, int c);
        ~grobject(); 
    
    public:
        virtual void draw() = 0; //чисто виртуальный метод draw - поэтому класс grobject абстрактный
        void hide();
        void reveal();
        void move(int dxx, int dyy);
};

//Конструктор по умолчанию
grobject::grobject()
{
    x  = 500;
    y = 500;
    color = 1;
    visible = 1; 
}

//Конструктор с заданными x, y
grobject::grobject(int xx,int yy)
{
    x  = xx;
    y = yy; 
}

//Конструктор с заданными x, y, color
grobject::grobject(int xx,int yy, int c)
{
    x  = xx;
    y = yy;
    color = c; 
    visible = 1;
}

// Деструктор - просто закрашивает точку чёрным
grobject::~grobject()
{
    x = 0;
    y = 0;
    color = 5;
}

// Функция спрятать - выключает видимость
void grobject::hide()
{
    visible = 0;
}

//Функция проявить - включает видимость
void grobject::reveal()
{
    visible = 1;
}

// Функция Переместить - меняет коорд x,y.
void grobject::move(int dxx, int dyy)
{
    x+=dxx;
    y+=dyy;
}



//----------------------------------------------------------
//-----Описание производного (от точки) класса Линия--------
//----------------------------------------------------------

class tline: public grobject
{
    protected:
        int dx, dy;

    public:
        tline();
        tline(int xx, int yy, int dxx, int dyy);
        tline(int xx, int yy, int dxx, int dyy, int c);
        ~tline();

        virtual void draw();
        void rotate(double fi);
};

//Конструктор по умолчанию 
tline::tline()
{
    x = 300;
    y = 500;
    dx = 400;
    dy = 0;
    color = 1;
    visible = 1;
}

// Конструктор с заданными параметрами
tline::tline(int x1, int y1, int dxx, int dyy)
{
    x = x1;
    y = y1;
    dx = dxx;
    dy = dyy;
    color = 1;
    visible = 1;
}

// Конструктор с заданными параметрами и цветом
tline::tline(int x1, int y1, int dxx, int dyy, int c)
{
    x = x1;
    y = y1;
    dx = dxx;
    dy = dyy;
    color = c;
    visible = 1;
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
    if (visible == 1)
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
}

/*Функция Вращать - НЕ ПРИБАВЛЯЕТ УГОЛ ФИ!!!! - Меняет угол, на указанный
При этом точка начала и длина линии те же.(Значения углов как на 
тригонометрической окружности). Угол в градусах.*/

// Переписал - теперь прибавляет угол - крутит вокруг x,y по часовой стрелке - угол в градусах.
void tline::rotate(double fi)
{
    double PI = 3.14;
    double length = sqrt(dx*dx+dy*dy);

    int xi = int(asin(dy/length)*180/PI);

    dx=int(length*cos((xi+fi)*PI/180));
    dy=int(length*sin((xi+fi)*PI/180));
}



//----------------------------------------------------------
//-----Описание производного (от линии) класса Квадрат------
//----------------------------------------------------------

class tsquare: public tline
{
    public:
        tsquare();
        tsquare(int xx, int yy, int dxx, int dyy);
        tsquare(int xx, int yy, int dxx, int dyy, int c);
        ~tsquare();

        virtual void draw();
};

//move и hide - не переопределяется, наследуются у class tline (которые насл. у point).

tsquare::tsquare()
{
    x = 200;
    y = 200;
    dx = 100;
    dy = 0;
    color = 1;
    visible = 1;
}

tsquare::tsquare(int xx, int yy, int dxx, int dyy)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    color = 1;
    visible = 1;
}

tsquare::tsquare(int xx, int yy, int dxx, int dyy, int c)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    color = c;
    visible = 1;
}

tsquare::~tsquare()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0; 
    color = 5;
    visible = 0;
}

void tsquare::draw()
{
    if (visible == 1)
    {
        sf::VertexArray lines(sf::LineStrip,5);
        lines[0].position = sf::Vector2f(x,y);
        lines[1].position = sf::Vector2f(x+dx,y+dy);
        lines[2].position = sf::Vector2f(x+dx-dy,y+dy+dx);
        lines[3].position = sf::Vector2f(x-dy,y+dx);
        lines[4].position = sf::Vector2f(x,y);


        switch(color)
        {
            case 1:
            {
                lines[0].color = sf::Color::Red;
                lines[1].color = sf::Color::Red;
                lines[2].color = sf::Color::Red;
                lines[3].color = sf::Color::Red;
                lines[4].color = sf::Color::Red;
                break;
            }
            case 2:
            {
                lines[0].color = sf::Color::Green;
                lines[1].color = sf::Color::Green;
                lines[2].color = sf::Color::Green;
                lines[3].color = sf::Color::Green;
                lines[4].color = sf::Color::Green;
                break;
            }
            case 3:
            {
                lines[0].color = sf::Color::Blue;
                lines[1].color = sf::Color::Blue;
                lines[2].color = sf::Color::Blue;
                lines[3].color = sf::Color::Blue;
                lines[4].color = sf::Color::Blue;
                break;
            }
            case 4:
            {
                lines[0].color = sf::Color::Yellow;
                lines[1].color = sf::Color::Yellow;
                lines[2].color = sf::Color::Yellow;
                lines[3].color = sf::Color::Yellow;
                lines[4].color = sf::Color::Yellow;
                break;
            }
            case 5:
            {
                lines[0].color = sf::Color::Black;
                lines[1].color = sf::Color::Black;
                lines[2].color = sf::Color::Black;
                lines[3].color = sf::Color::Black;
                lines[4].color = sf::Color::Black;
                break;
            }
            default:
            {
                lines[0].color = sf::Color::White;
                lines[1].color = sf::Color::White;
                lines[2].color = sf::Color::White;
                lines[3].color = sf::Color::White;
                lines[4].color = sf::Color::White;
                break;
            }
        }
        window.draw(lines);
    }
}

/*Функция поворота тоже унаследована от tline - первая
точка неизменна, меняется угол линии (x,y;x+dx,y+dy)*/



//----------------------------------------------------------
//-Описание производного (от квадрата) класса прямоугольник-
//----------------------------------------------------------

class trekt: virtual public tsquare
{
    protected:
    float ak, bk; //Коэфы увел. сторон - 1 - без изм.

    public:
        trekt();
        trekt(int xx, int yy, int dxx, int dyy, float akk, float bkk);
        trekt(int xx, int yy, int dxx, int dyy, float akk, float bkk, int c);
        ~trekt();

        void draw();
};


trekt::trekt()
{
    x = 200;
    y = 700;
    dx = 100;
    dy = 0;
    ak = 2;
    bk = 1;
    color = 1;
    visible = 1;
}

trekt::trekt(int xx, int yy, int dxx, int dyy, float akk, float bkk)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    ak = akk;
    bk = bkk;
    color = 1;
    visible = 1;
}

trekt::trekt(int xx, int yy, int dxx, int dyy, float akk, float bkk, int c)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    ak = akk;
    bk = bkk;
    color = c;
    visible = 1;
}

trekt::~trekt()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    ak = 0;
    bk = 0;
    color = 5;
    visible = 0;
}

void trekt::draw()
{
    if (visible == 1)
    {
        sf::VertexArray lines(sf::LineStrip,5);
        lines[0].position = sf::Vector2f(x,y);
        lines[1].position = sf::Vector2f(x+ak*dx,y+ak*dy);
        lines[2].position = sf::Vector2f(x+ak*dx-bk*dy,y+ak*dy+bk*dx);
        lines[3].position = sf::Vector2f(x-bk*dy,y+bk*dx);
        lines[4].position = sf::Vector2f(x,y);


        switch(color)
        {
            case 1:
            {
                lines[0].color = sf::Color::Red;
                lines[1].color = sf::Color::Red;
                lines[2].color = sf::Color::Red;
                lines[3].color = sf::Color::Red;
                lines[4].color = sf::Color::Red;
                break;
            }
            case 2:
            {
                lines[0].color = sf::Color::Green;
                lines[1].color = sf::Color::Green;
                lines[2].color = sf::Color::Green;
                lines[3].color = sf::Color::Green;
                lines[4].color = sf::Color::Green;
                break;
            }
            case 3:
            {
                lines[0].color = sf::Color::Blue;
                lines[1].color = sf::Color::Blue;
                lines[2].color = sf::Color::Blue;
                lines[3].color = sf::Color::Blue;
                lines[4].color = sf::Color::Blue;
                break;
            }
            case 4:
            {
                lines[0].color = sf::Color::Yellow;
                lines[1].color = sf::Color::Yellow;
                lines[2].color = sf::Color::Yellow;
                lines[3].color = sf::Color::Yellow;
                lines[4].color = sf::Color::Yellow;
                break;
            }
            case 5:
            {
                lines[0].color = sf::Color::Black;
                lines[1].color = sf::Color::Black;
                lines[2].color = sf::Color::Black;
                lines[3].color = sf::Color::Black;
                lines[4].color = sf::Color::Black;
                break;
            }
            default:
            {
                lines[0].color = sf::Color::White;
                lines[1].color = sf::Color::White;
                lines[2].color = sf::Color::White;
                lines[3].color = sf::Color::White;
                lines[4].color = sf::Color::White;
                break;
            }
        }
        window.draw(lines);
    }
}



//----------------------------------------------------------
//-----Описание производного (от квадрата) класса ромб------
//----------------------------------------------------------

class tromb: virtual public tsquare
{
    protected:
    int fi; //значение угла между в вершине x+dx,y+dy в градусах (0;180)

    public:
        tromb();
        tromb(int xx, int yy, int dxx, int dyy, int fik);
        tromb(int xx, int yy, int dxx, int dyy, int fik, int c);
        ~tromb();

        virtual void draw();
};

tromb::tromb()
{
    x = 100;
    y = 500;
    dx = 100;
    dy = 100;
    fi = 120;
    color = 1;
    visible = 1;
}

tromb::tromb(int xx, int yy, int dxx, int dyy, int fik)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    fi = fik;
    color = 1;
    visible = 1;
}

tromb::tromb(int xx, int yy, int dxx, int dyy, int fik, int c)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    fi = fik;
    color = c;
    visible = 1;
}

tromb::~tromb()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    fi = 0;
    color = 5;
    visible = 0;
}


//Надо править - пока рисует какую-то несуразицу.
//Исправил - вроде работает но надо тесты сделать
//Потестил, рисует фигуры верные, но угол неверно считывает


void tromb::draw()
{
    if (visible == 1)
    {

        double length = sqrt(dx*dx+dy*dy);
        double PI = 3.14;

        int xi = int(asin(dy/length)*180/PI);

        int dxx = int((length*cos((xi+180-fi)*PI/180)));//можно поиграться с модулем
        int dyy = int((length*sin((xi+180-fi)*PI/180))+1);

        sf::VertexArray lines(sf::LineStrip,5);
        lines[0].position = sf::Vector2f(x,y);
        lines[1].position = sf::Vector2f(x+dx,y+dy);
        lines[2].position = sf::Vector2f(x+dx+dxx,y+dy+dyy);
        lines[3].position = sf::Vector2f(x+dxx,y+dyy);
        lines[4].position = sf::Vector2f(x,y);


        switch(color)
        {
            case 1:
            {
                lines[0].color = sf::Color::Red;
                lines[1].color = sf::Color::Red;
                lines[2].color = sf::Color::Red;
                lines[3].color = sf::Color::Red;
                lines[4].color = sf::Color::Red;
                break;
            }
            case 2:
            {
                lines[0].color = sf::Color::Green;
                lines[1].color = sf::Color::Green;
                lines[2].color = sf::Color::Green;
                lines[3].color = sf::Color::Green;
                lines[4].color = sf::Color::Green;
                break;
            }
            case 3:
            {
                lines[0].color = sf::Color::Blue;
                lines[1].color = sf::Color::Blue;
                lines[2].color = sf::Color::Blue;
                lines[3].color = sf::Color::Blue;
                lines[4].color = sf::Color::Blue;
                break;
            }
            case 4:
            {
                lines[0].color = sf::Color::Yellow;
                lines[1].color = sf::Color::Yellow;
                lines[2].color = sf::Color::Yellow;
                lines[3].color = sf::Color::Yellow;
                lines[4].color = sf::Color::Yellow;
                break;
            }
            case 5:
            {
                lines[0].color = sf::Color::Black;
                lines[1].color = sf::Color::Black;
                lines[2].color = sf::Color::Black;
                lines[3].color = sf::Color::Black;
                lines[4].color = sf::Color::Black;
                break;
            }
            default:
            {
                lines[0].color = sf::Color::White;
                lines[1].color = sf::Color::White;
                lines[2].color = sf::Color::White;
                lines[3].color = sf::Color::White;
                lines[4].color = sf::Color::White;
                break;
            }
        }
        window.draw(lines);
    }
}



//----------------------------------------------------------
//---Производный (от ромба и прямоуг) класс параллелограмм--
//----------------------------------------------------------

class tpar: public tromb, public trekt
{
 public:
        tpar();
        tpar(int xx, int yy, int dxx, int dyy, float akk, float bkk, int fik);
        tpar(int xx, int yy, int dxx, int dyy, float akk, float bkk, int fik, int c);
        ~tpar();

        virtual void draw();
};

tpar::tpar()
{
    x = 600;
    y = 300;
    dx = 100;
    dy = 200;
    ak = 1;
    bk = 2;
    fi = 110;
    color = 1;
    visible = 1;
}

tpar::tpar(int xx, int yy, int dxx, int dyy, float akk, float bkk, int fik)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    ak = akk;
    bk = bkk;
    fi = fik;
    color = 1;
    visible = 1;
}

tpar::tpar(int xx, int yy, int dxx, int dyy, float akk, float bkk, int fik, int c)
{
    x = xx;
    y = yy;
    dx = dxx;
    dy = dyy;
    ak = akk;
    bk = bkk;
    fi = fik;
    color = c;
    visible = 1;
}

tpar::~tpar()
{
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    ak = 0;
    bk = 0;
    fi = 0;
    color = 5;
    visible = 0;
}

void tpar::draw()
{
    if (visible == 1)
    {
        double length = sqrt(dx*dx+dy*dy);
        double PI = 3.14;

        int xi = int(asin(dy/length)*180/PI);

        int dxx = int((length*cos((xi+180-fi)*PI/180)));//можно поиграться с модулем
        int dyy = int((length*sin((xi+180-fi)*PI/180))+1);

        sf::VertexArray lines(sf::LineStrip,5);
        lines[0].position = sf::Vector2f(x,y);
        lines[1].position = sf::Vector2f(x+ak*dx,y+ak*dy);
        lines[2].position = sf::Vector2f(x+ak*dx+bk*dxx,y+ak*dy+bk*dyy);
        lines[3].position = sf::Vector2f(x+bk*dxx,y+bk*dyy);
        lines[4].position = sf::Vector2f(x,y);


        switch(color)
        {
            case 1:
            {
                lines[0].color = sf::Color::Red;
                lines[1].color = sf::Color::Red;
                lines[2].color = sf::Color::Red;
                lines[3].color = sf::Color::Red;
                lines[4].color = sf::Color::Red;
                break;
            }
            case 2:
            {
                lines[0].color = sf::Color::Green;
                lines[1].color = sf::Color::Green;
                lines[2].color = sf::Color::Green;
                lines[3].color = sf::Color::Green;
                lines[4].color = sf::Color::Green;
                break;
            }
            case 3:
            {
                lines[0].color = sf::Color::Blue;
                lines[1].color = sf::Color::Blue;
                lines[2].color = sf::Color::Blue;
                lines[3].color = sf::Color::Blue;
                lines[4].color = sf::Color::Blue;
                break;
            }
            case 4:
            {
                lines[0].color = sf::Color::Yellow;
                lines[1].color = sf::Color::Yellow;
                lines[2].color = sf::Color::Yellow;
                lines[3].color = sf::Color::Yellow;
                lines[4].color = sf::Color::Yellow;
                break;
            }
            case 5:
            {
                lines[0].color = sf::Color::Black;
                lines[1].color = sf::Color::Black;
                lines[2].color = sf::Color::Black;
                lines[3].color = sf::Color::Black;
                lines[4].color = sf::Color::Black;
                break;
            }
            default:
            {
                lines[0].color = sf::Color::White;
                lines[1].color = sf::Color::White;
                lines[2].color = sf::Color::White;
                lines[3].color = sf::Color::White;
                lines[4].color = sf::Color::White;
                break;
            }
        }
        window.draw(lines);
    }
}

//----------------------------------------------------------
//-----------------------Функция MAIN-----------------------
//----------------------------------------------------------

int main()
{
    
 
    tline l1(300,500,200,0,3);
    tline l2(300,400,200,200,2);
    tline l3 = tline();
    l2.rotate(0);
    l3.move(300,300);

    //Сетка
    tline l4 = tline(0,200,1000,0,8);
    tline l5 = tline(200,0,0,1000,8);
    tline l6 = tline(0,400,1000,0,8);
    tline l7 = tline(400,0,0,1000,8);
    tline l8 = tline(0,600,1000,0,8);
    tline l9 = tline(600,0,0,1000,8);
    tline l10 = tline(0,800,1000,0,8); 
    tline l11 = tline(800,0,0,1000,8);
    l2.rotate(0);
    l3.move(300,300);

    tsquare s1(600,600,100,100);
    tsquare s2(600,200,100,100,2);
    tsquare s3 = tsquare();
    s1.hide();
    s2.move(200,500);
    s3.rotate(60);
    s3.move(400,550);

    trekt rk1 = trekt();
    trekt rk2(100,100,100,100,2,1);
    trekt rk3(800,100,200,0,0.5,2,4);
    rk2.hide();
    rk3.move(-50,410);
    rk3.rotate(60);

// с ромбом и пг надо тестить и думать (конкретно с углами)
// Потестил подумал и сделал, теперь работает
    tromb rm1 = tromb();
    tromb rm2(300,500,300,100,120);
    tromb rm3(300,100,200,100,150,3);
    rm1.hide();
    rm2.move(-260,-50);
    rm2.rotate(-48);
    
    tpar p1 = tpar();
    tpar p2(200,100,200,100,3,1,60);
    tpar p3(700,100,100,200,1,2,150,4);
    p1.hide();
    p2.move(0,-100);
    p3.move(100,0);
    p3.rotate(-3);

    //Описание примера, демонстрирующего позднее связывание
    tsquare *fig1;
    fig1 = new tromb();

    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }   

        window.clear();

        //Сетка
        l4.draw();
        l5.draw();
        l6.draw();
        l7.draw();
        l8.draw();
        l9.draw();
        l10.draw();
        l11.draw();

        s1.draw();
        s2.draw();
        s3.draw();

        rk1.draw();
        rk2.draw();
        rk3.draw();

        rm1.draw();
        rm2.draw();
        rm3.draw();

        p1.draw();
        p2.draw();
        p3.draw();

        //Отрисовка примера демонстр. позднее связывание
        fig1->draw();

        //На рисунке отрисовывается третий ромб, значит, несмотря на то, что fig1 - указатель на экземмпляр
        //класса квадрат, на этапе позднего связывания программа понимает, что в динамической памяти находятся
        //данные ромба и применяет соответствующий draw - из производного класса ромба

        window.display();
    }
    return 0;
}