/*
ID: liuq9011
LANG: C++
TASK: job
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("job.in","r");
   out=fopen("job.out","w");
   int n,m1,m2,i,j,k,t,min,max;
   int a[31],b[31],d[31],p[1001],q[1001];
   fscanf(in,"%d%d%d",&n,&m1,&m2);
   for (i=1;i<=m1;i++)
      fscanf(in,"%d",&a[i]);
   for (i=1;i<=m2;i++)
      fscanf(in,"%d",&b[i]);
   memset(d,0,sizeof(d));
   for (i=1;i<=n;i++)
   {
      min=20000000;
      for (j=1;j<=m1;j++)
         if (a[j]+d[j]<min)
         {
            min=a[j]+d[j];
            k=j;
         }
      d[k]+=a[k];
      p[i]=d[k];
   }
   memset(d,0,sizeof(d));
   for (i=1;i<=n;i++)
   {
      min=20000000;
      for (j=1;j<=m2;j++)
         if (b[j]+d[j]<min)
         {
            min=b[j]+d[j];
            k=j;
         }
      d[k]+=b[k];
      q[i]=d[k];
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
      {
         if (p[i]>p[j])
            t=p[i],p[i]=p[j],p[j]=t;
         if (q[i]>q[j])
            t=q[i],q[i]=q[j],q[j]=t;
      }
   fprintf(out,"%d ",p[n]);
   max=0;
   for (i=1;i<=n;i++)
      if (p[i]+q[n-i+1]>max)
         max=p[i]+q[n-i+1];
   fprintf(out,"%d\n",max);
   fclose(in),fclose(out);
   return(0);
}
