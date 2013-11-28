#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,x,s,i;
   scanf("%d%d",&n,&m);
   s=0;
   for (i=1;i<=m;i++)
   {
      scanf("%d",&x);
      s+=x;
   }
   printf("%d\n",s%n);
   system("pause");
   return(0);
}
