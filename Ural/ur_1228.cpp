#include <cstdio>
int d[20],K[20];
int main()
{
    int n,s;
    scanf("%d%d",&n,&d[0]);
    for (int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for (int i=n-1;i>=0;i--)
    {
        for (int j=i+2;j<=n;j++)
            d[i]/=K[j];
        K[i+1]=d[i];
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",K[i]-1,i==n?'\n':' ');
    return(0);
}

