#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <cmath> 
 
sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML"); 
 
class Shape 
{ 
protected: 
    int x, y, color; 
 
public: 
    Shape(); 
    Shape(int xx, int yy, int col); 
    virtual ~Shape(); 
 
    virtual void draw() = 0; 
    virtual void hide(); 
    virtual void move(int dxx, int dyy); 
}; 
 
Shape::Shape() 
{ 
    x = 500; 
    y = 500; 
    color = 1; 
} 
 
Shape::Shape(int xx, int yy, int col) 
{ 
    x = xx; 
    y = yy; 
    color = col; 
} 
 
Shape::~Shape() 
{ 
    x = 0; 
    y = 0; 
    color = 5; 
} 
 
void Shape::hide() 
{ 
    color = 5; 
} 
 
void Shape::move(int dxx, int dyy) 
{ 
    x += dxx; 
    y += dyy; 
} 
 
class Square : public Shape 
{ 
protected: 
    int side; 
 
public: 
    Square(); 
    Square(int xx, int yy, int s, int col); 
    ~Square(); 
 
    void draw(); 
}; 
 
Square::Square() 
{ 
    x = 300; 
    y = 500; 
    side = 100; 
    color = 1; 
} 
 
Square::Square(int xx, int yy, int s, int col) 
{ 
    x = xx; 
    y = yy; 
    side = s; 
    color = col; 
} 
 
Square::~Square() 
{ 
    x = 0; 
    y = 0; 
    side = 0; 
    color = 5; 
} 
 
void Square::draw() 
{ 
    sf::RectangleShape square(sf::Vector2f(side, side)); 
    square.setPosition(x, y); 
    switch (color) 
    { 
    case 1: 
        square.setFillColor(sf::Color::Red); 
        break; 
    case 2: 
        square.setFillColor(sf::Color::Green); 
        break; 
    case 3: 
        square.setFillColor(sf::Color::Blue); 
        break; 
    case 4: 
        square.setFillColor(sf::Color::Yellow); 
        break; 
    default: 
        square.setFillColor(sf::Color::Black); 
        break; 
    } 
    window.draw(square); 
} 
 
class Circle : public Shape 
{ 
protected: 
    int radius; 
 
public: 
    Circle(); 
    Circle(int xx, int yy, int r, int col); 
    ~Circle(); 
 
    void draw(); 
}; 
 
Circle::Circle() 
{ 
    x = 300; 
    y = 500; 
    radius = 50; 
    color = 1; 
} 
 
Circle::Circle(int xx, int yy, int r, int col) 
{ 
    x = xx; 
    y = yy; 
    radius = r; 
    color = col; 
} 
 
Circle::~Circle() 
{ 
    x = 0; 
    y = 0; 
    radius = 0; 
    color = 5; 
} 
 
void Circle::draw() 
{ 
    sf::CircleShape circle(radius); 
    circle.setPosition(x, y); 
    ///circle.setFillColor(sf::Color::Transparent); 
    switch (color) 
    { 
    case 1: 
        circle.setOutlineColor(sf::Color::Red); 
        break; 
    case 2: 
        circle.setOutlineColor(sf::Color::Green); 
        break; 
    case 3: 
        circle.setOutlineColor(sf::Color::Blue); 
        break; 
    case 4: 
        circle.setOutlineColor(sf::Color::Yellow); 
        break; 
    default: 
        circle.setOutlineColor(sf::Color::Black); 
        break; 
    } 
    window.draw(circle); 
} 
 
class Rectangle : public Shape 
{ 
protected: 
    int width, height; 
 
public: 
    Rectangle(); 
    Rectangle(int xx, int yy, int w, int h, int col); 
    ~Rectangle(); 
 
    void draw(); 
}; 
 
Rectangle::Rectangle() 
{ 
    x = 300; 
    y = 500; 
    width = 200; 
    height = 100; 
    color = 1; 
} 
 
Rectangle::Rectangle(int xx, int yy, int w, int h, int col) 
{ 
    x = xx; 
    y = yy; 
    width = w; 
    height = h; 
    color = col; 
} 
 
Rectangle::~Rectangle() 
{ 
    x = 0; 
    y = 0; 
    width = 0; 
    height = 0; 
    color = 5; 
} 
 
void Rectangle::draw() 
{ 
    sf::RectangleShape rectangle(sf::Vector2f(width, height)); 
    rectangle.setPosition(x, y); 
    switch (color) 
    { 
    case 1: 
        rectangle.setFillColor(sf::Color::Red); 
        break; 
    case 2: 
        rectangle.setFillColor(sf::Color::Green); 
        break; 
    case 3: 
        rectangle.setFillColor(sf::Color::Blue); 
        break; 
    case 4: 
        rectangle.setFillColor(sf::Color::Yellow); 
        break; 
    default: 
        rectangle.setFillColor(sf::Color::Black); 
        break; 
    } 
    window.draw(rectangle); 
} 
 
int main() 
{ 
    // Previous code remains the same 
 
    Square square(500, 300, 100, 3); 
    Circle circle(700, 700, 50, 1);
    Rectangle rectangle(200, 700, 150, 80, 2); 
 
    while (window.isOpen()) 
    { 
        sf::Event event; 
        while (window.pollEvent(event)) 
        { 
            if (event.type == sf::Event::Closed) 
                window.close(); 
        } 
 
        window.clear(); 
        // Previous shapes drawing remains the same 
        square.draw(); 
        circle.draw(); 
        rectangle.draw(); 
        window.display(); 
    } 
 
    return 0; 
}