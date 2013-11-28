#include <cstdio>
#include <cstdlib>
#include <cstring>
int sg[1010];
bool f[1010];
int main()
{
   sg[0]=sg[1]=0;
   for (int i=2;i<=1000;i++)
   {
      memset(f,0,sizeof(f));
      for (int j=0;j<=i-2;j++)
         f[sg[j]^sg[i-j-2]]=true;
      for (int j=0;j<=1000;j++)
         if (!f[j])
         {
            sg[i]=j;
            break;
         }
   }
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,x(0);
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         int y;
         scanf("%d",&y);
         x^=sg[y];
      }
      printf("%s\n",x?"Win":"Lost");
   }
   system("pause");
   return(0);
}
