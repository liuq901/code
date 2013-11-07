#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int mod=1440;
bool awake[1500];
int A,B,b[10000];
pair <int,int> ans[10000];
int main()
{
   void fill(int,int);
   bool check(int,int),check(int);
   while (scanf("%d%d",&A,&B)==2)
   {
      A*=60,B*=60;
      int n;
      scanf("%d",&n);
      memset(awake,0,sizeof(awake));
      int tot=0;
      for (int i=1;i<=n;i++)
      {
         int x1,y1,x2,y2;
         scanf("%d:%d-%d:%d",&x1,&y1,&x2,&y2);
         x1=x1*60+y1,x2=x2*60+y2;
         if (x1>x2)
            x2+=mod;
         fill(x1,x2);
         b[++tot]=x1,b[++tot]=x2,b[++tot]=x1+mod,b[++tot]=x2+mod;
      }
      sort(b+1,b+tot+1);
      tot=unique(b+1,b+tot+1)-b-1;
      int m=0;
      for (int i=2;i<=tot;i++)
         if (check(b[i-1]+1,b[i]-1))
            ans[++m]=make_pair(b[i-1]+1,b[i]-1);
      for (int i=1;i<=m;i++)
         ans[i+m]=ans[i];
      if (!m || !check(m<<1))
         printf("No\n");
      else
      {
         printf("Yes\n");
         for (int i=1;i<=m;i++)
            ans[i].first%=mod,ans[i].second%=mod;
         sort(ans+1,ans+m+1);
         m=unique(ans+1,ans+m+1)-ans-1;
         printf("%d\n",m);
         for (int i=1;i<=m;i++)
            printf("%02d:%02d-%02d:%02d\n",ans[i].first/60,ans[i].first%60,ans[i].second/60,ans[i].second%60);
      }
   }
   system("pause");
   return(0);
}
void fill(int l,int r)
{
   for (int i=l;i<=r;i++)
      awake[i%mod]=true;
}
bool check(int l,int r)
{
   if (r-l+1<A)
      return(false);
   for (int i=l;i<=r;i++)
      if (awake[i%mod])
         return(false);
   return(true);
}
bool check(int m)
{
   for (int i=2;i<=m;i++)
      if (ans[i].first-ans[i-1].second-1>B)
         return(false);
   return(true);
}
