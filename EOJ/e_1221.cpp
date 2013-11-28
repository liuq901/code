#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   bool f[31]={0};
   for (int i=1;i<=n;i++)
   {
      int x=0;
      while (x!=-1)
      {
         f[x]=true;
         scanf("%d",&x);
      }
   }
   for (int i=0;i<=30;i++)
      if (!f[i])
      {
         f[0]=false;
         break;
      }
   printf("%s\n",f[0]?"yes":"no");
   system("pause");
   return(0);
}
