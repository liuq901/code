#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50;
struct point
{
   int x,y;
   point(){}
   point(int x,int y):x(x),y(y){};
};
point q[maxn*maxn*5];
int fx[20],fy[20],len[30000],num[30000][100],dist[maxn*2+10][maxn*2+10];
int main()
{
   int &D(int,int),gcd(int,int);
   bool inside(int,int);
   void print(int);
   for (int i=1;i<=20000;i++)
   {
      len[i]=0;
      for (int j=1;j*j<=i;j++)
         if (!(i%j))
         {
            num[i][len[i]++]=j;
            if (j*j!=i)
               num[i][len[i]++]=i/j;
         }
      sort(num[i],num[i]+len[i]);
   }
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int sx,sy,ex,ey;
      scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
      ex-=sx,ey-=sy;
      int m;
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
         scanf("%d%d",&fx[i],&fy[i]);
      int l,r;
      l=r=1;
      q[1]=point(0,0);
      memset(dist,-1,sizeof(dist));
      D(0,0)=0;
      while (l<=r)
      {
         int x=q[l].x,y=q[l++].y,d=D(x,y);
         for (int i=1;i<=m;i++)
         {
            int nx=x+fx[i],ny=y+fy[i];
            if (inside(nx,ny) && D(nx,ny)==-1)
            {
               D(nx,ny)=d+1;
               q[++r]=point(nx,ny);
            }
         }
      }
      if (inside(ex,ey))
      {
         print(D(ex,ey));
         continue;
      }
      int ans=-1;
      for (int x=-maxn;x<=maxn;x++)
         for (int y=-maxn;y<=maxn;y++)
            if (D(-x,-y)>=0)
            {
               int nx=x+ex,ny=y+ey,p=gcd(abs(nx),abs(ny));
               if (!inside(nx/p,ny/p))
                  continue;
               int o,tmp=maxn/(max(abs(nx),abs(ny))/p);
               o=tmp?*(upper_bound(num[p],num[p]+len[p],tmp)-1):1;
               if (D(nx/p*o,ny/p*o)==-1)
                  continue;
               int nans=D(nx/p*o,ny/p*o)*(p/o)+D(-x,-y);
               if (ans==-1 || ans>nans)
                  ans=nans;
            }
      print(ans);
   }
   system("pause");
   return(0);
}
int &D(int x,int y)
{
   return(dist[x+maxn][y+maxn]);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
bool inside(int x,int y)
{
   return(x>=-maxn && x<=maxn && y>=-maxn && y<=maxn);
}
void print(int x)
{
   if (x<0)
      printf("IMPOSSIBLE\n");
   else
      printf("%d\n",x);
}
