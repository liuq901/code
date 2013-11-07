#include <cstdio>
#include <cstdlib>
int main()
{
   int n,s=0;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      if (x>0)
         s+=x;
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
