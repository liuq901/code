/*
ID: liuq9011
LANG: C++
TASK: buylow
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int c[5001][260];
int main()
{
   in=fopen("buylow.in","r");
   out=fopen("buylow.out","w");
   int plus(int *,int *,int *);
   int n,i,j,max;
   int s[260],a[5001],f[5001],flag[26000];
   fscanf(in,"%d",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&a[i]);
   for (i=1;i<=n;i++)
   {
      f[i]=1;
      for (j=1;j<=i-1;j++)
         if (a[j]>a[i] && f[j]+1>f[i])
            f[i]=f[j]+1;
   }
   max=0;
   for (i=1;i<=n;i++)
      if (f[i]>max)
         max=f[i];
   fprintf(out,"%d ",max);
   memset(c,0,sizeof(c));
   for (i=1;i<=n;i++)
      if (f[i]==1)
      {
         c[i][0]=1;
         c[i][1]=1;
      }
      else
      {
         memset(flag,0,sizeof(flag));
         for (j=i-1;j>=1;j--)
            if (f[j]+1==f[i] && a[j]>a[i] && !flag[a[j]])
            {
               plus(c[i],c[j],c[i]);
               flag[a[j]]=1;
            }
      }
   memset(s,0,sizeof(s));
   memset(flag,0,sizeof(flag));
   for (i=n;i>=1;i--)
      if (f[i]==max && !flag[a[i]])
      {
         plus(s,c[i],s);
         flag[a[i]]=1;
      }
   for (i=s[0];i>=1;i--)
      fprintf(out,"%d",s[i]);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
void plus(int *a,int *b,int *c)
{
   int i,x,l;
   if (a[0]>b[0])
      c[0]=a[0];
   else
      c[0]=b[0];
   x=0;
   for (i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
}
