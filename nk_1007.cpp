#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   while (n>3)
   {
      int p=n&1?3:2;
      printf("%d ",p);
      n-=p;
   }
   printf("%d\n",n);
   system("pause");
   return(0);
}
