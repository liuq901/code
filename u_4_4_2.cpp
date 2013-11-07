/*
ID: liuq9011
LANG: C++
TASK: milk6
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,m,b[40],p[1001][2];
long long ans,max,a[40][40];
int main()
{
   in=fopen("milk6.in","r");
   out=fopen("milk6.out","w");
   void work(),print();
   int i,x,y;
   long long t,z;
   fscanf(in,"%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      fscanf(in,"%d%d%lld",&x,&y,&z);
      z=510000+i+510000*1001*z;
      a[x][y]+=z;
      p[i][0]=x;
      p[i][1]=y;
   }
   max=1;
   for (i=1;i<=60;i++)
      max*=2;
   work();
   t=ans%(510000*1001)/510000;
   fprintf(out,"%lld %lld\n",ans/(510000*1001),t);
   if (t!=0)
      print();
   fclose(in),fclose(out);
   return(0);
}
void work()
{
   int build();
   long long flow(int,long long);
   long long x;
   ans=0;
   while (1)
   {
      if (!build())
         break;
      while (1)
      {
         x=flow(1,max);
         if (x==0)
            break;
         ans+=x;
      }
   }
}
int build()
{
   int l,r,i;
   int f[100],q[100];
   memset(b,0,sizeof(b));
   memset(f,0,sizeof(f));
   l=r=1;
   b[1]=0;
   f[1]=1;
   q[1]=1;
   while (1)
   {
      for (i=1;i<=n;i++)
         if (!f[i] && a[q[l]][i]!=0)
         {
            r++;
            b[i]=b[q[l]]+1;
            f[i]=1;
            q[r]=i;
         }
      if (q[l]==n)
         return(1);
      l++;
      if (l>r)
         break;
   }
   return(0);
}
long long flow(int t,long long x)
{
   long long min(long long,long long);
   int i;
   long long y;
   if (t==n)
      return(x);
   for (i=1;i<=n;i++)
      if (a[t][i]>0 && b[t]+1==b[i])
      {
         y=flow(i,min(x,a[t][i]));
         a[t][i]-=y;
         a[i][t]+=y;
         if (y!=0)
            return(y);
      }
   return(0);
}
long long min(long long x,long long y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
void print()
{
   void floodfill(int);
   int i;
   memset(b,0,sizeof(b));
   b[1]=1;
   floodfill(1);
   for (i=1;i<=m;i++)
      if (b[p[i][0]] && !b[p[i][1]])
         fprintf(out,"%d\n",i);
}
void floodfill(int x)
{
   int i;
   for (i=1;i<=n;i++)
      if (a[x][i]!=0 && !b[i])
      {
         b[i]=1;
         floodfill(i);
      }
}
