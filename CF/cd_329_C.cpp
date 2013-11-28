#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int l[N],p[N],r[N],d[N],c[N],b[N],a[2*N][2];
vector <pair <int,int> > ans;
inline bool connect(int x,int y)
{
    for (int i=b[x];i;i=a[i][1])
        if (y==a[i][0])
            return(true);
    return(false);
}
bool vis[10];
int dfs(int x)
{
    int ret=1;
    vis[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!vis[y])
            ret+=dfs(y);
    }
    return(ret);
}
bool ring3()
{
    for (int i=1;i<=6;i++)
        if (!vis[i] && dfs(i)!=3)
            return(false);
    for (int i=1;i<=6;i++)
        if (!vis[i] && dfs(i)!=3)
            return(false);
    return(true);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if (ll(n)*(n-1)/2-m<m)
        printf("-1\n");
    else
    {
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            d[x]++,d[y]++;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        if (n==4 && m==3 && count(d+1,d+n+1,0)==1)
            printf("-1\n");
        else if (n==6 && m==6 && ring3())
        {
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    if (i!=j && !connect(i,j))
                    {
                        p[1]=i,p[2]=j;
                        for (int k=1;k<=n;k++)
                        {
                            if (connect(i,k))
                                p[3]=k;
                            if (connect(j,k))
                                p[4]=k;
                        }
                        for (int k=n;k;k--)
                        {
                            if (connect(i,k))
                                p[5]=k;
                            if (connect(j,k))
                                p[6]=k;
                        }
                    }
            p[0]=p[6];
            for (int i=1;i<=6;i++)
                printf("%d %d\n",p[i-1],p[i]);
        }
        else
        {
            for (int i=1;i<=n;i++)
                c[i]=i;
            ans.clear();
            while (ans.size()<m)
            {
                random_shuffle(c+1,c+n+1);
                ans.clear();
                for (int i=1;i<=n;i++)
                {
                    r[i]=i+1;
                    l[i]=i-1;
                    p[i]=0;
                }
                int now=1,tot=0;
                for (int i=1;i<=n;i++)
                {
                    int x=c[i];
                    while (now==i || p[c[now]]==2)
                        now=r[now];
                    for (int j=now;j!=n+1;j=r[j])
                    {
                        if (p[x]==2)
                            break;
                        int y=c[j];
                        if (!connect(x,y))
                        {
                            p[x]++,p[y]++;
                            ans.push_back(make_pair(x,y));
                            tot++;
                            if (tot==m)
                                break;
                            if (p[y]==2)
                                l[r[j]]=l[j],r[l[j]]=r[j];
                        }
                    }
                    if (tot==m)
                        break;
                    if (p[x]==2)
                        l[r[i]]=l[i],r[l[i]]=r[i];
                }
            }
            for (int i=0;i<ans.size();i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
    return(0);
}

