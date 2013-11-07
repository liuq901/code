#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[10010];
int main()
{
   while (1)
   {
      int l,n;
      scanf("%d%d",&l,&n);
      if (!l && !n)
         break;
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i]=make_pair(x,0);
         a[i+n]=make_pair(y,1);
      }
      n<<=1;
      sort(a+1,a+n+1);
      int ans=0,sum=0,now=-1;
      for (int i=1;i<=n;i++)
      {
         int pos=a[i].first,op=a[i].second;
         if (!sum)
            ans+=pos-now-1;
         if (!op)
            sum++;
         else
            sum--;
         now=pos;
      }
      ans+=l-now;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
