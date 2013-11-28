#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int tot,n,m,d[20010],b[20010],a[400010][2],e[200010][3];
bool f[20010];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=b[y],b[y]=tot;
}
bool check(int limit)
{
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    tot=0;
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1],z=e[i][2];
        if (z>limit)
            continue;
        add(x,y+n);
        d[y+n]++;
    }
    int k=0;
    d[0]=1<<30;
    for (int i=n+1;i<=2*n;i++)
        if (d[i]<d[k])
            k=i;
    for (int i=b[k];i;i=a[i][1])
    {
        int x=a[i][0];
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        for (int j=b[x];j;j=a[j][1])
        {
            int y=a[j][0];
            f[y]=true;
        }
        int sum=0;
        bool flag=true;
        for (int j=n+1;j<=2*n;j++)
        {
            if (f[j])
                continue;
            sum++;
            flag=false;
            for (int k=b[j];k;k=a[k][1])
            {
                int y=a[k][0];
                if (++d[y]==sum)
                    flag=true;
            }
            if (!flag)
                break;
        }
        if (flag)
            return(true);
    }
    return(false);
}
vector <int> value;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
        value.push_back(e[i][2]);
    }
    sort(value.begin(),value.end());
    value.erase(unique(value.begin(),value.end()),value.end());
    int l=0,r=value.size()-1,ans=-1;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (check(value[mid]))
            r=mid-1,ans=value[mid];
        else
            l=mid+1;
    }
    if (ans==-1)
        printf("No solution\n");
    else
        printf("%d\n",ans);
    return(0);
}

