#include <iostream>
// #include <fstream>
// #include <string>
// #include <stdio.h>

using namespace std;

//
// Test pointer on pointer argument
// 
void func1(char **a)
{    
    printf("2   %p    \n", *a);

    static char *b = (char *) "Hello world, pointer on pointers";

    printf("3   %p    \n", b);

    a = &b;
    printf("4   %p    \n", *a);
}

void func2(char &a)
{
    //a = &"Hello world, pass by reference";
 }

void func3(int **i)
{
    int a = 1821;
    int *aptr = &a;
    i = &aptr;
}

int main(int argc, char *argv[])
{
        
    char *c ;
    printf("1   %p    \n", c);

    func1(&c);

    printf("5   %p    \n", c);
    // cout << &c << endl;

    /*
    char *l0 = "hello world";
    char *l1 = l0;
    char *l2 = l0;    
    printf("%p       %p       %p\n", l0, l1, l2);
    */

    


    // int n = 5489;
    //func3(&n);
    //cout << *n << endl;
    
    return 0;
}