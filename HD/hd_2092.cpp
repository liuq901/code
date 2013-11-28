#include <cstdio>
#include <cstdlib>
bool check(int n,int m)
{
    int t=abs(m);
    for (int i=-t;i<=t;i++)
    {
        int p=n-i;
        if (i*p==m)
            return(true);
    }
    return(false);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        printf("%s\n",check(n,m)?"Yes":"No");
    }
    return(0);
}

