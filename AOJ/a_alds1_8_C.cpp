#include <cstdio>
int root,tot,l[500010],r[500010],fa[500010],v[500010];
void insert(int &x,int value,int father)
{
    if (x==0)
    {
        x=++tot;
        v[tot]=value;
        fa[tot]=father;
        return;
    }
    insert(value<v[x]?l[x]:r[x],value,x);
}
bool find(int x,int value)
{
    if (x==0)
        return(false);
    if (value==v[x])
        return(true);
    return(find(value<v[x]?l[x]:r[x],value));
}
int next(int x)
{
    if (r[x]!=0)
    {
        x=r[x];
        while (l[x]!=0)
            x=l[x];
        return(x);
    }
    int y=fa[x];
    while (y!=0 && x==r[y])
    {
        x=y;
        y=fa[y];
    }
    return(y);
}
void del(int z,int value)
{
    if (v[z]==value)
    {
        int x,y;
        if (l[z]==0 || r[z]==0)
            y=z;
        else
            y=next(z);
        if (l[y]!=0)
            x=l[y];
        else
            x=r[y];
        if (x!=0)
            fa[x]=fa[y];
        if (fa[y]==0)
            root=x;
        else if (y==l[fa[y]])
            l[fa[y]]=x;
        else
            r[fa[y]]=x;
        if (y!=z)
            v[z]=v[y];
        return;
    }
    del(value<v[z]?l[z]:r[z],value);
}
void inorder(int x)
{
    if (x==0)
        return;
    inorder(l[x]);
    printf(" %d",v[x]);
    inorder(r[x]);
}
void preorder(int x)
{
    if (x==0)
        return;
    printf(" %d",v[x]);
    preorder(l[x]);
    preorder(r[x]);
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[10];
        scanf("%s",op);
        if (op[0]=='i')
        {
            int x;
            scanf("%d",&x);
            insert(root,x,0);
        }
        else if (op[0]=='f')
        {
            int x;
            scanf("%d",&x);
            printf("%s\n",find(root,x)?"yes":"no");
        }
        else if (op[0]=='d')
        {
            int x;
            scanf("%d",&x);
            del(root,x);
        }
        else
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return(0);
}

