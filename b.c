#include <stdio.h>

void func1(int *i)
{
    *i = 372;
}

/*
void func2(const int *i)
{
    // Not allowed Compile error
    // *i = 372;
}
*/

void func3(int &i)
{
    i = 423;
}

int main()
{
    int  a = 152;

    printf("%d\n", a);

    func1(&a);
    printf("%d\n", a);

    func3(&a);
    printf("%d\n", a);

}