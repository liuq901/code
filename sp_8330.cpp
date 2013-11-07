#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int array[30010];
typedef long long ll;
array a,l,c,d,s,e,w,f;
ll b[30010],ans[30010];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int N,K,m;
      scanf("%d%d%d",&N,&K,&m);
      int n=0,p=1;
      for (int i=1;i<=K;i++)
      {
         scanf("%d%d",&l[i],&c[i]);
         a[++n]=p,p+=l[i],f[i]=p;
      }
      a[++n]=N+1;
      for (int i=1;i<=m;i++)
      {
         scanf("%d%d%d",&s[i],&e[i],&w[i]);
         a[++n]=s[i],a[++n]=e[i]+1;
      }
      sort(a+1,a+n+1);
      n=unique(a+1,a+n+1)-a-1;
      int now=1;
      for (int i=1;i<n;i++)
      {
         if (a[i]==f[now])
            now++;
         d[i]=c[now];
      }
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x=lower_bound(a+1,a+n+1,s[i])-a,y=lower_bound(a+1,a+n+1,e[i]+1)-a;
         b[x]+=w[i],b[y]-=w[i];
      }
      ll more=0;
      int sum=0;
      for (int i=1;i<n;i++)
      {
         int num=a[i+1]-a[i];
         b[i]+=b[i-1];
         if (b[i]>=d[i])
         {
            sum+=num;
            more+=ll(b[i]-d[i])*num;
         }
         else
         {
            int p=d[i]-b[i];
            if (more>=ll(p)*num)
            {
               sum+=num;
               more-=ll(p)*num;
            }
            else
            {
               sum+=more/p;
               more=0;
            }
         }
      }
      printf("%lld %d\n",more,sum);
   }
   system("pause");
   return(0);
}
