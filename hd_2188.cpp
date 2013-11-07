#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%s\n",n%(m+1)==0?"Rabbit":"Grass");
    }
    return(0);
}

