#include <cstdio>
#include <cstdlib>
bool f[20010];
int main()
{
   for (int i=2;i<=20000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=20000;j++)
         f[i*j]=true;
   }
   int n;
   while (scanf("%d",&n)==1)
      for (int i=n>>1;i;i--)
         if (!f[i] && !f[n-i])
         {
            printf("%d %d\n",i,n-i);
            break;
         }
   system("pause");
   return(0);
}
