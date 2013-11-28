#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n<m)
            printf("0\n");
        else
            printf("%f\n",1-double(m)/(n+1));
    }
    return(0);
}

