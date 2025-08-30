#include <iostream>
#include <string>

std::string inverseString (std::string a)
{
    std::string b;
    for (int i = a.size() - 1; i >= 0; --i) {
        b += a[i];
    }
    return b;
}

int main ()
{
    std::string c,d;
    std::cout<<"Introduce un string \n";
    std::cin>>c;
    d = inverseString(c);
    std::cout<<d;
    return 0;
}