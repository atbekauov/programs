#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

//--------------------------------------------------------------------------------------------------
//--------------------------------ОПИСАНИЕ КЛАССА ВЕКТОРОВ------------------------------------------
//--------------------------------------------------------------------------------------------------

class vect
{
    int dim;
    double*v;

    public: 
    int num;
    static int count;
    
    vect();
    vect(vect&x);
    vect(int n);
    vect(int n, double*x);
    ~vect();
    void print();

    vect operator+(vect r);
    friend vect operator-(vect&l,vect&r);
    vect operator-();
    vect operator=(const vect&r);
    double operator*(vect&r);
    friend vect operator*(double k, vect&r);
    friend class matr;
};

int vect::count=0;

//--------------------------------------------------------------------------------------------------
//--------------------------------ОПИСАНИЕ КЛАССА МАТРИЦ--------------------------------------------
//--------------------------------------------------------------------------------------------------

class matr
{
    int dim;  
    double**v;

    public:
    int num;
    static int count;
    
    matr();
    matr(matr&x);
    matr(int n);
    matr(int n, double**x);
    ~matr();
    void print();

    matr operator+(matr r);
    matr operator-(matr&r);
    matr operator-();
    matr operator=(const matr r);
    matr operator*(matr&r);
    friend matr operator*(double k, matr&r);
    vect operator*(vect&r);
};

int matr::count=0;
//--------------------------------------------------------------------------------------------------
//--------------------------------ОПИСАНИЕ КОНСТРУКТОРОВ И МЕТОДОВ ВЕКТОРОВ-------------------------
//--------------------------------------------------------------------------------------------------

//Конструктор вектора по умолчанию
vect::vect()
{
    count ++;
    num = count;
    dim = 3;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i]=1;
    }
    cout<<"Конструктор vect(), создал вектор №"<<num<<endl;
}

//Конструктор копирования вектора
vect::vect(vect &r)
{
    count ++;
    num = count;
    cout<<"Конструктор vect(vect) создал вектор №"<<num<<endl;
    dim = r.dim;
    v = new double[dim];
    for (int i=0; i<dim; i++)
        v[i]=r.v[i];
}


//Конструктор создания нулевого вектора
vect::vect(int n)
{
    count ++;
    num = count;
    cout<<"Конструктор vect(int) создал вектор №"<<num<<endl;
    dim = n;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
        v[i] = 0;
}

//Конструктор создания вектора с компонентами;
vect::vect(int n, double*x)
{
    count ++;
    num = count;
    cout<<"Конструктор vect(int, double) создал вектор №"<<num<<endl;
    dim = n;
    v = new double[dim];
    for (int i = 0; i < dim; i++)
        v[i] = x[i];
}

//Деструктор вектора
vect::~vect()
{
    cout<<"Деструктор ~vect() ликвидировал вектор №"<<num<<endl;
    delete v;
    dim = 0;
}

// Вывод вектора
void vect::print()
{
    cout<<"Вектор №"<<num<<" размерностью "<<dim<<" имеет значения:"<<endl;
    for (int i = 0; i < dim; i++)
    {
        cout<<"dim "<<i+1<<" = "<<v[i]<<endl;
    }
    cout<<endl;
}

// Функция сложения векторов
vect vect::operator+(vect r)
{
    cout<<"Создан вектор со значением = v"<<num<<" + v"<<r.num<<endl;
    vect tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        tmp.v[i]=v[i]+r.v[i];
    }
    return tmp;
}

// Функция вычитания векторов бинарная 
vect operator-(vect&l, vect&r)
{
    cout<<"Создан вектор со значением = v"<<l.num<<" - v"<<r.num<<endl;
    vect tmp(l);
    for (int i = 0; i < tmp.dim; i++)
    {
        tmp.v[i]=l.v[i]-r.v[i];
    }
    return tmp;
}

//Функция вычитания векторов унарная
vect vect::operator-()
{
    cout<<"Создан вектор со значением = -v"<<num<<endl;
    vect tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        tmp.v[i]=-1*v[i];
    }
    return tmp;
}

// Функция присвоения вектору значения другого вектора 
vect vect::operator=(const vect&r)
{
    cout<<"Вектору v"<<num<<" присвоено значение вектора v"<<r.num<<endl;
    dim = r.dim;
    for (int i = 0; i < dim; i++)
    {
        v[i]=r.v[i];
    }
    return *this;
}

// Функция скалярного умножения векторов;
double vect::operator*(vect&r)
{
    cout<<"Создана переменная со скалярным значением = v"<<num<<" * v"<<r.num<<endl;
    double tmp = 0;
    for (int i = 0; i < dim; i++)
    {
        tmp+=v[i]*r.v[i];
    }
    return tmp;
}

