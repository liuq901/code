#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      n/=m;
      printf("%d\n",n+n/5*2+n%5/3);
   }
   system("pause");
   return(0);
}
