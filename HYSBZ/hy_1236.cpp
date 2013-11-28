#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   long long n;
   void work(long long);
   scanf("%I64d",&n);
   work(n);
   system("pause");
   return(0);
}
void work(long long n)
{
   long long count(int),calc(long long,int);
   int i,l;
   long long ans,s;
   l=(int)log10(n)+1;
   ans=0;
   s=1;
   for (i=1;i<=l-1;i++)
   {
      s*=10;
      ans+=calc(s-1,i);
   }
   ans+=calc(n,l);
   printf("%I64d\n",ans);
}
long long calc(long long x,int n)
{
   long long get(int,long long,int,int);
   int i,k;
   long long s,t,p;
   if (n%2==1)
   {
      s=1;
      for (i=1;i<=n;i++)
         s*=10;
      s/=10;
      if (s==1)
         s=0;
      t=x-s+1;
      t/=2;
      if (x%2==0)
      {
         k=1;
         for (i=1;i<=n;i++)
         {
            k*=-1;
            p=x%10;
            x/=10;
            t+=p*k;
         }
      }
      return(t);
   }
   return(get(1,x,n,-1));
}
long long get(int q,long long x,int l,int flag)
{
   int i,k;
   long long s,ans;
   if (l==0)
      return(0);
   s=1;
   for (i=1;i<=l-1;i++)
      s*=10;
   k=x/s;
   ans=0;
   for (i=q;i<=k-1;i++)
   {
      ans+=i*flag*s;
      ans-=(l-1)%2*s/10*45*flag;
   }
   ans+=k*flag*(x%s+1);
   ans+=get(0,x%s,l-1,-flag);
   return(ans);
}
