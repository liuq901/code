#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
bool f[1010];
int d[1010];
vector <int> a[1010];
void init()
{
    const int n=1000;
    for (int i=2;i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=2;i*j<=n;j++)
        {
            f[i*j]=true;
            a[i*j].push_back(i);
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(d,-1,sizeof(d));
        d[n]=0;
        queue <int> Q;
        Q.push(n);
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            for (int i=0;i<a[x].size();i++)
            {
                int y=a[x][i];
                if (x+y<=m && d[x+y]==-1)
                {
                    d[x+y]=d[x]+1;
                    Q.push(x+y);
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,d[m]);
    }
    return(0);
}

