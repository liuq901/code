#include <cstdio>
#include <cstdlib>
int main()
{
   int n,a[3]={0};
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a[x%3]++;
   }
   printf("%d %d %d\n",a[0],a[1],a[2]);
   system("pause");
   return(0);
}
