#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

//Описание структуры
struct tovar
{
    //Поля структуры
    string name;
    float price;
    int amount;
    //Поле задающее список
    tovar* next;
};

//Функция создающая товары, на выход получается указатель, содержащий адрес созданного товара.
tovar*Createtovar()
{
    tovar*tmp = new tovar;
    cout<<"Введите название товара: ";
    cin>> tmp->name;
    cout<<"Введите Цену: ";
    cin>> tmp->price;
    cout<<"Введите кол-во товара на складе: ";
    cin>> tmp->amount;
    tmp->next = NULL;
    return tmp;
}


/*Функция заменяющая указатель tlist на новосозданный указатель tmp, tmp->next при этом указывает на бывший tlist.
Таким образом новый товар становится первым в списке, а все остальные сдвигаются*/
void AddFirst (tovar*&tlist, tovar*tmp)
{
    tmp->next=tlist;
    tlist = tmp;
}

//Функция добавляющая товар после указанного(товар находится по имени), если указанного
// товара нет - добавляет в конец списка.
void AddAfter (tovar*&tlist, string fname, tovar*tmp)
{
    tovar*n=tlist;
    while ((n->next!=NULL) && (n->name!=fname))
    {
        n=n->next;
    }
    tmp->next = n->next;
    n->next=tmp;
}

// Функция добавляющая элемент перед указанным (товар находится по имени), если список пустой то в начало
// если указанноготовара нет - добавляет в конец списка.
void AddBefore(tovar*&tlist, string fname, tovar*tmp)
{
    tovar*n=tlist;
    if ((tlist==NULL) || (tlist->name==fname))
    {
        AddFirst(tlist,tmp);
        return;
    }
    while ((n->next!=NULL) && (n->next->name!=fname))
    {
        n=n->next;
    }
    tmp->next = n->next;
    n->next=tmp;
}



//Функция добавляющая элемент, если список пустой или добавляющая элемент в конец, если не пустой.
void AddLast(tovar*&tlist, tovar*tmp)
{
    tovar*i=tlist;
    //Если список пустой
    if (tlist ==NULL) 
    {
        AddFirst(tlist,tmp);
        return;
    }
    //Если не пустой
    while (i->next!=NULL)
    {
    i = i->next;
    }
    tmp->next = i->next;
    i->next=tmp;
}

// Функция удаляющая товар, если товар не найден - ничего не происходит.
void Deltovar(tovar*&tlist, string fname)
{
    if (tlist==NULL)
    {
        cout<<"Список уже пуст"<<endl;
        return;
    }
    tovar*n=tlist;
    if (tlist->name==fname)
    {
        tlist=tlist->next;
        delete n;
    }
    else
    {
        while ((n->next!=NULL) && (n->next->name!=fname))
        {
            n=n->next;
        }
        if ((n->next==NULL) && (n->name!=fname))
        {
            cout<<"Удаляемый элемент не найден в списке"<<endl;
            return;

        }
        else
        {
            tovar*tmp=n->next;
            n->next=n->next->next;
            delete tmp;
        }
    }
}

// Функция выводящая список на экран, если список пуст - выведет "список пуст".
void printlist (tovar*tlist)
{
    if (tlist==NULL)
    { 
    cout<<"Список пуст"<<endl;
    }
    tovar*tmp=tlist;
    while (tmp!=NULL)
    {
        cout<<"Название: "<<tmp->name<<endl;
        cout<<"Цена: "<<tmp->price<<endl;
        cout<<"Кол-во: "<<tmp->amount<<endl;
        cout<<""<<endl;
        tmp=tmp->next;
    }
}

int main()
{
    // Добавление заголовка списка (указателя на адрес первого элемента).Пока равен NULL
    tovar*tlist=NULL;
    tovar*tmp;
    int i = 7;
    string n;

    while (i!=0)
    {
        cout<<endl;
        cout<<"1 - Добавить товар в начало."<<endl;
        cout<<"2 - Добавить товар в конец списка"<<endl;
        cout<<"3 - Добавить после указанного товара"<<endl;
        cout<<"4 - Добавить товар перед указанным"<<endl;
        cout<<"5 - Введите товар, который нужно удалить из списка"<<endl;
        cout<<"6 - Вывести список товаров на экран"<<endl;
        cout<<"0 - Завершить выполнение программы"<<endl;
        cout<<endl; 
        cout<<"Ввод: ";
        cin>>i;
        cout<<endl;
            if (i==1)
            {
                tmp=Createtovar();
                AddFirst(tlist,tmp);
                i=-1;
            }
            else if (i==2)
            {
                tmp=Createtovar();
                AddLast(tlist,tmp);
                i=7;
            }
            else if (i==3)
            {
                tmp=Createtovar();
                cout<<endl;
                cout<<"Введите название товара за которым добавить: ";
                cin>>n;
                AddAfter(tlist,n,tmp);
                i=7;
            }
            else if (i==4)
            {
                tmp=Createtovar();
                cout<<endl;
                cout<<"Введите название товара перед которым добавить: ";
                cin>>n;
                AddBefore(tlist,n,tmp);
                i=7;
            }
            else if (i==5)
            {
                cout<<"Введите название товара, который нужно удалить: ";
                cin>>n;
                Deltovar(tlist,n);
                i=7;
            }
            else if (i==6)
            {
                printlist(tlist);
                i=7;
            }
            else if (i==0)
            {
              break;
            }
    }
}