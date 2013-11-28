#include <cstdio>
#include <cstdlib>
int main()
{
    int n=100,m=100,ans,delta=1<<30,value=2000000;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int now=0;
            for (int k=1;k<=i;k++)
                for (int l=1;l<=j;l++)
                    now+=k*l;
            int x=abs(value-now);
            if (x<delta)
            {
                delta=x;
                ans=i*j;
            }
        }
    printf("%d\n",ans);
    return(0);
}

