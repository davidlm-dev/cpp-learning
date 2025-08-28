#include <iostream>

int main ()
{
    int z;
    int x = 0;
    int numbers [5] = {7,4,2,4,6};
    for (size_t i = 0; i < 4; i++)
    {
        if (numbers[i]>numbers[i+1])
        {
            z = numbers[i+1];
            numbers[i+1] = numbers[i];
            numbers[i] = z;
        }
    }

        for (size_t i = 0; i < 4; i++)
    {
        if (numbers[i]>numbers[i+1])
        {
            z = numbers[i+1];
            numbers[i+1] = numbers[i];
            numbers[i] = z;
        }
    }

    do
    {
        std::cout<<numbers[x];
        x++;
    } while (x <5);
    

    return 0;
}