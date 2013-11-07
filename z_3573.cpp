#include <cstdio>
int n,c[15010];
void add(int x,int y)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]+=y;
}
int get(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int main()
{
    while (scanf("%d",&n)==1)
    {
        n++;
        for (int i=1;i<=n;i++)
            c[i]=0;
        while (1)
        {
            int l,r,v;
            scanf("%d%d%d",&l,&r,&v);
            if (l==-1)
                break;
            l++,r++;
            add(l,v);
            add(r+1,-v);
        }
        int p,q;
        p=q=-1;
        for (int i=1;i<=n;i++)
            if (p==-1 || get(i)>get(p))
                p=i;
        for (int i=n;i;i--)
            if (q==-1 || get(i)>get(q))
                q=i;
        printf("%d %d\n",p-1,q-1);
    }
    return(0);
}

