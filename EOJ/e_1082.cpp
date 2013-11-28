#include <cstdio>
#include <cstdlib>
const int a[10]={1,1,2,6,24,120,720,5040,40320,362880};
bool ans[1000001];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n<0)
         break;
      printf("%s\n",ans[n]?"YES":"NO");
   }
   system("pause");
   return(0);
}
void init()
{
   for (int i=1;i<=1023;i++)
   {
      int sum=0,x=i;
      for (int j=0;j<=9;j++)
      {
         sum+=a[j]*(x&1);
         x>>=1;
      }
      if (sum<=1000000)
         ans[sum]=true;
   }
}
