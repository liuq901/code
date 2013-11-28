#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
pair <ll,int> a[100010];
int main()
{
   int n;
   scanf("%d",&n);
   int ans,n2,n4;
   ll lq=0;
   ans=n2=n4=0;
   for (int i=1;i<=n;i++)
   {
      int x;
      ll y;
      scanf("%d%lld",&x,&y);
      a[i]=make_pair(y,x);
      if (x==2 || x==4)
         ans++;
      if (x==2)
         n2++;
      if (x==4)
         n4++;
   }
   sort(a+1,a+n+1);
   int p,q,i;
   p=q=0,i=1;
   while (i<=n)
   {
      ll now=a[i].first;
      int p1,p2,p3,p4;
      p1=p2=p3=p4=0;
      while (i<=n && a[i].first==now)
      {
         int x=a[i].second;
         if (x==1)
            p1++;
         if (x==2)
            p2++;
         if (x==3)
            p3++;
         if (x==4)
            p4++;
         i++;
      }
      int sum=p+n2-q-p2+p3+n4-p4;
      if (sum>ans)
         ans=sum,lq=now;
      if (i<=n && a[i].first!=now+1)
      {
         sum=p+p1+n2-q-p2+n4;
         if (sum>ans)
            ans=sum,lq=now;
      }
      p+=p1,q+=p2;
   }
   printf("%d %lld\n",ans,lq);
   system("pause");
   return(0);
}
