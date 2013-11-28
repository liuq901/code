#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100010;
int l[N],r[N],len[N],c[N];
inline bool cmp(int x,int y)
{
    return(r[x]<r[y] || r[x]==r[y] && l[x]<l[y]);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            len[i]=(r[i]-l[i])/2+1;
            r[i]-=len[i];
            c[i]=i;
        }
        sort(c+1,c+n+1,cmp);
        int last=0;
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            int x=c[i];
            if (last>r[x])
            {
                flag=false;
                break;
            }
            last=max(last,l[x])+len[x];
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

