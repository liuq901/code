#include <cstdio>
int main()
{
    double p=3.0/7,now=1e10;
    int x=1,u;
    for (int i=2;i<=1000000;i++)
    {
        while (double(x)/i<p)
            x++;
        x--;
        double value=double(x)/i;
        if (p-value<now)
        {
            now=p-value;
            u=x;
        }
    }
    printf("%d\n",u);
    return(0);
}

