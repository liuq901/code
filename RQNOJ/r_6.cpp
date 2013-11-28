#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[61][3][3],b[61],f[61][3326];
int main()
{
   int i,j,k,n,m,x,y,z,s1,s2,s3,s4,s5,max;
   scanf("%d%d",&n,&m);
   n/=10;
   for (i=1;i<=60;i++)
      for (j=0;j<2;j++)
         for (k=0;k<2;k++)
            a[i][j][k]=0;
   for (i=1;i<=m;i++)
      b[i]=1;
   for (i=1;i<=m;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      x/=10;
      if (z==0)
      {
         a[i][0][0]=x;
         a[i][0][1]=y;
         a[i][0][2]=x*y;
      }
      else
      {
         a[z][b[z]][0]=x;
         a[z][b[z]][1]=y;
         a[z][b[z]][2]=x*y;
         b[z]++;
      }
   }
   memset(f,0,sizeof(f));
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
      {
         s1=s2=s3=s4=0;
         if (j-a[i][0][0]>=0)
            s1=f[i-1][j-a[i][0][0]]+a[i][0][2];
         if (j-a[i][0][0]-a[i][1][0]>=0)
            s2=f[i-1][j-a[i][0][0]-a[i][1][0]]+a[i][0][2]+a[i][1][2];
         if (j-a[i][0][0]-a[i][2][0]>=0)
            s3=f[i-1][j-a[i][0][0]-a[i][2][0]]+a[i][0][2]+a[i][2][2];
         if (j-a[i][0][0]-a[i][1][0]-a[i][2][0]>=0)
            s4=f[i-1][j-a[i][0][0]-a[i][1][0]-a[i][2][0]]+a[i][0][2]+a[i][1][2]+a[i][2][2];
         s5=f[i-1][j];
         max=s1;
         if (s2>max)
            max=s2;
         if (s3>max)
            max=s3;
         if (s4>max)
            max=s4;
         if (s5>max)
            max=s5;
         f[i][j]=max;
      }
   printf("%d\n",f[m][n]*10);
   system("pause");
   return(0);
}
