#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N=(1<<22)+10;
int a[100],count[N],log[N];
vector <int> b[260];
void init()
{
    int n=22;
    for (int i=0;i<1<<n;i++)
    {
        if (i==0)
            log[0]=0;
        else
        {
            log[i]=log[i-1];
            if (!(i&i-1))
                log[i]++;
        }
        int sum=0;
        for (int j=1;j<=n;j++)
            if (i>>j-1&1)
            {
                sum+=j;
                count[i]++;
            }
        b[sum].push_back(i);
    }
}
int f[N];
queue <int> Q;
int bfs(int n,int m)
{
    int ret=0;
    memset(f,-1,sizeof(f));
    f[0]=0;
    Q.push(0);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        int dep=f[x]+1;
        for (int i=0;i<b[a[dep]].size();i++)
        {
            if (x&b[a[dep]][i])
                continue;
            int now=x|b[a[dep]][i];
            if (log[now]>n || f[now]!=-1)
                continue;
            f[now]=dep;
            ret=max(ret,count[now]);
            if (dep!=m)
                Q.push(now);
        }
    }
    return(ret);
}
int main()
{
    init();
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        static int id=0;
        printf("Game %d: %d\n",++id,bfs(n,m));
    }
    return(0);
}

