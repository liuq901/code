#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;
map <int,int> a;
int c[50010],d[50010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,C;
      scanf("%d%d",&n,&C);
      for (int i=1;i<=n;i++)
         scanf("%d",&d[i]);
      for (int i=0;i<n;i++)
         scanf("%d",&c[i]);
      c[n]=1<<30;
      a.clear();
      a[c[0]]+=C;
      ll ans=0;
      for (int i=1;i<=n;i++)
      {
         int dis=d[i]-d[i-1],need=dis;
         while (dis && a.begin()->second<=dis)
         {
            dis-=a.begin()->second;
            ans+=ll(a.begin()->first)*a.begin()->second;
            a.erase(a.begin());
         }
         ans+=ll(a.begin()->first)*dis;
         a.begin()->second-=dis;
         while (!a.empty() && a.rbegin()->first>c[i])
         {
            need+=a.rbegin()->second;
            map <int,int>::iterator k=a.end();
            --k;
            a.erase(k);
         }
         a[c[i]]+=need;
      }
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
