#include <cstdio>
struct point
{
        int x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline point operator -(const point &a,const point &b)
{
    return(point(a.x-b.x,a.y-b.y));
}
inline int det(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
point a[110],b[110];
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
    {
        a[i].in(),b[i].in();
        for (int j=1;j<i;j++)
            if (det(a[i]-a[j],b[i]-a[j])==0 && det(a[i]-b[j],b[i]-b[j])==0)
            {
                n--,i--;
                break;
            }
    }
    bool flag=true;
    for (int i=2;i<=n;i++)
        if (det(a[i]-b[i],a[1]-b[1])!=0)
        {
            flag=false;
            break;
        }
    int now,next;
    if (flag)
        now=n+1,next=2*now;
    else
        now=2*n,next=2*n+2;
    if (m<=now)
        printf("0\n");
    else if (m<=next)
        printf("1\n");
    else
        printf("%d\n",(m+1)/2-n);
    return(0);
}

