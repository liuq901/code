#include <cstdio>
int a[110];
bool f[110][10010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int m=0,sum=0;
        while (1)
        {
            int x;
            scanf("%d",&x);
            if (x==-1)
                break;
            a[++m]=x;
            sum+=x;
        }
        f[i][0]=true;
        for (int j=1;j<=m;j++)
            for (int k=sum;k>=a[j];k--)
                if (f[i][k-a[j]])
                    f[i][k]=true;
    }
    for (int i=10000;i>=0;i--)
    {
        bool flag=true;
        for (int j=1;j<=n;j++)
            if (!f[j][i])
            {
                flag=false;
                break;
            }
        if (flag)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

