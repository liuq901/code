#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[1000010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      memset(f,0,sizeof(f));
      int ans;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (f[x])
            ans=x;
         f[x]=true;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
