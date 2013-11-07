#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,t;
   int a[26];
   while (scanf("%d",&n)!=EOF)
   {
      t=0;
      while (n!=0)
      {
         t++;
         a[t]=n%10;
         n/=10;
      }
      i=1;
      while (a[i]==0)
         i++;
      while (i<=t)
      {
         printf("%d",a[i]);
         i++;
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
