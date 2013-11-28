#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[100010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int k,m;
         scanf("%d%d",&k,&m);
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            a[x]=k;
         }
      }
      int p;
      scanf("%d",&p);
      printf("%d\n",a[p]);
   }
   system("pause");
   return(0);
}
