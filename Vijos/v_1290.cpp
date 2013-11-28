#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   scanf("%d",&n);
   for (i=1;i<=n/2;i++)
   {
      printf("%d\n",i);
      printf("%d\n",n-i+1);
   }
   if (n%2==1)
      printf("%d\n",n/2+1);
   system("pause");
   return(0);
}
