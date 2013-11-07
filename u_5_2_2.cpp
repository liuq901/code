/*
ID: liuq9011
LANG: C++
TASK: fence3
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
FILE *in,*out;
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct line
{
   int x1,y1,x2,y2;
};
struct line a[151];
int n;
int main()
{
   in=fopen("fence3.in","r");
   out=fopen("fence3.out","w");
   double count(int,int); 
   int i,j,x0,y0,p,q,t;
   double ans,s;
   fscanf(in,"%d",&n);
   a[0].x1=a[0].y1=20000000;
   a[0].x2=a[0].y2=0;
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
      a[i].x1*=10,a[i].y1*=10,a[i].x2*=10,a[i].y2*=10;
      if (a[i].x1==a[i].x2 && a[i].y1>a[i].y2)
         t=a[i].y1,a[i].y1=a[i].y2,a[i].y2=t;
      if (a[i].x1>a[i].x2 && a[i].y1==a[i].y2)
         t=a[i].x1,a[i].x1=a[i].x2,a[i].x2=t;
      if (a[i].x1<a[0].x1)
         a[0].x1=a[i].x1;
      if (a[i].y1<a[0].y1)
         a[0].y1=a[i].y1;
      if (a[i].x2>a[0].x2)
         a[0].x2=a[i].x2;
      if (a[i].y2>a[0].y2)
         a[0].y2=a[i].x1;
   }
   srand(n);
   x0=rand()%(a[0].x2-a[0].x1+1)+a[0].x1;
   y0=rand()%(a[0].y2-a[0].y1+1)+a[0].y1;
   ans=count(x0,y0);
   for (i=30;i>=1;i--)
      for (j=1;j<=500;j++)
      {
         p=rand()%4;
         q=rand()%i+1;
         s=count(x0+q*c[p][0],y0+q*c[p][1]);
         if (s<ans)
         {
            ans=s;
            x0+=q*c[p][0];
            y0+=q*c[p][1];
         }
      }
   fprintf(out,"%.1lf %.1lf %.1lf\n",(double)x0/10.0,(double)y0/10.0,ans/10.0);
   fclose(in),fclose(out);
   return(0);
}
double count(int x,int y)
{
   int i;
   double s,t;
   s=0;
   for (i=1;i<=n;i++)
   {
      if (a[i].x1==a[i].x2)
      {
         if (y>=a[i].y1 && y<=a[i].y2)
            t=fabs(a[i].x1-x);
         if (y<a[i].y1)
            t=sqrt((a[i].x1-x)*(a[i].x1-x)+(a[i].y1-y)*(a[i].y1-y));
         if (y>a[i].y2)
            t=sqrt((a[i].x2-x)*(a[i].x2-x)+(a[i].y2-y)*(a[i].y2-y));
         s+=t;
      }
      if (a[i].x1!=a[i].x2 && a[i].y1==a[i].y2)
      {
         if (x>=a[i].x1 && x<=a[i].x2)
            t=fabs(a[i].y1-y);
         if (x<a[i].x1)
            t=sqrt((a[i].x1-x)*(a[i].x1-x)+(a[i].y1-y)*(a[i].y1-y));
         if (x>a[i].x2)
            t=sqrt((a[i].x2-x)*(a[i].x2-x)+(a[i].y2-y)*(a[i].y2-y));
         s+=t;
      }
   }
   return(s);
}
