#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int n,p[102][2];
double time[101][101],dist[1001][101];
int main()
{
   void init();
   bool work(double);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=0;i<=n+1;i++)
         scanf("%d%d",&p[i][0],&p[i][1]);
      init();
      for (int i=1;i<=n;i++)
      {
         int c,w,s;
         scanf("%d%d%d",&c,&w,&s);
         for (int j=1;j<=n;j++)
         {
            time[i][j]=1e10;
            for (int k=0;k<=p[n+1][0];k++)
            {
               double t=abs(k-s)/double(w)+dist[k][j]/c;
               if (t<time[i][j])
                  time[i][j]=t;
            }
         }
      }
      double l=0,r=1e5,ans;
      while (r-l>1e-5)
      {
         double mid=(l+r)/2;
         if (work(mid))
         {
            ans=mid;
            r=mid;
         }
         else
            l=mid;
      }
      printf("%.2lf\n",ans);
   }
   system("pause");
   return(0);
}
void init()
{
   bool check(int,int);
   for (int i=0;i<=p[n+1][0];i++)
      for (int j=1;j<=n;j++)
      {
         if (!check(i,j))
         {
            dist[i][j]=1e10;
            continue;
         }
         dist[i][j]=sqrt(double((p[j][0]-i)*(p[j][0]-i)+p[j][1]*p[j][1]));
      }
}
bool check(int pos,int id)
{
   int x1,y1,x2,y2;
   if (pos==p[id][0])
      return(true);
   x1=p[id][0]-pos;
   y1=p[id][1];
   if (pos<p[id][0])
   {
      for (int i=id-1;i>=0;i--)
      {
         if (p[i][0]<pos)
            break;
         x2=p[i][0]-pos;
         y2=p[i][1];
         if (x1*y2-x2*y1<0)
            return(false);
      }
      return(true);
   }
   else
   {
      for (int i=id+1;i<=n+1;i++)
      {
         if (p[i][0]>pos)
            break;
         x2=p[i][0]-pos;
         y2=p[i][1];
         if (x1*y2-x2*y1>0)
            return(false);
      }
      return(true);
   }
}
int b[101],a[101][101];
bool f[101];
bool work(double mid)
{
   bool hungary(int);
   for (int i=1;i<=n;i++)
   {
      a[i][0]=0;
      for (int j=1;j<=n;j++)
      {
         if (time[i][j]>mid)
            continue;
         a[i][++a[i][0]]=j;
      }
   }
   memset(b,0,sizeof(b));
   for (int i=1;i<=n;i++)
   {
      memset(f,0,sizeof(f));
      if (!hungary(i))
         return(false);
   }
   return(true);
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=1;i<=a[x][0];i++)
   {
      int t=a[x][i];
      if (f[t])
         continue;
      f[t]=true;
      if (hungary(b[t]))
      {
         b[t]=x;
         return(true);
      }
   }
   return(false);
}
