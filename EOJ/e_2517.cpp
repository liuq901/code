#include <cstdio>
bool f[510];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if (op==0)
            for (int j=l;j<=r;j++)
                f[j]=!f[j];
        else
        {
            int ans=0;
            for (int j=l;j<=r;j++)
                ans+=f[j];
            printf("%d\n",ans);
        }
    }
    return(0);
}

