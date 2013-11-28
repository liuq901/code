#include <cstdio>
#include <cstdlib>
int main()
{
   int n,k,m,a[1001]={0};
   scanf("%d%d%d",&n,&k,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x]+=y;
   }
   int ans=1,now=k;
   for (int i=1;i<=n;i++)
   {
      a[i]++;
      if (now<a[i])
      {
         now=k;
         ans++;
      }
      now-=a[i];
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
