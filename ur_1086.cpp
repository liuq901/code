#include <cstdio>
#include <cstdlib>
#include <cstring>
const int max=165000;
int a[16000],f[165001];
int main()
{
   void init();
   int n,x,i;
   init();
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&x);
      printf("%d\n",a[x]);
   }
   system("pause");
   return(0);
}
void init()
{
   int i,j;
   memset(f,0,sizeof(f));
   for (i=2;i<=max;i++)
   {
      if (f[i])
         continue;
      j=i;
      while (1)
      {
         if (i*j>max || i*j<i)
            break;
         f[i*j]=1;
         j++;
      }
   }
   j=0;
   for (i=2;i<=max;i++)
      if (!f[i])
      {
         j++;
         a[j]=i;
      }
}
