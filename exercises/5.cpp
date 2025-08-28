#include <iostream>

void numCompare(int a, int b);

int main ()
{

    int x,y;
    std::cout<<"Write 2 integer numbers\n";
    std::cin>>x>>y;
    numCompare(x,y);
    return 0;

}

void numCompare(int a , int b)
{

    if (a>b)
    {
        std::cout<<"Number " << a << " is greater than " << b <<'\n';
    }
    else
    {
        std::cout<<"Number " << b << " is greater than " << a <<'\n';
    }
    
}