#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   n--;
   if (!n)
      printf("%d\n",1%m);
   else
   {
      int f[2][10001];
      f[1][1]=1;
      for (int i=2;i<=n;i++)
      {
         f[i&1][0]=0;
         for (int j=1;j<=n;j++)
         {
            f[i&1][j]=f[i&1][j-1];
            if (i>j)
               f[i&1][j]=(f[i&1][j]+f[1-(i&1)][i-j])%m;
         }
      }
      int ans=0;
      for (int i=1;i<=n;i++)
         ans=(ans+f[n&1][i])%m;
      printf("%d\n",ans*2%m);
   }
   system("pause");
   return(0);
}
