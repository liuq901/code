#include <cstdio>
void gcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1,y=0;
        return;
    }
    gcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int x,y;
    gcd(a,b,x,y);
    printf("%d %d\n",x,y);
    return(0);
}

