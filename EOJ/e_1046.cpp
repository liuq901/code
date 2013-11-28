#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;
const int mod=999997;
int a[4010],b[4010],c[4010],d[4010];
vector <pair <int,int> > hash[mod];
int main()
{
   void insert(int);
   int find(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         insert(a[i]+b[j]);
   long long ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         int x=-(c[i]+d[j]);
         ans+=find(x);
      }
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
void insert(int x)
{
   int p=x%mod;
   if (p<0)
      p+=mod;
   for (int i=0;i<hash[p].size();i++)
      if (hash[p][i].first==x)
      {
         hash[p][i].second++;
         return;
      }
   hash[p].push_back(make_pair(x,1));
}
int find(int x)
{
   int p=x%mod;
   if (p<0)
      p+=mod;
   for (int i=0;i<hash[p].size();i++)
      if (hash[p][i].first==x)
         return(hash[p][i].second);
   return(0);
}
