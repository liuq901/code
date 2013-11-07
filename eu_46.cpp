#include <cstdio>
#include <cstdlib>
const int n=1000000;
bool f[n+10],g[n+10];
int a[n+10];
int main()
{
   void init();
   init();
   for (int i=2;i<=n;i++)
      if ((i&1) && f[i])
      {
         bool flag=true;
         for (int j=2;j<=a[0];j++)
         {
            if (i<=a[j])
               break;
            if (g[i-a[j]>>1])
            {
               flag=false;
               break;
            }
         }
         if (flag)
         {
            printf("%d\n",i);
            break;
         }
      }
   system("pause");
   return(0);
}
void init()
{
   f[1]=true;
   for (int i=1;i*i<=n;i++)
   {
      g[i*i]=true;
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
