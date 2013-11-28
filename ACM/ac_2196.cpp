#include <cstdio>
#include <cstdlib>
typedef long long ll;
int main()
{
   ll calc(int),power(int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      ll ans=calc(n)+n-1+(calc(n)+n)*power(n-1)+power(n)-1+(n<<1)-2;
      static int id=0;
      printf("Case %d: %d\n",++id,int(ans%10000));
   }
   system("pause");
   return(0);
}
ll calc(int x)
{
   if (x<10)
      return(x);
   ll now=1;
   int p=1;
   while (now<=x)
   {
      now*=10;
      p++;
   }
   now/=10;
   p--;
   return((ll(x-now+1)*p+calc(now-1))%10000);
}
ll power(int x)
{
   if (!x)
      return(1);
   ll ans=power(x>>1);
   ans*=ans;
   if (x&1)
      ans<<=1;
   return(ans%10000);
}
