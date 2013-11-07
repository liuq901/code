#include <cstdio>
#include <cstdlib>
int a[7]={0,100,50,20,10,5,2};
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      for (int i=1;i<=6;i++)
      {
         printf("%d ",x/a[i]);
         x%=a[i];
      }
      printf("%d\n",x);
   }
   system("pause");
   return(0);
}
