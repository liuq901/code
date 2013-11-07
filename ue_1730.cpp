#include <cstdio>
const int N=500010;
int n,a[N],c[N];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]^=value;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret^=c[i];
    return(ret);
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        modify(i,a[i]);
    }
    for (int i=1;i<=m;i++)
    {
        char op[10];
        scanf("%s",op);
        if (op[0]=='Q')
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(r)^query(l-1));
        }
        else
        {
            int pos,x;
            scanf("%d%d",&pos,&x);
            modify(pos,a[pos]);
            modify(pos,x);
            a[pos]=x;
        }
    }
    return(0);
}

