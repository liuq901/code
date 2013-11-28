#include <cstdio>
#include <cstdlib>
int main()
{
   int k;
   while (scanf("%d",&k)!=EOF)
   {
      int m=1,n=1;
      while (m+n<=k)
      {
         int t=m+n;
         m=n,n=t;
      }
      printf("%d %d\n",m,n);
   }
   system("pause");
   return(0);
}
