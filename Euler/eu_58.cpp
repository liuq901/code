#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int x,y,z;
bool prime(int n)
{
    if (n==1)
        return(false);
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return(false);
    return(true);
}
int work(int len)
{
    int n=len<<1;
    static int sum=0;
    x++,y++;
    for (int i=0;i<4;i++)
        for (int j=1;j<=n;j++)
        {
            x+=c[i][0],y+=c[i][1],z++;
            if (abs(x)==len && abs(y)==len)
                sum+=prime(z);
        }
    return(sum);
}
int main()
{
    z=1;
    for (int i=1;;i++)
    {
        int sum=work(i),n=2*i+1;
        if (sum*10<(2*n-1))
        {
            printf("%d\n",n);
            break;
        }
    }
    return(0);
}

