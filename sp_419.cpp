#include <cstdio>
#include <cstdlib>
struct integer
{
   int a,b;
   integer(int a,int b):a(a),b(b){}
};
const int prime=1000003;
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   int gcd(int,int);
   integer extended_gcd(int,int);
   long long multi(int);
   int n,m,g;
   scanf("%d%d",&n,&m);
   if (!n || !m)
   {
      printf("0\n");
      return;
   }
   g=gcd(n,m);
   int x=(n+m)/g;
   integer tmp=extended_gcd(x,prime);
   int p=tmp.a;
   long long sum=0;
   for (int i=1;i<=x;i++)
   {
      long long k=multi(g*gcd(i,x))*p%prime;
      while (k<0)
         k+=prime;
      sum+=k;
      sum%=prime;
   }
   long long t=multi(n+m);
   printf("%I64d\n",(t-sum+prime)%prime);
}
int gcd(int a,int b)
{
   if (!b)
      return(a);
   return(gcd(b,a%b));
}
integer extended_gcd(int a,int b)
{
   if (!b)
      return(integer(1,0));
   integer tmp=extended_gcd(b,a%b);
   int x=tmp.a,y=tmp.b;
   return(integer(y,x-(a/b)*y));
}
int f[500001];
long long multi(int x)
{
   if (f[x])
      return(f[x]);
   if (!x)
      f[x]=1;
   else if (x&1)
      f[x]=multi(x/2)*multi(x/2)*2%prime;
   else
      f[x]=multi(x/2)*multi(x/2)%prime;
   return(f[x]);
}
