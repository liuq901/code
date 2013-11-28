#include <cstdio>
#include <cstdlib>
const int a[]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
   int calc(int);
   int ans=0;
   for (int i=10;i<=1000000;i++)
      if (calc(i)==i)
         ans+=i;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int calc(int x)
{
   int sum=0;
   while (x)
   {
      sum+=a[x%10];
      x/=10;
   }
   return(sum);
}
