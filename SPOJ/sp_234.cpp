#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,k;
bool ans[31];
long long t[31];
int main()
{
   void init(long long);
   bool check();
   int test;
   scanf("%d",&test);
   while (test--)
   {
      scanf("%d%d",&n,&k);
      long long max=0;
      int now=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%lld",&t[i]);
         if (t[i]>max)
         {
            max=t[i];
            now=i;
         }
      }
      if (k==n-1)
      {
         for (int i=1;i<=n-2;i++)
            if (i!=now)
               printf("%d ",i);
         if (now==n-1)
            printf("%d\n",n);
         else if (now==n)
            printf("%d\n",n-1);
         else
            printf("%d %d\n",n-1,n);
         continue;
      }
      long long l=1,r=max;
      while (l<=r)
      {
         long long mid=l+r>>1;
         init(mid);
         if (check())
            l=mid+1;
         else
            r=mid-1;
      }
      int tot=0;
      for (int i=1;i<=n;i++)
         if (!ans[i])
         {
            tot++;
            printf("%d",i);
            if (tot==k)
            {
               printf("\n");
               break;
            }
            printf(" ");
         }
   }
   system("pause");
   return(0);
}
bool a[31][31];
void init(long long x)
{
   long long gcd(long long,long long);
   for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
      {
         long long p=gcd(t[i],t[j]);
         if (p>=x)
            a[i][j]=a[j][i]=true;
         else
            a[i][j]=a[j][i]=false;
      }
}
long long gcd(long long a,long long b)
{
   return(b?gcd(b,a%b):a);
}
int q[31];
bool check()
{
   bool search(int);
   q[0]=0;
   return(search(1));
}
bool search(int dep)
{
   if (q[0]==n-k)
   {
      memset(ans,0,sizeof(ans));
      for (int i=1;i<=q[0];i++)
         ans[q[i]]=true;
      return(true);
   }
   if (n-dep+1<n-k-q[0])
      return(false);
   bool flag=true;
   for (int i=1;i<=q[0];i++)
      if (!a[q[i]][dep])
      {
         flag=false;
         break;
      }
   if (flag)
   {
      q[++q[0]]=dep;
      if (search(dep+1))
         return(true);
      q[0]--;
   }
   if (search(dep+1))
      return(true);
   return(false);
}
