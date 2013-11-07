#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i;
   int a[100];
   while (scanf("%d",&n)!=EOF)
   {
      i=0;
      while (n!=0)
      {
         i++;
         a[i]=n%2;
         n/=2;
      }
      while (i!=0)
      {
         printf("%d",a[i]);
         i--;
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
