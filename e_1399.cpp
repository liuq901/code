#include <cstdio>
#include <cstdlib>
long long a[2000001],s[2000001];
int d[1000001],p[1000001],q[2000001];
bool ans[1000001];
int main()
{
   void solve(int,bool);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&d[i],&p[i]);
      a[i]=d[i]-p[i];
      s[i]=s[i-1]+a[i];
   }
   for (int i=n+1;i<=2*n-1;i++)
   {
      a[i]=a[i-n];
      s[i]=s[i-1]+a[i];
   }
   solve(n,false);
   p[0]=p[n];
   for (int i=1;i<=n;i++)
   {
      a[i]=d[n-i+1]-p[n-i];
      s[i]=s[i-1]+a[i];
   }
   for (int i=n+1;i<=2*n-1;i++)
   {
      a[i]=a[i-n];
      s[i]=s[i-1]+a[i];
   }
   solve(n,true);
   for (int i=1;i<=n;i++)
      printf("%s\n",ans[i]?"TAK":"NIE");
   system("pause");
   return(0);
}
void solve(int n,bool flag)
{
   int l=1,r=0;
   for (int i=1;i<=n-1;i++)
   {
      while (l<=r && s[q[r]]>=s[i])
         r--;
      q[++r]=i;
   }
   for (int i=n;i<=2*n-1;i++)
   {
      int x=i-n+1;
      if (q[l]==x-1)
         l++;
      while (l<=r && s[q[r]]>=s[i])
         r--;
      q[++r]=i;
      int t;
      if (!flag)
         t=x;
      else
         t=n-x+1;
      if (s[q[l]]>=s[x-1])
         ans[t]=true;
   }
}
