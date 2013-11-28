#include <cstdio>
#include <cstdlib>
int n,m,p,x[60],c[60],d[60][60];
long long ans,a[60],b[60],f[60];
int main()
{
   void init(),search(int,int);
   scanf("%d%d%d",&n,&m,&p);
   init();
   search(1,0);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
void init()
{
   int gcd(int,int);
   long long multi(long long,long long);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         d[i][j]=gcd(i,j);
   for (int i=0;i<=n;i++)
      c[i]=i*(i-1)/2;
   for (int i=1;i<=n;i++)
      a[i]=multi(i,p-2);
   f[0]=1;
   for (int i=1;i<=n;i++)
      f[i]=f[i-1]*i%p;
   for (int i=0;i<=n;i++)
      b[i]=multi(f[i],p-2);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
void search(int t,int s)
{
   long long count();
   if (s==n)
   {
      ans=(ans+count())%p;
      return;
   }
   if (t>n)
      return;
   int k=(n-s)/t;
   for (int i=0;i<=k;i++)
   {
      x[t]=i;
      search(t+1,t*i+s);
   }
}
long long count()
{
   long long multi(long long,long long);
   long long sum=0,ans=1;
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
         if (x[i] && x[j])
            sum+=x[i]*x[j]*d[i][j];
   for (int i=1;i<=n;i++)
      sum+=i/2*x[i]+c[x[i]]*i;
   for (int i=1;i<=n;i++)
   {
      long long t=a[i];
      for (int j=1;j<=x[i];j++)
         ans=ans*t%p;
      ans=ans*b[x[i]]%p;
   }
   ans=ans*multi(m,sum)%p;
   return(ans);
}
long long multi(long long a,long long b)
{
   if (b==0)
      return(1);
   long long tmp=multi(a,b>>1);
   tmp=tmp*tmp%p;
   if (b&1)
      tmp=tmp*a%p;
   return(tmp);
}
