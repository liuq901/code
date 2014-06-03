#include <cstdio>
#include <cmath>
int calc(int pos,int n)
{
    return(pos*(n-pos+1)*2-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int X,Y,Z,n;
        scanf("%d%d%d%d",&X,&Y,&Z,&n);
        double ans=0,tot=double(X)*X*Y*Y*Z*Z;
        for (int i=1;i<=X;i++)
            for (int j=1;j<=Y;j++)
                for (int k=1;k<=Z;k++)
                {
                    double p=double(calc(i,X))*calc(j,Y)*calc(k,Z)/tot;
                    ans+=(p-0.5)*pow(1-2*p,double(n-1))+0.5;
                }
        static int id=0;
        printf("Case %d: %.10f\n",++id,fabs(ans));
    }
    return(0);
}

