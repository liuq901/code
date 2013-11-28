#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
int v[20],b[20],a[100000][2];
bool adj[20][20];
pair <ll,ll> f[8200][15][15];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        memset(adj,0,sizeof(adj));
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x][y]=adj[y][x]=true;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        if (n==1)
        {
            printf("%d 1\n",v[1]);
            continue;
        }
        int limit=1<<n;
        for (int i=0;i<limit;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                    f[i][j][k]=make_pair(-1,-1);
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][1])
            {
                int x=a[j][0];
                if (i==x)
                    continue;
                pair <ll,ll> &ret=f[1<<i-1|1<<x-1][i][x];
                if (ret.first==-1)
                    ret=make_pair(v[i]+v[x]+v[i]*v[x],1);
                else
                    ret.second++;
            }
        pair <ll,ll> ans(-1,-1);
        for (int i=0;i<limit;i++)
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                {
                    if (f[i][j][k].first==-1)
                        continue;
                    for (int l=b[k];l;l=a[l][1])
                    {
                        int x=a[l][0];
                        if (i>>x-1&1)
                            continue;
                        ll now=f[i][j][k].first+v[x]+v[k]*v[x];
                        if (adj[j][x] && adj[k][x])
                            now+=v[j]*v[k]*v[x];
                        pair <ll,ll> &ret=f[i|1<<x-1][k][x];
                        if (now>ret.first)
                            ret=make_pair(now,f[i][j][k].second);
                        else if (now==ret.first)
                            ret.second+=f[i][j][k].second;
                    }
                    if (i!=limit-1)
                        continue;
                    if (f[i][j][k].first>ans.first)
                        ans=f[i][j][k];
                    else if (f[i][j][k].first==ans.first)
                        ans.second+=f[i][j][k].second;
                }
        if (ans.first==-1)
            ans=make_pair(0,0);
        cout<<ans.first<<" "<<ans.second/2<<endl;
    }
    return(0);
}

