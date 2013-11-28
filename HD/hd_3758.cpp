#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
const int limit=10010;
vector <short> a[limit+10];
vector <pair <int,int> > ans;
bool f[limit+10];
int tot,prime[1300],b[1300];
void init()
{
    for (int i=2;i*i<limit;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=limit;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=limit;i++)
        if (!f[i])
            prime[tot++]=i;
    for (int i=2;i<=limit;i++)
    {
        a[i]=a[i-1];
        if (!f[i])
        {
            a[i].push_back(1);
            continue;
        }
        int x=i;
        for (int j=0;j<a[i].size();j++)
        {
            int p=prime[j];
            if (x%p)
                continue;
            while (x%p==0)
            {
                a[i][j]++;
                x/=p;
            }
            if (x==1)
                break;
        }
    }
}
int calc(int x)
{
    int ret=1<<30;
    for (int i=0;i<a[x].size();i++)
        ret=min(ret,b[i]/a[x][i]);
    return(ret);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(b,0,sizeof(b));
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int i=0;i<a[x].size();i++)
                b[i]+=a[x][i];
        }
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            for (int i=0;i<a[x].size();i++)
                b[i]-=a[x][i];
        }
        bool flag=true;
        for (int i=0;i<tot;i++)
            if (b[i]<0)
            {
                flag=false;
                break;
            }
        if (!flag)
            printf("-1\n");
        else
        {
            ans.clear();
            for (int i=limit;i>1;i--)
            {
                int t=calc(i);
                if (t>0)
                {
                    ans.push_back(make_pair(i,t));
                    for (int j=0;j<a[i].size();j++)
                        b[j]-=a[i][j]*t;
                }
            }
            printf("%d\n",ans.size());
            for (int i=0;i<ans.size();i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
    return(0);
}