// Функция умножения вектора на число
vect operator*(double k, vect&r)
{
    cout<<"Создан вектор со значением = "<<k<<" * v"<<r.num<<endl;
    vect tmp(r);
    for (int i = 0; i < tmp.dim; i++)
    {
        tmp.v[i]=r.v[i]*k;
    }
    return tmp;
}
//--------------------------------------------------------------------------------------------------
//--------------------------------ОПИСАНИЕ КОНСТРУКТОРОВ И МЕТОДОВ МАТРИЦ---------------------------
//--------------------------------------------------------------------------------------------------
//Конструктор матрицы по умолчанию (единичной) --- Работает только в форме matr m1 = matr(); - так и должно быть - написано в Павловской.
matr::matr()
{
    count ++;
    num = count;
    dim = 3;
    v = new double*[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = new double [dim];
        for (int j = 0; j < dim; j++)
        {
            if (i==j)
            {
                v[i][j]=1;
            }
            else
            {
                v[i][j]=0;
            }
        }
 
    }
    //cout<<"Конструктор matr(), создал матрицу №"<<num<<endl;
}

//Конструктор копирования матрицы
matr::matr(matr &r)
{
    count ++;
    num = count;
    //cout<<"Конструктор matr(matr) создал матрицу №"<<num<<endl;
    dim = r.dim;
    v = new double*[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = new double [dim];
        for (int j = 0; j < dim; j++)
        {
            v[i][j]=r.v[i][j];
        }
    }
}


//Конструктор создания нулевой матрицы, размера n.
matr::matr(int n)
{
    count ++;
    num = count;
    //cout<<"Конструктор matr(int) создал матрицу №"<<num<<endl;
    dim = n;
    v = new double*[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = new double [dim];
        for (int j = 0; j < dim; j++)
        {
            v[i][j]=0;
        }
    }
}

//Конструктор создания матрицы с компонентами x;
matr::matr(int n, double**x)
{
    count ++;
    num = count;
    //cout<<"Конструктор matr(int, double) создал матрицу №"<<num<<endl;
    dim = n;
    v = new double*[dim];
    for (int i = 0; i < dim; i++)
    {
        v[i] = new double [dim];
        for (int j = 0; j < dim; j++)
        {
            v[i][j]=x[i][j];
        }
    }
}

//Деструктор матрицы 
matr::~matr()
{
    //cout<<"Деструктор ~matr() ликвидировал матрицу №"<<num<<endl;
    for (int i = 0; i < dim; i++)
    {
        delete [] v[i];
    }
}

// Вывод матрицы
void matr::print()
{
    cout<<"Матрица №"<<num<<" размерностью "<<dim<<'x'<<dim<<" имеет значения:"<<endl; //тут хорошо бы обратиться по имени -- неактуально
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout<<setw(4)<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// Функция сложения матриц
matr matr::operator+(matr r)
{
    matr tmp(dim);
     for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp.v[i][j]=v[i][j]+r.v[i][j];
        }
    }
    return tmp;
}

// Функция вычитания матриц бинарная
matr matr::operator-(matr&r)
{
    matr tmp(dim);
     for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp.v[i][j]=v[i][j]-r.v[i][j];
        }
    }
    return tmp;
}

//Функция вычитания матриц унарная
matr matr::operator-()
{
    matr tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp.v[i][j]=-v[i][j];
        }
    }
    return tmp;
}

// Функция присвоения матрице значения другой матрицы
matr matr::operator=(const matr r)
{
    dim = r.dim;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            v[i][j]=r.v[i][j];
        }
    }
    return *this;
}


// Функция перемножения матриц;
 matr matr::operator*(matr&r)
{
    matr tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            for (int k = 0; k < dim; k++)
            {
                tmp.v[i][j]+=v[i][k]*r.v[k][j]; 
            }
        }
    }
    return tmp;
}

// Функция умножения матрицы на число
matr operator*(double k, matr&r)
{
    matr tmp(r.dim);
    for (int i = 0; i < tmp.dim; i++)
    {
        for (int j = 0; j < tmp.dim; j++)
        {
            tmp.v[i][j]=r.v[i][j]*k;
        }
    }
    return tmp;
}

// Функция умножения матрицы на вектор-столбец
vect matr::operator*(vect&r)
{
    vect tmp(dim);
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            tmp.v[i]+=v[i][j]*r.v[i];
        }
    }
    return tmp;
}

