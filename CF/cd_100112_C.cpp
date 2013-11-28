#include <cstdio>
#include <cstdlib>
const int N=600010;
int tot,root,l[N],r[N],s[N],v[N],c[N];
char buf[100000];
int find(int x,int pos)
{
    if (pos<=s[l[x]])
        return(find(l[x],pos));
    if (pos==s[l[x]]+1)
        return(x);
    return(find(r[x],pos-s[l[x]]-1));
}
int merge(int x,int y)
{
    if (!x)
        return(y);
    if (!y)
        return(x);
    if (c[x]<c[y])
    {
        r[x]=merge(r[x],y);
        s[x]=s[l[x]]+s[r[x]]+1;
        return(x);
    }
    else
    {
        l[y]=merge(x,l[y]);
        s[y]=s[l[y]]+s[r[y]]+1;
        return(y);
    }
}
void del(int &x,int value)
{
    if (v[x]==value)
    {
        x=merge(l[x],r[x]);
        return;
    }
    if (value<v[x])
        del(l[x],value);
    else
        del(r[x],value);
    s[x]=s[l[x]]+s[r[x]]+1;
}
void left(int &x)
{
    int t=l[x];
    l[x]=r[t];
    r[t]=x;
    s[t]=s[x];
    s[x]=s[l[x]]+s[r[x]]+1;
    x=t;
}
void right(int &x)
{
    int t=r[x];
    r[x]=l[t];
    l[t]=x;
    s[t]=s[x];
    s[x]=s[l[x]]+s[r[x]]+1;
    x=t;
}
void insert(int &x,int value)
{
    if (x==0)
    {
        x=++tot;
        l[x]=r[x]=0;
        s[x]=1;
        v[x]=value;
        c[x]=rand();
        return;
    }
    if (value<v[x])
    {
        insert(l[x],value);
        s[x]++;
        if (c[l[x]]<c[x])
            left(x);
    }
    else
    {
        insert(r[x],value);
        s[x]++;
        if (c[r[x]]<c[x])
            right(x);
    }
}
int main()
{
    while (scanf("%s",buf)==1)
    {
        if (buf[0]=='#')
        {
            int p=find(root,s[root]/2+1);
            printf("%d\n",v[p]);
            del(root,v[p]);
        }
        else
        {
            int x;
            sscanf(buf,"%d",&x);
            insert(root,x);
        }
    }
    return(0);
}

