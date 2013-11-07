/*
ID: liuq9011
LANG: C++
TASK: cowxor
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int a[100001],f[100001];
char b[9000000];
int main()
{
   in=fopen("cowxor.in","r");
   out=fopen("cowxor.out","w");
   void build(int,int);
   int n,i,j,x,y,t,ans,k;
   int c[30];
   fscanf(in,"%d",&n);
   f[0]=0;
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d",&a[i]);
      f[i]=a[i]^f[i-1];
   }
   memset(b,0,sizeof(b));
   t=1;
   for (i=1;i<=21;i++)
   {
      t*=2;
      b[t]=1;
   }
   ans=-1;
   for (i=1;i<=n;i++)
   {
      x=f[i];
      for (j=21;j>=1;j--)
      {
         c[j]=x%2;
         x/=2;
      }
      y=0;
      t=1;
      for (j=1;j<=21;j++)
      {
         if (c[j]==0)
         {
            if (b[2*t+1])
            {
               t=2*t+1;
               y=2*y+1;
               continue;
            }
            t*=2;
            y*=2;
            continue;
         }
         if (b[2*t])
         {
            t*=2;
            y=2*y+1;
            continue;
         }
         t=2*t+1;            
         y*=2;
      }
      t=1;
      for (j=1;j<=21;j++)
      {
         if (c[j]==0)
            t*=2;
         else
            t=2*t+1;
         b[t]=1;
      }
      if (y>ans)
      {
         ans=y;
         k=i;
      }
   }
   x=0;
   for (i=k;i>=1;i--)
   {
      x^=a[i];
      if (x==ans)
      {
         t=i;
         break;
      }
   }
   fprintf(out,"%d %d %d\n",ans,t,k);
   fclose(in),fclose(out);
   return(0);
}
