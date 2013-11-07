#include <cstdio>
#include <cstdlib>
typedef long long ll;
const int N=10010;
char buf[100];
int tot,root,l[N],r[N],f[N],v[N],c[N],s[N];
int myrandom()
{
    return(rand()<<16|rand());
}
int node(int value,int fa)
{
    tot++;
    l[tot]=r[tot]=0;
    s[tot]=1;
    f[tot]=fa;
    v[tot]=value;
    c[tot]=myrandom();
    return(tot);
}
void update(int x)
{
    s[x]=s[l[x]]+s[r[x]]+1;
}
void rotate(int x,bool right)
{
    int t=f[x],p=right?l[x]:r[x];
    if (f[t]==0)
        root=x;
    else if (t==l[f[t]])
        l[f[t]]=x;
    else
        r[f[t]]=x;
    if (!right)
        r[x]=t,l[t]=p;
    else
        l[x]=t,r[t]=p;
    f[x]=f[t],f[t]=x,f[p]=t;
    update(t);
    update(x);
}
int merge(int x,int y)
{
    if (x==0 || y==0)
        return(x+y);
    if (c[x]<c[y])
    {
        int p=merge(r[x],y);
        f[p]=x;
        r[x]=p;
        update(x);
        return(x);
    }
    else
    {
        int p=merge(x,l[y]);
        f[p]=y;
        l[y]=p;
        update(y);
        return(y);
    }
}
bool del(int x,int value)
{
    if (x==0)
        return(false);
    if (v[x]==value)
    {
        int t=merge(l[x],r[x]);
        if (f[x]==0)
            root=t;
        else if (x==l[f[x]])
            l[f[x]]=t;
        else
            r[f[x]]=t;
        f[t]=f[x];
        return(true);
    }
    bool ret=value<v[x]?del(l[x],value):del(r[x],value);
    update(x);
    return(ret);
}
void add(int x,int value)
{
    if (x==0)
    {
        root=node(value,0);
        return;
    }
    if (value<=v[x])
    {
        if (!l[x])
            l[x]=node(value,x);
        else
            add(l[x],value);
        update(x);
        if (c[l[x]]<c[x])
            rotate(l[x],false);
        return;
    }
    if (!r[x])
        r[x]=node(value,x);
    else
        add(r[x],value);
    update(x);
    if (c[r[x]]<c[x])
        rotate(r[x],true);
}
int find(int x,int k)
{
    if (s[l[x]]+1==k)
        return(v[x]);
    if (k<=s[l[x]])
        return(find(l[x],k));
    return(find(r[x],k-s[l[x]]-1));
}
void query()
{
    if (root==0)
    {
        printf("Empty!\n");
        return;
    }
    int k=(s[root]+1)/2;
    if (s[root]%2==1)
        printf("%d\n",find(root,k));
    else
    {
        ll p=ll(find(root,k))+find(root,k+1);
        if (p%2==0)
            printf("%lld\n",p/2);
        else
        { 
            if (p<0)
                printf("-");
            printf("%lld.5\n",(llabs(p)-1)/2);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int Q;
        scanf("%d",&Q);
        root=tot=0;
        while (Q--)
        {
            int x;
            scanf("%s%d",buf,&x);
            if (buf[0]=='a')
            {
                add(root,x);
                query();
            }
            else if (buf[0]=='r')
                if (del(root,x))
                    query();
                else
                    printf("Wrong!\n");
        }
    }
    return(0);
}

