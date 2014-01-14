#include <cstdio>
int tot,l[500010],r[500010],v[500010];
void insert(int &x,int value)
{
    if (x==0)
    {
        x=++tot;
        v[tot]=value;
        return;
    }
    insert(value<v[x]?l[x]:r[x],value);
}
bool find(int x,int value)
{
    if (x==0)
        return(false);
    if (value==v[x])
        return(true);
    return(find(value<v[x]?l[x]:r[x],value));
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
    int root=0,Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[10];
        scanf("%s",op);
        if (op[0]=='i')
        {
            int x;
            scanf("%d",&x);
            insert(root,x);
        }
        else if (op[0]=='f')
        {
            int x;
            scanf("%d",&x);
            printf("%s\n",find(root,x)?"yes":"no");
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

