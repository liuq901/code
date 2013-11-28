#include <cstdio>
#include <algorithm>
using namespace std;
int root,l[100010],r[100010],s[100010],f[100010];
bool rev[100010];
int build(int L,int R,int father)
{
    int x=L+R>>1;
    f[x]=father;
    s[x]=1;
    if (L<=x-1)
    {
        l[x]=build(L,x-1,x);
        s[x]+=s[l[x]];
    }
    if (x+1<=R)
    {
        r[x]=build(x+1,R,x);
        s[x]+=s[r[x]];
    }
    return(x);
}
void update(int x)
{
    if (rev[x])
    {
        rev[l[x]]=!rev[l[x]];
        rev[r[x]]=!rev[r[x]];
        swap(l[x],r[x]);
        rev[x]=false;
    }
}
int get(int x,int pos)
{
    update(x);
    if (pos==s[l[x]]+1)
        return(x);
    if (pos<=s[l[x]])
        return(get(l[x],pos));
    return(get(r[x],pos-s[l[x]]-1));
}
void left(int x)
{
    int p=f[x],t=l[x];
    if (root==p)
        root=x;
    else if (p==l[f[p]])
        l[f[p]]=x;
    else
        r[f[p]]=x;
    l[x]=p,r[p]=t;
    f[x]=f[p],f[p]=x,f[t]=p;
    s[p]=s[l[p]]+s[r[p]]+1;
    s[x]=s[l[x]]+s[r[x]]+1;
}
void right(int x)
{
    int p=f[x],t=r[x];
    if (root==p)
        root=x;
    else if (p==l[f[p]])
        l[f[p]]=x;
    else
        r[f[p]]=x;
    r[x]=p,l[p]=t;
    f[x]=f[p],f[p]=x,f[t]=p;
    s[p]=s[l[p]]+s[r[p]]+1;
    s[x]=s[l[x]]+s[r[x]]+1;
}
void splay(int x,int fa)
{
    while (f[x]!=fa)
    {
        int p=f[x];
        update(p);
        update(x);
        if (x==l[p])
            right(x);
        else
            left(x);
    }
}
int n;
void print(int x)
{
    if (x==0)
        return;
    update(x);
    print(l[x]);
    if (x>1 && x<n+2)
        printf("%d\n",x-1);
    print(r[x]);
}
int main()
{
    int Q;
    scanf("%d%d",&n,&Q);
    root=build(1,n+2,0);
    while (Q--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        L++,R++;
        L=get(root,L-1),R=get(root,R+1);
        splay(L,0);
        splay(R,L);
        int p=l[R];
        l[R]=0;
        s[R]-=s[p];
        s[L]-=s[p];
        int last=get(root,n+1-s[p]);
        splay(last,0);
        splay(n+2,last);
        l[n+2]=p;
        f[p]=n+2;
        s[n+2]+=s[p];
        s[last]+=s[p];
        rev[p]=!rev[p];
    }
    print(root);
    return(0);
}

