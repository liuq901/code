#include <cstdio>
int main()
{
    int ans=0,m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    for (int i=k;i<=10000;i++)
    {
        int t0=0,t1=0;
        for (int j=1;j*j<=i;j++)
            if (i%j==0)
                t0++;
        for (int j=1;j*j<=i-k;j++)
            if ((i-k)%j==0)
                t1++;
        if (t0==n && t1==m)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return(0);
}

