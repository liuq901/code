#include <cstdio>
#include <cstring>
double a[1010],b[1010],c[1010];
int main()
{
    int n,m,x0,y0;
    scanf("%d%d%d%d",&n,&m,&x0,&y0);
    if (m==1)
        printf("%.10f\n",(n-x0)*2.0);
    else
    {
        for (int i=x0;i<n;i++)
        {
            memset(b,0,sizeof(b));
            for (int T=1;T<=100;T++)
            {
                for (int j=2;j<m;j++)
                    c[j]=(b[j]+b[j-1]+b[j+1]+a[j])/4+1;
                c[1]=(b[1]+b[2]+a[1])/3+1;
                c[m]=(b[m-1]+b[m]+a[m])/3+1;
                memcpy(b,c,sizeof(c));
            }
            memcpy(a,b,sizeof(b));
        }
        printf("%.10f\n",a[y0]);
    }
    return(0);
}

