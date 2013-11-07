#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<30;
int a[50],prime[1000000];
ll ans;
int main()
{
   void init(),dfs(int,int);
   init();
   while (1)
   {
      ll n;
      cin>>n;
      if (!n)
         break;
      a[0]=0;
      ll t=n;
      for (int i=1;i<=prime[0];i++)
      {
         if (t%prime[i])
            continue;
         a[++a[0]]=0;
         while (!(t%prime[i]))
         {
            a[a[0]]++;
            t/=prime[i];
         }
      }
      if (t>1)
         a[++a[0]]=1;
      ans=0;
      dfs(1,inf);
      cout<<n<<" "<<ans<<endl;
   }
   system("pause");
   return(0);
}
bool f[3200010];
void init()
{
   int n=3200000;
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         prime[++prime[0]]=i;
}
void dfs(int dep,int value)
{
   if (dep==a[0]+1)
   {
      ans+=value==inf?0:value;
      return;
   }
   dfs(dep+1,value);
   for (int i=1;i<=a[dep];i++)
      dfs(dep+1,min(value,a[dep]/i));
}
