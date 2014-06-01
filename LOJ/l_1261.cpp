#include <cstdio>
#include <cstring>
int a[40][40];
bool in[40];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=K;j++)
                scanf("%d",&a[i][j]);
        memset(in,0,sizeof(in));
        int p;
        scanf("%d",&p);
        for (int i=1;i<=p;i++)
        {
            int x;
            scanf("%d",&x);
            in[x]=true;
        }
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            flag=false;
            for (int j=1;j<=K;j++)
                if (a[i][j]>0 && in[a[i][j]] || a[i][j]<0 && !in[-a[i][j]])
                {
                    flag=true;
                    break;
                }
            if (!flag)
                break;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,flag?"Yes":"No");
    }
    return(0);
}

