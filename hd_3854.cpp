#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long ll;
int n,Log[N],c[N],C[N],left[N],right[N],f[20][N];
int get(int l,int r)
{
    int t=Log[r-l+1];
    return(min(f[t][l],f[t][r-(1<<t)+1]));
}
void add(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        C[i]+=value;
}
int find(int x)
{
    int ans=0;
    for (int i=x;i;i-=i&-i)
        ans+=C[i];
    return(ans);
}
int calc(int x,int color)
{
    int p=0,q=0;
    if (left[x]!=-1)
    {
        p=find(left[x]);
        if (color==1)
            p=left[x]-p;
    }
    if (right[x]!=-1)
    {
        q=find(n)-find(right[x]-1);
        if (color==1)
            q=n-right[x]+1-q;
    }
    return(p+q);
}
int main()
{
    int T;
    scanf("%d",&T);
    Log[0]=-1;
    for (int i=1;i<=100000;i++)
    {
        Log[i]=Log[i-1];
        if ((i&i-1)==0)
            Log[i]++;
    }
    while (T--)
    {
        int m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++)
            scanf("%d",&f[0][i]);
        for (int i=1;i<=Log[n];i++)
            for (int j=1;j<=n;j++)
            {
                if (j+(1<<i)-1>n)
                    break;
                f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
            }
        for (int i=1;i<=n;i++)
        {
            left[i]=right[i]=-1;
            int l=1,r=i-1;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (get(mid,i)<K)
                    l=mid+1,left[i]=mid;
                else
                    r=mid-1;
            }
            l=i+1,r=n;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (get(i,mid)<K)
                    r=mid-1,right[i]=mid;
                else
                    l=mid+1;
            }
        }
        memset(C,0,sizeof(C));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            if (c[i]==1)
                add(i,1);
        }
        ll ans=0;
        for (int i=1;i<=n;i++)
            ans+=calc(i,c[i]);
        ans>>=1;
        for (int i=1;i<=m;i++)
        {
            int op;
            scanf("%d",&op);
            if (op==0)
            {
                int x;
                scanf("%d",&x);
                ans+=calc(x,1-c[x])-calc(x,c[x]);
                c[x]=1-c[x];
                if (c[x]==1)
                    add(x,1);
                else
                    add(x,-1);
            }
            else
                printf("%I64d\n",ans);
        }
    }
    return(0);
}

