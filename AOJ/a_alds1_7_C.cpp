#include <cstdio>
int l[25],r[25];
bool f[25];
void preorder(int x)
{
    if (x==-1)
        return;
    printf(" %d",x);
    preorder(l[x]);
    preorder(r[x]);
}
void inorder(int x)
{
    if (x==-1)
        return;
    inorder(l[x]);
    printf(" %d",x);
    inorder(r[x]);
}
void postorder(int x)
{
    if (x==-1)
        return;
    postorder(l[x]);
    postorder(r[x]);
    printf(" %d",x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int id;
        scanf("%d",&id);
        scanf("%d%d",&l[id],&r[id]);
        f[l[id]]=f[r[id]]=true;
    }
    int root;
    for (int i=0;i<n;i++)
        if (!f[i])
        {
            root=i;
            break;
        }
    printf("Preorder\n");
    preorder(root);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPostorder\n");
    postorder(root);
    printf("\n");
    return(0);
}

