#include <cstdio>
#include <algorithm>
using namespace std;
int win[100010],lose[100010],a[200010],b[200010],c[200010];
inline bool cmp(int x,int y)
{
    return(a[x]>a[y] || a[x]==a[y] && x<y);
}
int main()
{
    int n,m,Q;
    scanf("%d%d%d",&n,&m,&Q);
    n<<=1;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        c[i]=i;
    sort(c+1,c+n+1,cmp);
    while (m--)
    {
        int t=0;
        for (int i=1;i<=n;i+=2)
        {
            int x=c[i],y=c[i+1];
            if (b[x]<b[y])
                swap(x,y);
            a[x]++;
            win[++t]=x;
            lose[t]=y;
        }
        merge(win+1,win+t+1,lose+1,lose+t+1,c+1,cmp);
    }
    printf("%d\n",c[Q]);
    return(0);
}

