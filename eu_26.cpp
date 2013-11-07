#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[1010];
int main()
{
   int k=-1,ans;
   for (int i=2;i<1000;i++)
   {
      int x=1,t=0;
      memset(f,0,sizeof(f));
      while (x)
      {
         int p=x*10/i;
         x=x*10%i;
         if (!x)
            break;
         t++;
         if (f[x])
         {
            if (t-f[x]>k)
               k=t-f[x],ans=i;
            break;
         }
         f[x]=t;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
