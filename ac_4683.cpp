#include <cstdio>
#include <cstdlib>
typedef long long ll;
int m,a[20];
int main()
{
   void init();
   ll calc(ll);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d%d",&m,&n);
      for (int i=1;i<=m;i++)
         scanf("%d",&a[i]);
      init();
      ll l=1,r=1LL<<60,ans;
      while (l<=r)
      {
         ll mid=l+r>>1;
         if (calc(mid)>=n)
            r=mid-1,ans=mid;
         else
            l=mid+1;
      }
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
ll b[4100];
int c[4100];
void init()
{
   ll lcm(int);
   int limit=1<<m;
   for (int i=1;i<limit;i++)
   {
      b[i]=lcm(i);
      c[i]=0;
      for (int j=i;j;j>>=1)
         c[i]+=j&1;
      c[i]=c[i]&1?c[i]:-c[i];
   }
}
ll lcm(int x)
{
   ll gcd(ll,ll);
   ll now=-1;
   for (int i=0;i<m;i++)
      if (x>>i&1)
      {
         if (now==-1)
         {
            now=a[i+1];
            continue;
         }
         ll p=gcd(now,a[i+1]);
         now=now/p*a[i+1];
      }
   return(now);
}
ll gcd(ll a,ll b)
{
   while (b)
   {
      ll t=a%b;
      a=b,b=t;
   }
   return(a);
}
ll calc(ll num)
{
   ll tot=0;
   int limit=1<<m;
   for (int i=1;i<limit;i++)
      tot+=num/b[i]*c[i];
   return(tot);
}
