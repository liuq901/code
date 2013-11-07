#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
vector <int> c[210];
int n,tot,id,C[410],dfn[410],low[410],b[410],A[210][210],a[1000000][2];
stack <int> s;
bool in[410];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++id;
    s.push(x);
    in[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        C[0]++;
        while (s.top()!=x)
        {
            in[s.top()]=false;
            C[s.top()]=C[0];
            s.pop();
        }
        in[x]=false,C[x]=C[0],s.pop();
    }
}
bool check(int limit)
{
    memset(b,0,sizeof(b));
    tot=0;
    for (int i=1;i<=n;i++)
        for (int j=limit+1;j<n;j++)
        {
            int x=A[i][j];
            for (int p=0;p<2;p++)
                for (int q=0;q<2;q++)
                    if (c[i][p]==c[x][q])
                    {
                        add(i+p*n,x+(1-q)*n);
                        add(x+q*n,i+(1-p)*n);
                    }
        }
    memset(dfn,0,sizeof(dfn));
    id=C[0]=0;
    for (int i=1;i<=2*n;i++)
        if (!dfn[i])
            tarjan(i);
    for (int i=1;i<=n;i++)
        if (C[i]==C[i+n])
            return(false);
    return(true);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for (int j=0;j<=2;j++)
            if (j!=x)
                c[i].push_back(j);
        for (int j=1;j<n;j++)
            scanf("%d",&A[i][j]);
    }
    int l=0,r=n,ans;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    return(0);
}

