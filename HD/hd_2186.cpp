#include <cstdio>
inline int calc(int x)
{
    return((x+9)/10);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int x=n/2;
        n-=x;
        int y=2*n/3;
        n-=y;
        printf("%d\n",calc(n)+calc(x)+calc(y));
    }
    return(0);
}