//--------------------------------------------------------------------------------------------------
//------------------------------------------ФУНКЦИЯ MAIN--------------------------------------------
//--------------------------------------------------------------------------------------------------
int main()
{
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"Демонстрация всех конструкторов, методов и функций векторов:"<<endl;
    cout<<"------------------------------------------------------------"<<endl;

    cout<<"Работа конструктора вектора по умолчанию (единичного) vect():"<<endl;;
    vect v1 = vect();
    v1.print();
    
    cout<<"Работа конструктора копирования вектора vect(vect):"<<endl;
    vect v2(v1);
    v2.print();

    cout<<"Работа конструктора создания нулевого вектора vect(int):"<<endl;
    vect v3(4);
    v3.print();

    cout<<"Работа конструктора создания вектора c заданными параметрами vect(int,double):"<<endl;
    double a[] = {4,2,3};
    vect v4(3,a);
    v4.print();

    cout<<"Работа функции сложения векторов:"<<endl;
    cout<<"v6 = v1(1,1,1) + v1(1,1,1)"<<endl;
    vect v6 = v1+v2;
    v6.print(); 

    cout<<"Работа функции бинарного вычитания векторов:"<<endl;
    cout<<"v7 = v4(4,2,3) - v1(1,1,1)"<<endl;
    vect v7 = v4-v1;
    v7.print();

    cout<<"Работа функции унарного вычитания вектора:"<<endl;
    cout<<"v8 = -v1(1,1,1)"<<endl;
    vect v8 = -v1;
    v8.print();

    cout<<"Работа функции присвоения вектора:"<<endl;
    cout<<"v9 = v1(1,1,1)"<<endl;
    vect v9 = v1;
    v9.print();

    cout<<"Работа функции скалярного перемножения векторов:"<<endl;
    double ans = v4*v7;
    cout<<"ans = v4(4,2,3) * v7(3,1,2) = "<<ans<<endl;
    cout<<endl;

    cout<<"Работа функции умножения вектора на число"<<endl;
    cout<<"v10 = 5 * v4(4,2,3)"<<endl;
    vect v10 = 5*v4;
    v10.print();

    cout<<"----------------------------------------------------------"<<endl;
    cout<<"Демонстрация всех конструкторов, методов и функций матриц:"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"Работа конструктора матрицы по умолчанию (единичной) matr():"<<endl;;
    matr m1 = matr();
    m1.print();

    cout<<"Работа конструктора копирования  matr(matr):"<<endl;
    matr m2(m1);
    m2.print();

    cout<<"Работа конструктора создания нулевого вектора matr(int):"<<endl;
    matr m3(4);
    m3.print();

    cout<<"Работа конструктора создания вектора c заданными параметрами matr(int,double):"<<endl;
    double b[] = {4,2,6}, c[] = {3,1,7}, d[] = {5,3,2}, *x[] = {b,c,d};
    matr m4(3,x);
    m4.print();

    cout<<"Работа функции сложения матриц:"<<endl;
    cout<<"m6 = m4((4,2,6),(3,1,7),(5,3,2)) + m1((1,0,0),(0,1,0),(0,0,1))"<<endl;
    matr m6 = m4+m1;
    m6.print();

    cout<<"Работа функции бинарного вычитания матриц:"<<endl;
    cout<<"m7 = m4((4,2,6),(3,1,7),(5,3,2)) - m1((1,0,0),(0,1,0),(0,0,1))"<<endl;
    matr m7 = m4-m1;
    m7.print();

    cout<<"Работа функции унарного вычитания матриц:"<<endl;
    cout<<"m8 = -m1((1,0,0),(0,1,0),(0,0,1))"<<endl;
    matr m8 = -m1;
    m8.print();

    cout<<"Работа функции присвоения матрицы:"<<endl;
    cout<<"m9 = m4((4,2,6),(3,1,7),(5,3,2))"<<endl;
    matr m9 = m4;
    m9.print();
    
    cout<<"Работа функции перемножения матриц:"<<endl;
    cout<<"m10 = m4((4,2,6),(3,1,7),(5,3,2)) * m6((((5,2,6),(3,2,7),(5,3,3))))"<<endl;
    matr m10 = m4*m6;
    m10.print();

    cout<<"Работа функции умножения матрицы на число:"<<endl;
    cout<<"m11 = 5 * m4((4,2,6),(3,1,7),(5,3,2))"<<endl;
    matr m11 = 5*m4;
    m11.print();

    cout<<"Работа функции умножения матрицы на вектор-столбец:"<<endl;
    cout<<"v11 = m4((4,2,6),(3,1,7),(5,3,2)) * v4(4,2,3)"<<endl;
    vect v11 = m4*v4;
    v11.print();

    cout<<"------------------------------------"<<endl;
    cout<<"Демонстрация работы сложных функций:"<<endl;
    cout<<"------------------------------------"<<endl;

    cout<<"ПРИМЕР 1 (матрицы: двойное присваивание, сложение матрицы умноженной на число):"<<endl;
    cout<<"m15 = m11 = m4((4,2,6),(3,1,7),(5,3,2)) + 5 * m1((1,0,0),(0,1,0),(0,0,1))"<<endl;
    matr m12(3);
    matr m15 = m12 = m4 + 5 * m1;
    m15.print();

    cout<<"ПРИМЕР 2 (векторы: двойное присваивание, сложение вектора умноженного на число):"<<endl;
    cout<<"v15 = v12 = v4(4,2,3) + 3 * v7(3,1,2)"<<endl;
    vect v12(3);
    vect v15 = v12 = v4 + 3 * v7;
    v15.print();

    
}
