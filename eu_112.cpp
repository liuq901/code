#include <cstdio>
bool increase(int x)
{
    int now=9;
    while (x)
    {
        if (now<x%10)
            return(false);
        now=x%10;
        x/=10;
    }
    return(true);
}
bool decrease(int x)
{
    int now=0;
    while (x)
    {
        if (now>x%10)
            return(false);
        now=x%10;
        x/=10;
    }
    return(true);
}
int main()
{
    int tot=0;
    for (int i=1;;i++)
    {
        if (!increase(i) && !decrease(i))
            tot++;
        if (tot*100==i*99)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

