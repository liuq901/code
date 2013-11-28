#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[500001],f[500001],ans[500001];
int main()
{
   int n,i;
   scanf("%d",&n);
   for (i=2;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,0,sizeof(f));
   for (i=n;i>1;i--)
      if (!f[i] && !f[a[i]])
      {
         ans[0]++;
         ans[ans[0]]=i;
         f[i]=f[a[i]]=1;
      }
   printf("%d000\n",ans[0]);
   for (i=ans[0];i>1;i--)
      printf("%d ",ans[i]);
   printf("%d\n",ans[1]);
   system("pause");
   return(0);
}
