#include<iostream>
using namespace std;

class vect
{
    int dim;
    double*v;
    int num;

    public:
    static int count;
    vect();
    vect(int d);
    vect(int d, double*x);
    vect(vect &x);
    ~vect();
    void print();
    
    vect &operator+(vect &r);
    friend vect operator-(vect l,vect r);
    vect &operator=(const vect &r);
};

int vect::count=0;

//Конструктор создания нулевого вектора
vect::vect(int d)
{
    count ++;
    num = count;
    cout<<"Конструктор vect(int) создал вектор N"<<num;
    dim = d;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
        v[i] = 0;
}

//Конструктор копирования вектора
vect::vect(vect &r)
{
    count ++;
    num = count;
    cout<<"Конструктор vect(vect) создал N"<<num;
    dim = r.dim;
    v = new double[dim];
    for (int i=0; i<dim; i++)
        v[i]=r.v[i];
}

vect &vect::operator=(vect &r)
{
    if (dim = 0)
    {
        dim = r.dim;
        v = new double[dim];
    }
    for (int i = 0; i < dim; i++)
    {
        v[i]=r.v[i];
    }
    return* this;
}

vect

int main()
{
    cout<<"HELLO WORLD";
}