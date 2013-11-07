#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[50001];
int main()
{
   int v,n;
   while (scanf("%d%d",&v,&n)!=EOF)
   {
      memset(f,0,sizeof(f));
      f[0]=true;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         for (int j=v;j>=x;j--)
         {
            if (f[j])
               continue;
            f[j]=f[j-x];
         }
      }
      int ans=v;
      while (!f[ans])
         ans--;
      printf("%d\n",v-ans);
   }
   system("pause");
   return(0);
}
