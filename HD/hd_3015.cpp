#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,x[100010],h[100010],p[100010],c[100010];
ll d[100010];
pair <int,int> a[100010];
int main()
{
   bool cmp1(int,int),cmp2(int,int);
   ll get(int);
   int find(int);
   void insert(int);
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&x[i],&h[i]);
         p[i]=i;
      }
      sort(p+1,p+n+1,cmp1);
      for (int i=1;i<=n;i++)
         a[p[i]].first=x[p[i]]==x[p[i-1]]?a[p[i-1]].first:i;
      sort(p+1,p+n+1,cmp2);
      for (int i=1;i<=n;i++)
         a[p[i]].second=h[p[i]]==h[p[i-1]]?a[p[i-1]].second:i;
      sort(a+1,a+n+1);
      ll ans;
      ans=0;
      memset(c,0,sizeof(c));
      memset(d,0,sizeof(d));
      for (int i=1;i<=n;i++)
      {
         int num=find(a[i].second);
         ans+=ll(a[i].first)*(get(a[i].second)+ll(a[i].second)*(i-1-find(a[i].second)));
         insert(a[i].second);
      }
      memset(c,0,sizeof(c));
      memset(d,0,sizeof(d));
      for (int i=n;i;i--)
      {
         int num=find(a[i].second);
         ans-=ll(a[i].first)*(get(a[i].second)+ll(a[i].second)*(n-i-find(a[i].second)));
         insert(a[i].second);
      }
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
bool cmp1(int a,int b)
{
   return(x[a]<x[b]);
}
bool cmp2(int a,int b)
{
   return(h[a]<h[b]);
}
ll get(int x)
{
   ll ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=d[i];
   return(ans);
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
void insert(int x)
{
   for (int i=x;i<=n;i+=i&-i)
   {
      c[i]++;
      d[i]+=x;
   }
}
