#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
map <ll,int> s;
int n,a[100010];
ll b[100010],c[100010];
int main()
{
   void insert(int);
   int find(int);
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
      {
         scanf("%lld",&b[i]);
         c[i]=b[i];
      }
      sort(b+1,b+n+1);
      s.clear();
      for (int i=1;i<=n;i++)
         s[b[i]]=i;
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x=s[c[i]];
         insert(x);
         printf("%d\n",i-find(x)+1);
      }
   }
   system("pause");
   return(0);
}
void insert(int x)
{
   for (int i=x;i<=n;i+=i&-i)
      a[i]++;
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=a[i];
   return(ans);
}
