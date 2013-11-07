#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
const double eps=1e-7;
struct point
{
   double x,y;
   point(){}
   point(double x,double y):x(x),y(y){}
};
point operator -(const point &a,const point &b)
{
   return(point(a.x-b.x,a.y-b.y));
}
double operator *(const point &a,const point &b)
{
   return(a.x*b.y-a.y*b.x);
}
int m[510],dep[510],pos[510],f[510];
point p[510][1010];
double area[510];
int main()
{
   bool cmp(int,int),in(int,int);
   double dist(const point &,const point &);
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&m[i]);
         for (int j=1;j<=m[i];j++)
         {
            double x,y;
            scanf("%lf%lf",&x,&y);
            p[i][j]=point(x,y);
         }
         p[i][0]=p[i][m[i]];
         area[i]=0;
         for (int j=1;j<=m[i];j++)
            area[i]+=p[i][j]*p[i][j-1];
         if (area[i]<0)
            area[i]*=-1;
         pos[i]=i;
      }
      sort(pos+1,pos+n+1,cmp);
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<i;j++)
         {
            if (f[pos[j]])
               continue;
            if (in(pos[j],pos[i]))
               f[pos[j]]=pos[i];
         }
      }
      int ans=0;
      for (int i=n;i;i--)
      {
         int x=pos[i];
         if (!f[x])
            ans++;
         dep[x]=dep[f[x]]+1;
      }
      double steel=0,wooden=0;
      for (int i=1;i<=n;i++)
      {
         double len=0;
         for (int j=1;j<=m[i];j++)
            len+=dist(p[i][j],p[i][j-1]);
         if (dep[i]&1)
            steel+=len;
         else
            wooden+=len;
      }
      steel/=10000,wooden/=20000;
      static int id=0;
      printf("Case %d:\n",++id);
      printf("Total Number of Communities %d\n",ans);
      printf("Total Cost:\n");
      printf("Steel Fence: %.8f Million Yuan\n",steel);
      printf("Wooden Fence: %.8f Million Yuan\n",wooden);
      printf("\n");
   }
   system("pause");
   return(0);
}
bool cmp(int x,int y)
{
   return(area[x]<area[y]);
}
bool in(int x,int y)
{
   point P=p[x][1];
   for (int i=1;i<=m[y];i++)
      if ((P-p[y][i])*(p[y][i-1]-p[y][i])<eps)
         return(false);
   return(true);
}
double dist(const point &a,const point &b)
{
   return(sqrt(double(SQR(a.x-b.x)+SQR(a.y-b.y))));
}
