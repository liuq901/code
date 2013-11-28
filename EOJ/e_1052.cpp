#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[100001];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
      {
         int w,v;
         scanf("%d%d",&w,&v);
         for (int j=m;j>=w;j--)
            if (f[j-w]+v>f[j])
               f[j]=f[j-w]+v;
      }
      printf("%d\n",f[m]);
   }
   system("pause");
   return(0);
}
