#include <cstdio>
#include <cstdlib>
int a[1001];
int main()
{
   void init();
   init();
   int t;
   scanf("%d",&t);
   while (t--)
   {
      long long n;
      scanf("%lld",&n);
      long long p=(n-1)/a[0],q=(n-1)%a[0];
      if (p)
         printf("%lld",p);
      printf("%03d\n",a[q+1]);
   }
   system("pause");
   return(0);
}
void init()
{
   for (int i=1;i<=1000;i++)
   {
      long long p=(long long)i*i*i;
      if (p%1000==888)
         a[++a[0]]=i;
   }
}
