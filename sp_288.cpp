#include <cstdio>
#include <cstdlib>
typedef long long int64;
typedef unsigned long long int64u;
int main()
{
   bool work(int,int64);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int64 n;
      scanf("%lld",&n);
      printf("%s\n",work(2,n) && work(3,n)?"YES":"NO");
   }
   system("pause");
   return(0);
}
bool work(int p,int64 x)
{
   int64 pow(int,int64,int64),multi(int64,int64,int64);
   if (x==2 || p==x)
      return(true);
   if (x==1 || !(x&1))
      return(false);
   int64 d=x-1,t;
   while (!(d&1))
      d>>=1;
   t=pow(p,d,x);
   while (d!=x-1 && t!=1 && t!=x-1)
   {
      d<<=1;
      t=multi(t,t,x);
   }
   return(t==x-1 || d&1);
}
int64 pow(int x,int64 p,int64 q)
{
   int64 multi(int64,int64,int64);
   if (!p)
      return(1);
   int64 ans=pow(x,p>>1,q);
   ans=multi(ans,ans,q);
   if (p&1)
      ans=multi(ans,x,q);
   return(ans%q);
}
int64 multi(int64 a,int64 b,int64 c)
{
   int64u ans=0,now;
   for (now=a;b;b>>=1)
   {
      if (b&1)
      {
         ans+=now;
         if (ans>=c)
            ans-=c;
      }
      now<<=1;
      if (now>=c)
         now-=c;
   }
   return(ans);
}
