#include <cstdio>
#include <cstdlib>
int main()
{
   int sum,n;
   scanf("%d",&n);
   sum=(n+1)/2;
   while (n!=0)
   {
      n/=4;
      sum+=(n+1)/2;
   }
   printf("%d\n",sum);
   system("pause");
   return(0);
}
