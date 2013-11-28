#include <cstdio>
const int n=100;
int a[n+10],f[n+10][n+10];
bool flag[n+10];
int main()
{
    for (int i=2;i*i<=n;i++)
    {
        if (flag[i])
            continue;
        for (int j=i;i*j<=n;j++)
            flag[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!flag[i])
            a[++a[0]]=i;
    for (int i=2;i<=n;i++)
    {
        if (!flag[i])
            f[i][i]++;
        int sum=0;
        for (int j=1;j<=n;j++)
        {
            for (int k=1;k<=a[0];k++)
            {
                if (a[k]<j || i+a[k]>n)
                    continue;
                f[i+a[k]][a[k]]+=f[i][j];
            }
            sum+=f[i][j];
        }
        if (sum>=5000)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

