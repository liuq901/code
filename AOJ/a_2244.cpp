#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
map <char,int> M,to;
char direct[1010],a[110][110];
int b[20],num[1010],f[4100];
int main()
{
    to['U']=0,to['D']=1,to['L']=2,to['R']=3;
    while (1)
    {
        int init,hp;
        scanf("%d%d",&init,&hp);
        if (init==0 && hp==0)
            break;
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int K;
        M.clear();
        scanf("%d",&K);
        for (int i=1;i<=K;i++)
        {
            int x;
            scanf("%s%d",a[0],&x);
            M[a[0][0]]=x;
        }
        scanf("%d",&K);
        for (int i=1;i<=K;i++)
        {
            int x;
            scanf("%s%d",a[0],&x);
            direct[i]=a[0][0];
            num[i]=x;
        }
        int p;
        scanf("%d",&p);
        for (int i=1;i<=p;i++)
            scanf("%d",&b[i]);
        memset(f,0,sizeof(f));
        int limit=1<<p;
        f[limit-1]=init;
        int x=1,y=1;
        for (int i=1;i<=K;i++)
            for (int j=1;j<=num[i];j++)
            {
                int k=to[direct[i]];
                x+=c[k][0],y+=c[k][1];
                for (int i=limit-1;i>=0;i--)
                {
                    if (f[i]==0)
                        continue;
                    for (int j=1;j<=p;j++)
                        if (i>>j-1&1)
                        {
                            int now=i^1<<j-1;
                            f[now]=max(f[now],min(f[i]+b[j],hp));
                        }
                }
                int t=M[a[x][y]];
                for (int i=0;i<limit;i++)
                    f[i]=max(f[i]-t,0);
            }
        bool flag=false;
        for (int i=0;i<limit;i++)
            if (f[i]>0)
            {
                flag=true;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

