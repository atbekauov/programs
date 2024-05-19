#include <iostream>
#include <cmath>

using namespace std;

int main()
{
char command[]="";
while (true)
{
cout<<"please enter command for listening port"<<endl;
cin.getline(command,50);
if (command == "ls")
{
    cout<<"Welcome in system Artur"<<endl;
}
//system("cd .. && g++ -c Untitled-2.cpp && g++ Untitled-2.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app");

system(command);
}
}