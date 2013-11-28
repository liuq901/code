/*
ID: liuq9011
LANG: C++
TASK: sort3
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("sort3.in","r");
   out=fopen("sort3.out","w");
   int min(int,int);
   int i,j,t,n,ans;
   int a[1001],b[4],f[4][4];
   fscanf(in,"%d",&n);
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%d",&a[i]);
      b[a[i]]++;
   }
   memset(f,0,sizeof(f));
   for (i=1;i<=b[1];i++)
   {
      if (a[i]==2)
         f[1][2]++;
      if (a[i]==3)
         f[1][3]++;
   }
   for (i=b[1]+1;i<=b[1]+b[2];i++)
   {
      if (a[i]==1)
         f[2][1]++;
      if (a[i]==3)
         f[2][3]++;
   }
   for (i=b[1]+b[2]+1;i<=n;i++)
   {
      if (a[i]==1)
         f[3][1]++;
      if (a[i]==2)
         f[3][2]++;
   }
   ans=0;
   for (i=1;i<=2;i++)
      for (j=i+1;j<=3;j++)
      {
         t=min(f[i][j],f[j][i]);
         ans+=t;
         if (f[i][j]>=t)
            f[i][j]-=t;
         if (f[j][i]>=t)
            f[j][i]-=t;
      }
   ans+=(f[1][2]+f[1][3])*2;
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
