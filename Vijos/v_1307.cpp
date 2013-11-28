#include <cstdio>
#include <cstdlib>
int main()
{
   long long s=0;
   int n,i;
   scanf("%d",&n);
   for (i=n;i>=1;i--)
      s+=i*i;
   printf("%I64d\n",s);
   system("pause");
   return(0);
}
