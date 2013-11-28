#include <cstdio>
#include <cstdlib>
const int n=140000;
int a[n+10],b[n+10];
int main()
{
   void init();
   init();
   for (int i=100;i<=n;i++)
   {
      for (int j=1;j<=a[0];j++)
         if (!(i%a[j]))
            b[i]++;
      if (b[i]==4 && b[i-1]==4 && b[i-2]==4 && b[i-3]==4)
      {
         printf("%d\n",i-3);
         break;
      }
   }
   system("pause");
   return(0);
}
bool f[n+10];
void init()
{
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
