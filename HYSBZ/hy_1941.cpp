#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf=1<<30;
struct point
{
   int x,y,min,max;
};
point a[500001];
int n,p[500001],c[500001],d[500001];
int main()
{
   bool com0(point,point),com1(point,point);
   int find(int),get(int),count(int);
   void insert(int,int);
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i].x,&a[i].y);
      a[i].min=inf;
      a[i].max=-inf;
      p[i]=a[i].y;
   }
   sort(p+1,p+n+1);
   sort(a+1,a+n+1,com0);
   memset(c,26,sizeof(c));
   memset(d,-26,sizeof(d));
   for (int i=1;i<=n;i++)
   {
      int pos=n-find(a[i].y)+1;
      a[i].max=max(a[i].max,a[i].x-a[i].y-get(pos));
      a[i].min=min(a[i].min,a[i].x-a[i].y-count(pos));
      insert(pos,a[i].x-a[i].y);
   }
   memset(c,26,sizeof(c));
   memset(d,-26,sizeof(d));
   for (int i=n;i>=1;i--)
   {
      int pos=find(a[i].y);
      a[i].max=max(a[i].max,count(pos)-a[i].x+a[i].y);
      a[i].min=min(a[i].min,get(pos)-a[i].x+a[i].y);
      insert(pos,a[i].x-a[i].y);
   }
   sort(a+1,a+n+1,com1);
   memset(c,26,sizeof(c));
   memset(d,-26,sizeof(d));
   for (int i=1;i<=n;i++)
   {
      int pos=find(a[i].y);
      a[i].max=max(a[i].max,a[i].x+a[i].y-get(pos));
      a[i].min=min(a[i].min,a[i].x+a[i].y-count(pos));
      insert(pos,a[i].x+a[i].y);
   }
   memset(c,26,sizeof(c));
   memset(d,-26,sizeof(d));
   for (int i=n;i>=1;i--)
   {
      int pos=n-find(a[i].y)+1;
      a[i].max=max(a[i].max,count(pos)-a[i].x-a[i].y);
      a[i].min=min(a[i].min,get(pos)-a[i].x-a[i].y);
      insert(pos,a[i].x+a[i].y);
   }
   int ans=inf;
   for (int i=1;i<=n;i++)
      ans=min(ans,a[i].max-a[i].min);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool com0(point a,point b)
{
   if (a.x!=b.x)
      return(a.x<b.x);
   return(a.y>b.y);
}
bool com1(point a,point b)
{
   if (a.x!=b.x)
      return(a.x<b.x);
   return(a.y<b.y);
}
int find(int x)
{
   int l=1,r=n;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (p[mid]==x)
         return(mid);
      if (p[mid]<x)
         l=mid+1;
      else
         r=mid-1;
   }
}
int get(int x)
{
   int ans=inf;
   for (int i=x;i;i-=i&-i)
      ans=min(ans,c[i]);
   return(ans);
}
int count(int x)
{
   int ans=-inf;
   for (int i=x;i;i-=i&-i)
      ans=max(ans,d[i]);
   return(ans);
}
void insert(int x,int v)
{
   for (int i=x;i<=n;i+=i&-i)
   {
      c[i]=min(c[i],v);
      d[i]=max(d[i],v);
   }
}
