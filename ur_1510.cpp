#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,s,k,x;
   scanf("%d",&n);
   s=k=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      if (s==0)
      {
         k=x;
         s=1;
      }
      else if (x==k)
         s++;
      else
         s--;
   }
   printf("%d\n",k);
   system("pause");
   return(0);
}
