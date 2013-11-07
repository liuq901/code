/*
ID: liuq9011
LANG: C++
TASK: cowtour
*/
#include <cstdio>
#include <cmath>
#include <cstring>
FILE *in,*out;
double ans,a[160][160],b[160],c[160];
int n,x[160],y[160],s[160],f[160][160];
int main()
{
   in=fopen("cowtour.in","r");
   out=fopen("cowtour.out","w");
   void floodfill(int,int),count(),work(int,int);
   int i,j,k;
   char ch;
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d%d",&x[i],&y[i]);
   fscanf(in,"%*c");
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         a[i][j]=2000000;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
      {
         fscanf(in,"%c",&ch);
         f[i][j]=ch-'0';
         if (f[i][j])
            a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      }
      fscanf(in,"%*c");
   }
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         for (k=1;k<=n;k++)
            if (a[j][i]+a[i][k]<a[j][k])
               a[j][k]=a[j][i]+a[i][k];
   memset(s,0,sizeof(s));
   k=0;
   for (i=1;i<=n;i++)
      if (!s[i])
      {
         k++;
         floodfill(i,k);
      }
   count();
   ans=200000000;
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (s[i]!=s[j])
            work(i,j);
   fprintf(out,"%.6lf\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void floodfill(int t,int k)
{
   int i;
   s[t]=k;
   for (i=1;i<=n;i++)
      if (!s[i] && f[t][i])
         floodfill(i,k);
}
void count()
{
   int i,j;
   double t[160];
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (i!=j && s[i]==s[j] && a[i][j]>b[i])
            b[i]=a[i][j];
   memset(t,0,sizeof(t));
   for (i=1;i<=n;i++)
      if (b[i]>t[s[i]])
         t[s[i]]=b[i];
   for (i=1;i<=n;i++)
      c[i]=t[s[i]];
}
void work(int i,int j)
{
   double max,sum;
   sum=b[i]+b[j]+sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
   if (c[i]>c[j])
      max=c[i];
   else
      max=c[j];
   if (sum>max)
      max=sum;
   if (max<ans)
      ans=max;
}
