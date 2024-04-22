#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//Описание структуры
struct Students
{
    //Поля структуры
    string name;
    string sex;
    string spec;
    double group;
    double age;
    double avgrate;
};

//Функция для отображения информации
void print(Students str)
{
    cout<<"Имя студента: "<<str.name<<endl;
    cout<<"Пол: "<<str.sex<<endl;
    cout<<"Возвраст: "<<str.age<<endl;
    cout<<"Номер группы: "<<str.group<<endl;
    cout<<"Направление подготовки: "<<str.spec<<endl;
    cout<<"Средний балл: "<<str.avgrate<<endl;
    cout<<""<<endl;
}

//Главная функция
int main()
{
    //Добавление экземпляров структуры
    Students Alex={"Алексей","муж.","Бизнес-информатика",1,19,90.4};
    Students Nicolo={"Николай","муж.","Математика и механика",6,18,73.3};
    Students Kate={"Екатерина","жен.","Комп. и инф. науки",3,17,85.2};
    Students Boris={"Борис","муж","Строительство",11,20,52.3};
    
    //Вывод на экран
    print(Alex);
    print(Nicolo);
    print(Kate);
    print(Boris);
}