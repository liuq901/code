#include <cstdio>
#include <algorithm>
using namespace std;
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
inline int operator *(const point &a,const point &b)
{
    return(a.x*b.y-a.y*b.x);
}
inline bool cmp(const point &a,const point &b)
{
    return(a.y<b.y || a.y==b.y && a.x<b.x);
}
inline double sqr(double x)
{
    return(x*x);
}
inline int dist(const point &a,const point &b)
{
    return(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point pp[100000],conv[100000];
int totco;
void convex(point *p,int n)
{
    sort(p,p+n,cmp);
    conv[0]=p[0],conv[1]=p[1],totco=2;
    for (int i=2;i<n;i++)
    {
        while (totco>1 && (conv[totco-1]-conv[totco-2])*(p[i]-conv[totco-2])<=0)
            totco--;
        conv[totco++]=p[i];
    }
    int limit=totco;
    for (int i=n-1;i>=0;i--)
    {
        while (totco>limit && (conv[totco-1]-conv[totco-2])*(p[i]-conv[totco-2])<=0)
            totco--;
        conv[totco++]=p[i];
    }
}    
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d%d",&pp[i].x,&pp[i].y);
    convex(pp,n);
    n=totco;
    for (int i=0;i<n;i++)
        pp[i]=conv[i];
    n--;
    int ans=0;
    for (int i=0;i<n;i++)
        pp[n+i]=pp[i];
    int now=1;
    for (int i=0;i<n;i++)
    {
        point tt=pp[i+1]-pp[i];
        while (now<2*n-2 && tt*(pp[now+1]-pp[now])>0)
            now++;
        if (dist(pp[i],pp[now])>ans)
            ans=dist(pp[i],pp[now]);
        if (dist(pp[i+1],pp[now])>ans)
            ans=dist(pp[i+1],pp[now]);
    }
    printf("%d\n",ans);
    return(0);
}

