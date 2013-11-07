#include <cstdio>
#include <cstring>
int n,m,a[510][2510],s[2510];
bool check(int x)
{
    memset(s,0,sizeof(s));
    for (int i=1;i<=n;i++)
    {
        bool flag=false;
        for (int j=1;j<=m;j++)
        {
            if (flag)
                s[a[i][j]]++;
            if (a[i][j]==x)
                flag=true;
        }
    }
    for (int i=0;i<m;i++)
        if (i!=x && s[i]<=n-s[i])
            return(false);
    return(true);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(s,0,sizeof(s));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][j]=x;
                s[x]+=(m-j);
            }
        int k=0;
        for (int i=0;i<m;i++)
            if (s[i]>=s[k])
                k=i;
        static int id=0;
        printf("Case %d: ",++id);
        if (check(k))
            printf("%d\n",k);
        else
            printf("No Condorcet winner\n");
    }
    return(0);
}

