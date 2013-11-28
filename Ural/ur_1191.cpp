#include <cstdio>
#include <cstdlib>
int main()
{
   int l,n;
   scanf("%d%d",&l,&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      l-=l%x;
   }
   printf("%s\n",l<=0?"YES":"NO");
   system("pause");
   return(0);
}
