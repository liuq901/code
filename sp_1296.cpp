#include <cstdio>
#include <cstdlib>
#include <utility>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;
hash_map <int,int> p;
int a[4001],b[4001],c[4001],d[4001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
   p.clear();
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         hash_map <int,int>::iterator k=p.find(a[i]+b[j]);
         if (k==p.end())
            p.insert(make_pair(a[i]+b[j],1));
         else
            k->second++;
      }
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         hash_map <int,int>::iterator k=p.find(-c[i]-d[j]);
         if (k!=p.end())
            ans+=k->second;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
