#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
struct data
{
    int l,r,u,d;
};
data a[300010];
map <int,int> mx,my,py;
pair <int,int> b[100010];
int X[100010],Y[100010],c[100010];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&b[i].first,&b[i].second);
            X[i]=b[i].first,Y[i]=b[i].second;
        }
        sort(b+1,b+n+1);
        sort(X+1,X+n+1);
        sort(Y+1,Y+n+1);
        int nx=unique(X+1,X+n+1)-X-1;
        int ny=unique(Y+1,Y+n+1)-Y-1;
        mx.clear();
        my.clear();
        py.clear();
        int tot=0,now=0;
        for (int i=1;i<=nx;i++)
        {
            tot++;
            a[tot].l=now;
            a[now].r=tot;
            a[tot].u=a[tot].d=tot;
            mx[X[i]]=tot;
            now=tot;
        }
        a[0].l=tot;
        a[tot].r=0;
        now=0;
        for (int i=1;i<=ny;i++)
        {
            tot++;
            a[tot].u=now;
            a[now].d=tot;
            a[tot].l=a[tot].r=tot;
            my[Y[i]]=tot;
            py[Y[i]]=i;
            now=tot;
            c[i]=tot;
        }
        a[0].u=tot;
        a[tot].d=0;
        for (int i=1;i<=n;)
        {
            int p=i;
            while (p<=n && b[p].first==b[i].first)
                p++;
            int now=mx[b[i].first],t=now;
            for (int j=i;j<p;j++)
            {
                tot++;
                a[tot].u=now;
                a[now].d=tot;
                int q=py[b[j].second];
                a[tot].l=c[q];
                a[c[q]].r=tot;
                now=c[q]=tot;
            }
            a[t].u=now;
            a[now].d=t;
            i=p;
        }
        for (int i=1;i<=ny;i++)
        {
            int t=my[Y[i]];
            a[c[i]].r=t;
            a[t].l=c[i];
        }
        for (int i=1;i<=m;i++)
        {
            int op,x;
            scanf("%d%d",&op,&x);
            if (op==1)
            {
                if (!my.count(x))
                {
                    printf("0\n");
                    continue;
                }
                int t=my[x],ans=0;
                for (int j=a[t].r;j!=t;j=a[j].r)
                {
                    ans++;
                    a[a[j].u].d=a[j].d;
                    a[a[j].d].u=a[j].u;
                }
                a[t].l=a[t].r=t;
                printf("%d\n",ans);
            }
            else
            {
                if (!mx.count(x))
                {
                    printf("0\n");
                    continue;
                }
                int t=mx[x],ans=0;
                for (int j=a[t].d;j!=t;j=a[j].d)
                {
                    ans++;
                    a[a[j].l].r=a[j].r;
                    a[a[j].r].l=a[j].l;
                }
                a[t].u=a[t].d=t;
                printf("%d\n",ans);
            }
        }
        printf("\n");
    }
    return(0);
}

