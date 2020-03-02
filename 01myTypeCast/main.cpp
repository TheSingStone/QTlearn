#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"
using namespace std;



int main()
{
    Animal *pa = new Dog;
    pa->voice();
    delete pa;
    cout<<"----------------"<<endl;
    pa = new Cat;
    pa->voice();
    delete pa;
    return 0;

}

