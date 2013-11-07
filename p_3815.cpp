#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1010;
int n,D,a[N],c[N],h[N],pos[N];
inline bool cmp(int x,int y)
{
    return(h[x]<h[y]);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&D);
        if (n==0 && D==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&h[i]);
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        for (int i=1;i<=n;i++)
            a[c[i]]=i;
        for (int i=1;i<=n;i++)
            pos[i]=i;
        bool flag=true;
        for (int i=2;i<=n;i++)
            if (abs(pos[c[i]]-pos[c[i-1]])>D)
            {
                flag=false;
                break;
            }
        if (!flag)
        {
            printf("-1\n");
            continue;
        }
        int l=min(c[1],c[n]),r=max(c[1],c[n]);
        for (int i=l+1;i<=r;i++)
        {
            int len=1<<30;
            for (int j=1;j<i;j++)
            {
                if (a[j]>1 && c[a[j]-1]>=i)
                    len=min(len,D-(pos[c[a[j]-1]]-pos[j]));
                if (a[j]<n && c[a[j]+1]>=i)
                    len=min(len,D-(pos[c[a[j]+1]]-pos[j]));
            }
            for (int j=i;j<=n;j++)
                pos[j]+=len;
        }
        printf("%d\n",pos[r]-pos[l]);
    }
    return(0);
}

