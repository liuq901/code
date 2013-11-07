#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[501],ans[501];
int main()
{
   void search(int);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      if (n==1)
      {
         printf("1\n");
         continue;
      }
      a[1]=1;
      a[0]=20000000;
      search(2);
      for (int i=1;i<=a[0]-1;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[a[0]]);
   }
   system("pause");
   return(0);
}
void search(int dep)
{
   if (dep>=a[0])
      return;
   for (int i=dep-1;i>=1;i--)
      for (int j=i;j>=1;j--)
      {
         int x=a[i]+a[j];
         if (x<=a[dep-1])
            break;
         if (x>n)
            continue;
         a[dep]=x;
         if (x==n)
         {
            a[0]=dep;
            memcpy(ans,a,sizeof(a));
            return;
         }
         search(dep+1);
      }
}
