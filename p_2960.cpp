#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int k;
      scanf("%d",&k);
      if (k==0)
         break;
      int a[101];
      for (int i=1;i<=k;i++)
         scanf("%d",&a[i]);
      int f[10001];
      f[0]=0;
      for (int i=1;i<=10000;i++)
      {
         bool g[10001]={0};
         for (int j=1;j<=k;j++)
            if (i-a[j]>=0)
               g[f[i-a[j]]]=true;
         f[i]=0;
         while (g[f[i]])
            f[i]++;
      }
      int m;
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
      {
         int n;
         scanf("%d",&n);
         int s=0;
         for (int j=1;j<=n;j++)
         {
            int x;
            scanf("%d",&x);
            s^=f[x];
         }
         if (s!=0)
            printf("W");
         else
            printf("L");
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
