#include <cstdio>
#include <cstdlib>
#include <cstring>
const double eps=1e-8;
double f[110][110][20];
int a[10],b[10];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int state=0,m=0;
      for (int i=1;i<=5;i++)
      {
         scanf("%d",&a[i]);
         if (i<5)
         {
            if (a[i]>=2)
               m+=a[i]-1;
            if (a[i])
               state+=1<<i-1;
         }
      }
      int n=0,tot=m;
      for (int i=1;i<=5;i++)
      {
         scanf("%d",&b[i]);
         n+=b[i];
         if (i<5)
            tot+=b[i];
      }
      memset(f,0,sizeof(f));
      f[0][m][state]=1;
      double ans=0;
      for (int i=0;i<=n;i++)
         for (int j=i+1>>1;j<=tot;j++)
            for (int k=0;k<16;k++)
            {
               if (f[i][j][k]<eps)
                  continue;
               if (i==n || i==j<<1)
               {
                  ans+=i*f[i][j][k];
                  continue;
               }
               int equip=-j,rest=n-i;
               double sum=n-i;
               for (int l=1;l<=4;l++)
                  if (k>>l-1&1)
                     equip+=a[l]+b[l]-1;
                  else
                  {
                     rest-=b[l];
                     f[i+1][j][k+(1<<l-1)]+=f[i][j][k]*b[l]/sum;
                  }
               f[i+1][j][k]+=f[i][j][k]*(rest-equip)/sum;
               f[i+1][j+1][k]+=f[i][j][k]*equip/sum;
            }
      static int id=0;
      printf("Case %d: %.2f\n",++id,ans);
   }
   system("pause");
   return(0);
}
