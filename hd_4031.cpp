#include <cstdio>
#include <cstring>
int n,a[20010],b[20010],l[20010],r[20010],c[20010];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=value;
}
int get(int x)
{
    int ans=0;
    for (int i=x;i;i-=i&-i)
        ans+=c[i];
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        int Q,t;
        scanf("%d%d%d",&n,&Q,&t);
        int m=0;
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[0]=='A')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                l[m]=x,r[m++]=y;
                modify(x,1);
                modify(y+1,-1);
            }
            else
            {
                int x;
                scanf("%d",&x);
                for (int i=a[x];i<m;i++)
                {
                    if (l[i]>x || r[i]<x)
                        continue;
                    b[x]++;
                    a[x]=i+t;
                    i+=t-1;
                }
                printf("%d\n",get(x)-b[x]);
            }
        }
    }
    return(0);
}

