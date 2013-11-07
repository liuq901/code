#include <cstdio>
#include <cstdlib>
#include <cstring>
const int q=40000;
int f[100000];
int main()
{
   int i,n,x,t;
   scanf("%d",&n);
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      f[x+q]=1;
   }
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      t=10000-x;
      if (t+q>=0 && t+q<100000 && f[t+q])
         break;
   }
   if (i==n+1)
      printf("NO\n");
   else
      printf("YES\n");
   system("pause");
   return(0);
}
