#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int a[201][201],b[201];
   int x,i,j,k,n,ans,flag;
   memset(a,0,sizeof(a));
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      while (1)
      {
         scanf("%d",&x);
         if (x==0)
            break;
         else
            a[i][x]=1;
      }
   flag=1;
   while (flag)
   {
      flag=0;
      for (i=1;i<=n;i++)
         for (j=1;j<=n;j++)
            for (k=1;k<=n;k++)
               if (a[i][j] && a[j][k] && !a[i][k])
               {
                  a[i][k]=1;
                  flag=1;
               }
   }
   memset(b,0,sizeof(b));
   ans=0;
   for (i=1;i<=n;i++)
   {
      if (b[i])
         continue;
      for (j=1;j<=n;j++)
         if (a[i][j] && a[j][i])
            b[j]=1;
      ans++;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
