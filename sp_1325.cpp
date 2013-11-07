#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
int main()
{
   int min(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,k,p,sum,ans;
      scanf("%d%d%d",&n,&k,&p);
      set <int> a;
      a.insert(0);
      sum=0;
      ans=p;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         sum=(sum+p-x%p)%p;
         int l=(sum+k)%p,r=(p+k-1)%p;
         if (l<=r)
         {
            set <int>::iterator k=a.lower_bound(l);
            if (k!=a.end() && *k<=r)
               ans=min(ans,*k+p-sum);
         }
         else
         {
            set <int>::iterator k=a.lower_bound(l);
            if (k!=a.end())
               ans=min(ans,*k-sum);
            ans=min(ans,p-sum);
         }
         a.insert(sum);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
