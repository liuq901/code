#include <cstdio>
#include <cstdlib>
int ans[210];
int main()
{
   ans[1]=1;
   for (int i=2;i<=200;i++)
      if (i&1)
         ans[i]=ans[i-1];
      else if (i>20 && (i>>1)%10>=(i>>1)/10<<1)
         ans[i]=ans[i>>1]+ans[i-1]-ans[(i>>1)/10];
      else
         ans[i]=ans[i>>1]+ans[i-1];
   int n;
   while (scanf("%d",&n)==1)
      printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
