#include <cstdio>
#include <cstdlib>
int f[100010];
int main()
{
   int calc(int,int);
   int a,b;
   while (scanf("%d%d",&a,&b)==2)
      printf("%d\n",calc(b,a));
   system("pause");
   return(0);
}
int calc(int x,int t)
{
   if (!x)
      return(1);
   int ans=calc(x>>1,t);
   ans*=ans;
   if (x&1)
      ans*=t;
   return(ans%10);
}
