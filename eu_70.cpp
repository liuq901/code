#include <cstdio>
bool f[10000010];
int a[10000010],p[10000010];
bool check(int x,int y)
{
    int a[10]={0};
    while (x)
    {
        a[x%10]++;
        x/=10;
    }
    while (y)
    {
        a[y%10]--;
        y/=10;
    }
    for (int i=0;i<10;i++)
        if (a[i])
            return(false);
    return(true);
}
int main()
{
    for (int i=2;i*i<=10000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=10000000;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    a[1]=1;
    for (int i=2;i<=10000000;i++)
    {
        if (!f[i])
        {
            a[i]=i-1;
            continue;    
        }
        int x=i;
        while (x%p[i]==0)
            x/=p[i];
        if (x==1)
            a[i]=i/p[i]*(p[i]-1);
        else
            a[i]=a[x]*a[i/x];
    }
    double ans=1e10;
    int k;
    for (int i=2;i<10000000;i++)
        if (check(i,a[i]))
        {
            double x=double(i)/a[i];
            if (x<ans)
            {
                ans=x;
                k=i;
            }
        }
    printf("%d\n",k);
    return(0);
}

