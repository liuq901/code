/*
ID: liuq9011
LANG: C++
TASK: fc
*/
#include <cstdio>
#include <cmath>
FILE *in,*out;
int n,a[10026];
double x[10001],y[10001],s[10001],d[10001];
int main()
{
   in=fopen("fc.in","r");
   out=fopen("fc.out","w");
   int i,k;
   double ans,minx,miny,tmp;
   double count(int,int,int);
   void build(),sort(int,int),work();
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%lf%lf",&x[i],&y[i]);
   minx=miny=20000000;
   for (i=1;i<=n;i++)
   {
      if (x[i]<minx)
      {
         minx=x[i];
         miny=y[i];
         k=i;
      }
      if (x[i]==minx && y[i]<miny)
      {
         miny=y[i];
         k=i;
      }
   }
   tmp=x[1],x[1]=x[k],x[k]=tmp;
   tmp=y[1],y[1]=y[k],y[k]=tmp;
   build();
   sort(2,n);
   work();
   ans=0;
   a[0]++;
   a[a[0]]=1;
   for (i=2;i<=a[0];i++)
      ans+=sqrt((x[a[i]]-x[a[i-1]])*(x[a[i]]-x[a[i-1]])+(y[a[i]]-y[a[i-1]])*(y[a[i]]-y[a[i-1]]));
   fprintf(out,"%.2lf\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void build()
{
   int i;
   for (i=2;i<=n;i++)
   {
      s[i]=sqrt((x[i]-x[1])*(x[i]-x[1])+(y[i]-y[1])*(y[i]-y[1]));
      if (x[i]==x[1])
         d[i]=M_PI/2;
      else
         d[i]=atan((y[i]-y[1])/(x[i]-x[1]));
   }
}
void sort(int l,int r)
{
   int i,j;
   double x0,y0,t;
   i=l;
   j=r;
   x0=d[(l+r)/2];
   y0=s[(l+r)/2];
   while (i<=j)
   {
      while (d[i]<x0 || (d[i]==x0 && s[i]<y0))
         i++;
      while (d[j]>x0 || (d[j]==x0 && s[j]>y0))
         j--;
      if (i<=j)
      {
         t=x[i],x[i]=x[j],x[j]=t;
         t=y[i],y[i]=y[j],y[j]=t;
         t=s[i],s[i]=s[j],s[j]=t;
         t=d[i],d[i]=d[j],d[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void work()
{
   double count(int,int,int);
   double x;
   int i,j;
   a[0]=2;
   a[1]=1;
   a[2]=2;
   for (i=3;i<=n;i++)
   {
      for (j=a[0];j>=2;j--)
      {
         if (count(a[j],a[j-1],i)<0)
            break;
         a[0]--;
      }
      a[0]++;
      a[a[0]]=i;
   }
}
double count(int p0,int p1,int p2)
{
   double x1,x2,y1,y2;
   x1=x[p1]-x[p0];
   y1=y[p1]-y[p0];
   x2=x[p2]-x[p0];
   y2=y[p2]-y[p0];
   return(x1*y2-x2*y1);
}
