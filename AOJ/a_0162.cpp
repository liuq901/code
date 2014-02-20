#include <cstdio>
const int c[]={2,3,5};
bool f[1000010];
int ans[1000010];
void init()
{
    f[1]=true;
    for (int i=1;i<=1000000;i++)
    {
        if (!f[i])
            continue;
        for (int j=0;j<3;j++)
            if (i*c[j]<=1000000)
                f[i*c[j]]=true;
    }
    for (int i=1;i<=1000000;i++)
        ans[i]=ans[i-1]+f[i];
}
int main()
{
    init();
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
        printf("%d\n",ans[m]-ans[n-1]);
    return(0);
}

