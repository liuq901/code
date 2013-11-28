#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int i,n,k,x,t,ans;
   scanf("%d",&n);
   scanf("%d",&k);
   ans=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      t=(int)(pow(x,k)+0.5);
      if (t>0)
         ans+=t;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
