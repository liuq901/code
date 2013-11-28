#include <cstdio>
#include <cstdlib>
int f[100001],pre[100001];
int main()
{
   int t;
   scanf("%d",&t);
   for (int id=1;id<=t;id++)
   {
      f[0]=-1<<30;
      int ans=0,n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (f[i-1]>=0)
         {
            f[i]=f[i-1]+x;
            pre[i]=pre[i-1];
         }
         else
         {
            f[i]=x;
            pre[i]=i;
         }
         if (f[i]>f[ans])
            ans=i;
      }
      printf("Case %d:\n%d %d %d\n",id,f[ans],pre[ans],ans);
      if (id!=t)
         printf("\n");
   }
   system("pause");
   return(0);
}
