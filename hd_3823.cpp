#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int n=19000000;
vector <int> s[160];
int main()
{
   void init();
   int find(int,int);
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      if (a>b)
         swap(a,b);
      static int id=0;
      printf("Case %d: %d\n",++id,find(b-a,a));
   }
   system("pause");
   return(0);
}
bool f[n+10];
int a[1300000];
void init()
{
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
   for (int i=2;i<=a[0];i++)
   {
      int t=a[i]-a[i-1];
      if (s[t].empty() || s[t][s[t].size()-1]<150)
         s[t].push_back(a[i-1]);
   }
}
int find(int x,int v)
{
   int l=0,r=s[x].size()-1,ans=-1;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (s[x][mid]>=v)
         r=mid-1,ans=s[x][mid]-v;
      else
         l=mid+1;
   }
   return(ans);
}
