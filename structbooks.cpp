#include<iostream> 
#include<cstdlib>
#include<string>
using namespace std;

//Описание структуры
struct Book
{
    //Поля структуры
    string name;
    string author;
    double year;
    double pubnum;
};

//Функция для отображения информации
void print(Book str)
{
    cout<<"Название книги: "<<str.name<<endl;
    cout<<"Автор книги: "<<str.author<<endl;
    cout<<"Год создания: "<<str.year<<endl;
    cout<<"Тираж: "<<str.pubnum<<endl;
    cout<<""<<endl;
}

//Главная функция
int main()
{
    //Добавление экземпляров структуры
    Book deadsouls={"Мёртвые души","Николай Васильевич Гоголь",1842,10000};
    Book belltoll={"По ком звонит колокол","Эрнест Хемингуэй",1940,7500};
    Book seawolf={"Морской волк","Джек Лондон",1904,3800};
    Book delamethode={"Рассуждения о методе","Рене Декарт",1637,2600};
    
    //Вывод на экран
    print(deadsouls);
    print(belltoll);
    print(seawolf);
    print(delamethode);
}