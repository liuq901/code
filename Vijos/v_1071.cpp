#include <cstdio>
const int N=100010;
int a[110],pre[N],p[N],f[N];
void print(int x)
{
    if (pre[x]!=0)
    {
        print(pre[x]);
        printf(" ");
    }
    printf("%d",p[x]);
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    m=sum-m;
    f[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=m;j>=a[i];j--)
            if (f[j-a[i]])
            {
                f[j]+=f[j-a[i]];
                if (f[j]==1)
                {
                    pre[j]=j-a[i];
                    p[j]=i;
                }
            }
    if (f[m]==0)
        printf("0\n");
    else if (f[m]!=1)
        printf("-1\n");
    else
    {
        print(m);
        printf("\n");
    }
    return(0);
}

