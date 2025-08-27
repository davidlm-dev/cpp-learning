#include <iostream>

int add (int a, int b)
{
     int c = a+b;
     return c;
}

int substract (int a, int b)
{
    int c = a-b;
    return c;
}

int multiply (int a, int b)

{
    int c = a * b;
    return c;

}

int divide (int a, int b)

{
    int c = a/b;
    return c;

}



int main () 
{
    std::cout<<"write two numbers\n";
    int x{},y{},z{},w{};
    std::cin>>x>>y;
    std::cout<<"Choose the operation writting the number\n";
    std::cout<<"1) Addition\n";
    std::cout<<"2) Substraction\n";
    std::cout<<"3) Multiplication\n";
    std::cout<<"4) Division\n";
    std::cin>>z;

    switch (z)
    {
    case 1:
        w = add(x,y);
        break;
    
    case 2:
        w = substract(x,y);
        break;
    
    case 3:
        w = multiply(x,y);
        break;
    
    case 4:
        w = divide(x,y);
        break;
    
    default:
        std::cout << "Invalid operation.\n";
        return 1;
        break;
    }
    std::cout<<"The result is "<< w << '\n';
    return 0;
}

