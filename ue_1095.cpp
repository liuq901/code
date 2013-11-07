#include <cstdio>
#include <algorithm>
using namespace std;
int p[260],a[510][510];
int SQR(int x)
{
    return(x*x);
}
void work(int n)  
{  
    int x=1,y=n+1>>1;  
    for (int i=1;i<=SQR(n);i++)  
    {  
        a[x][y]=i;  
        if (i%n)  
        {  
            x--,y++;  
            if (!x)  
                x=n;  
            if (y>n)  
                y=1;  
        }  
        else  
        {  
            x++;  
            if (x>n)  
                x=1;  
        }  
    }  
}
void set(int p,int q,int n)
{
    int tmp=SQR(n)+1;
    for (int i=1;i<=4;i++)
    {
        a[p-i+2][q+i]=tmp-a[p-i+2][q+i];
        a[p-3+i][q+i]=tmp-a[p-3+i][q+i];
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        if (n&1)
            work(n);
        else if (n&3)
        {
            int t=n>>1,s=SQR(t);
            work(t);
            for (int i=1;i<=t;i++)
                p[i]=0;
            p[(t-1>>1)+1]=1;
            int limit=n-2>>2;
            for (int i=1;i<=t;i++)
                for (int j=1;j<=t;j++)
                {
                    a[i][j+t]=a[i][j]+(s<<1);
                    a[i+t][j]=a[i][j]+s*3;
                    a[i+t][j+t]=a[i][j]+s;
                }
            for (int i=1;i<=t;i++)
                for (int j=1;j<=limit;j++)
                    swap(a[i][p[i]+j],a[i+t][p[i]+j]);
            for (int i=n;i>n-limit+1;i--)
                for (int j=1;j<=t;j++)
                    swap(a[j][i],a[j+t][i]);
        }
        else
        {
            int k=0;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=++k;
            int limit=n/4;
            for (int i=1;i<=limit;i++)
                for (int j=0;j<limit;j++)
                    set((i<<2)-1,j<<2,n);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
        if (T)
            printf("\n");
    }
    return(0);
}

