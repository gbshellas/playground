#include <iostream>

void allocate(int** p)
{
    *p = (int*)malloc(sizeof(int));
}

int main()
{
    int* p; // = NULL;
    
    allocate(&p);
    *p = 42;
    std::cout << *p << std::endl;
    free(p);
}