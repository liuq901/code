#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int tot,b[100010],d[100010],e[200010][3],a[400010][3];
vector <int> now,tmp,ans;
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
}
int q[100010];
void bfs(int S)
{
    int l,r;
    memset(d,0,sizeof(d));
    q[l=r=1]=S,d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y]==0)
            {
                d[y]=d[x]+1;
                q[++r]=y;
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
            e[i][0]=x,e[i][1]=y,e[i][2]=z;
        }
        bfs(n);
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=m;i++)
        {
            int x=e[i][0],y=e[i][1],z=e[i][2];
            if (d[x]==0 || d[y]==0)
                continue;
            if (d[x]==d[y]+1)
                add(x,y,z);
            if (d[y]==d[x]+1)
                add(y,x,z);
        }
        now.clear();
        ans.clear();
        now.push_back(1);
        for (int i=2;i<=d[1];i++)
        {
            int t=1<<30;
            for (int j=0;j<now.size();j++)
            {
                int x=now[j];
                for (int k=b[x];k;k=a[k][2])
                {
                    int y=a[k][0];
                    if (a[k][1]<t)
                    {
                        t=a[k][1];
                        tmp.clear();
                        tmp.push_back(y);
                    }
                    else if (a[k][1]==t)
                        tmp.push_back(y);
                }
            }
            sort(tmp.begin(),tmp.end());
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            now=tmp;
            ans.push_back(t);
        }
        printf("%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return(0);
}

