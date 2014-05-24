#include <cstdio>
#include <cstdlib>
int tot,s[100010],l[100010],r[100010],c[100010];
void left(int &x)
{
    int t=l[x],y=r[t];
    l[x]=y;
    r[t]=x;
    s[x]=s[l[x]]+s[r[x]]+1;
    s[t]=s[l[t]]+s[r[t]]+1;
    x=t;
}
void right(int &x)
{
    int t=r[x],y=l[t];
    r[x]=y;
    l[t]=x;
    s[x]=s[l[x]]+s[r[x]]+1;
    s[t]=s[l[t]]+s[r[t]]+1;
    x=t;
}
void insert(int &x,int pos)
{
    if (x==0)
    {
        tot++;
        l[tot]=r[tot]=0;
        s[tot]=1;
        c[tot]=rand();
        x=tot;
        return;
    }
    s[x]++;
    if (pos<=s[l[x]])
    {
        insert(l[x],pos);
        if (c[l[x]]<c[x])
            left(x);
    }
    else
    {
        insert(r[x],pos-s[l[x]]-1);
        if (c[r[x]]<c[x])
            right(x);
    }
}
int a[100010];
void dump(int x)
{
    if (x==0)
        return;
    dump(l[x]);
    a[++tot]=x;
    dump(r[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        tot=0;
        int root=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            insert(root,i-1-x);
        }
        tot=0;
        dump(root);
        for (int i=1;i<=n;i++)
            if (a[i]==1)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i);
                break;
            }
    }
    return(0);
}

