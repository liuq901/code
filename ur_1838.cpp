#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int len,L,R,a[100010];
int main()
{
   int calc(int,int);
   int n;
   scanf("%d%d",&len,&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   int ans=a[1]+len-a[n];
   L=a[1],R=a[n];
   for (int i=1;i<n;i++)
      ans+=calc(a[i],a[i+1]);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int calc(int l,int r)
{
   int left=max(L<<1,max((r<<1)-len,l));
   int right=min(l<<1,min((R<<1)-len,r));
   if (left>right)
      left=right;
   return(r-l-(right-left));
}
