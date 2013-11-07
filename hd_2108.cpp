#include <cstdio>
struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int sign(int x)
{
    return(x<0?-1:x>0);
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point a[10010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        a[0]=a[n],a[n+1]=a[1];
        bool flag=true;
        for (int i=1;i<=n;i++)
            if (sign(det(a[i]-a[i-1],a[i+1]-a[i]))==-1)
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"convex":"concave");
    }
    return(0);
}

