#include <QCoreApplication>
#include <iostream>


int __fastcall AddInt(int a,int b);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int x = 1;
    int y = 3;
    int c = AddInt(x,y);
    std::cout<<"c = "<<c<<std::endl;
    return a.exec();
}

int AddInt(int a,int b)
{
    int c = a + b;
    return c;
}
