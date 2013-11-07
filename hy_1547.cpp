#include <cstdio>
#include <cstdlib>
const int max=100000007;
int n,k;
long long ans,r[2001],q[2001],p[2001][2001];
int main()
{
   void prepare(),work();
   int i,t;
   prepare();
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
      scanf("%d%d",&n,&k);
      if (n<k)
         k=n;
      work();
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void prepare()
{
   long long count(int,int);
   int i;
   for (i=1;i<=2000;i++)
      q[i]=count(i,max-2);
}
long long count(int base,int t)
{
   long long res;
   if (t==0)
      return(1);
   res=count(base,t>>1);
   res=(res*res)%max;
   if (t&1==1)
      res=(res*base)%max;
   return(res);
}
void work()
{
   int i,j;
   p[1][0]=1;
   for (i=1;i<n;i++)
   {
      p[i+1][0]=0;
      for (j=0;j<=k;j++)
      {
         p[i+1][0]=(p[i+1][0]+p[i][j])%max;
         p[i+1][j+1]=p[i][j];
      }
   }
   for (i=1;i<=n;i++)
      for (j=0;j<=k;j++)
         p[i][j]=(p[i][j]*(j+1))%max;
   for (i=1;i<=n;i++)
   {
      r[i]=0;
      for (j=0;j<=k;j++)
         r[i]=(r[i]+p[i][j])%max;
   }
   if (k>=n)
      ans=1;
   else
      ans=0;
   for (i=1;i<=n;i++)
      if (n%i==0)
      {
         for (j=2*i;j<=n;j+=i)
            r[j]=(r[j]-r[i]+max)%max;
         ans=(ans+r[i]*q[i])%max;
      }
}
