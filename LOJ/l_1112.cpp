#include <cstdio>
#include <cstring>
typedef long long ll;
int n,a[100010];
ll c[100010];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
ll query(int x)
{
    ll ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Q;
        scanf("%d%d",&n,&Q);
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            modify(i,a[i]);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int op;
            scanf("%d",&op);
            if (op==1)
            {
                int x;
                scanf("%d",&x);
                x++;
                modify(x,-a[x]);
                printf("%d\n",a[x]);
                a[x]=0;
            }
            else if (op==2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x++;
                modify(x,y);
                a[x]+=y;
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",query(y+1)-query(x));
            }
        }
    }
    return(0);
}

