#include <cstdio>
struct point
{
    int x,y;
    point(int x,int y):x(x),y(y){}
};
int sqr(int x)
{
    return(x*x);
}
int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y));
}
bool check(const point &a,const point &b,const point &c)
{
    int A=dist(b,c),B=dist(a,c),C=dist(a,b);
    if (A==0 || B==0 || C==0)
        return(false);
    return(A+B==C || A+C==B || B+C==A);
}
int main()
{
    int ans=0,n=50;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=n;k++)
                for (int l=0;l<=n;l++)
                    ans+=check(point(0,0),point(i,j),point(k,l));
    printf("%d\n",ans/2);
    return(0);
}

