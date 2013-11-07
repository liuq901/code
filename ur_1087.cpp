#include <cstdio>
#include <cstdlib>
bool f[10001]={0};
int main()
{
   int n,m,a[51];
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
      scanf("%d",&a[i]);
   f[0]=true;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (i>=a[j] && !f[i-a[j]])
         {
            f[i]=true;
            break;
         }
   printf("%d\n",f[n]?1:2);
   system("pause");
   return(0);
}
