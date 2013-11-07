#include <cstdio>
#include <cstdlib>
#include <utility>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;
hash_map <int,int> p;
int main()
{
   int n,a[101];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         for (int k=1;k<=n;k++)
         {
            int x=a[i]*a[j]+a[k];
            hash_map <int,int>::iterator t=p.find(x);
            if (t==p.end())
               p.insert(make_pair(x,1));
            else
               t->second++;
         }
   int ans=0;
   for (int i=1;i<=n;i++)
   {
      if (!a[i])
         continue;
      for (int j=1;j<=n;j++)
         for (int k=1;k<=n;k++)
         {
            int x=(a[j]+a[k])*a[i];
            hash_map <int,int>::iterator t=p.find(x);
            if (t!=p.end())
               ans+=t->second;
         }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
