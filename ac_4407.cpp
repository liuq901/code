#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct point
{
   int x,y,p;
   point(){}
   point(int x,int y,int p=0):x(x),y(y),p(p){}
};
point operator -(point a,point b)
{
   return(point(a.x-b.x,a.y-b.y));
}
ll operator *(point a,point b)
{
   return(ll(a.x)*b.y-ll(a.y)*b.x);
}
int X[310],Y[310],p[310];
int main()
{
   void init(int);
   int work(int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&X[i],&Y[i],&p[i]);
      init(n);
      static int id=0;
      printf("Case %d: ",++id);
      printf("%d\n",work(n));
   }
   system("pause");
   return(0);
}
point p1[310],p2[310];
int b[310],a[60010][2];
void init(int n)
{
   ll cross(point,point,point),dist(point,point);
   int S,T,R;
   scanf("%d%d%d",&S,&T,&R);
   R*=R;
   int t1=0,t2=0;
   point P=point(X[S],Y[S]),Q=point(X[T],Y[T]);
   for (int i=1;i<=n;i++)
   {
      if (i==S || i==T || !p[i])
         continue;
      point tmp=point(X[i],Y[i],p[i]);
      if (cross(P,Q,tmp)<0)
         p1[++t1]=tmp;
      else
         p2[++t2]=tmp;
   }
   if (t1>t2)
   {
      for (int i=1;i<=t1;i++)
         swap(p1[i],p2[i]);
      swap(t1,t2);
   }
   memset(b,0,sizeof(b));
   int tot=0;
   for (int i=1;i<=t1;i++)
      for (int j=1;j<=t2;j++)
         if (p1[i].p>p2[j].p && dist(p1[i],p2[j])<=R)
            a[++tot][0]=j,a[tot][1]=b[i],b[i]=tot;
}
ll cross(point P,point Q,point O)
{
   return((O-P)*(O-Q));
}
ll dist(point P,point Q)
{
   return(ll(P.x-Q.x)*(P.x-Q.x)+ll(P.y-Q.y)*(P.y-Q.y));
}
int d[310];
bool f[310];
int work(int n)
{
   bool hungary(int);
   memset(d,0,sizeof(d));
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      ans+=hungary(i);
   }
   return(ans);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(d[y]))
      {
         d[y]=x;
         return(true);
      }
   }
   return(false);
}
