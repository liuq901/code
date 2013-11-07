#include <cstdio>
#include <cstdlib>
#include <cmath>
bool f[1000001];
int a[1000001];
int main()
{
   void init(int);
   int n;
   scanf("%d",&n);
   init(n);
   for (int i=4;i<=n;i+=2)
      for (int j=1;j<=a[0];j++)
         if (!f[i-a[j]])
         {
            printf("%d=%d+%d\n",i,a[j],i-a[j]);
            break;
         }
   system("pause");
   return(0);
}
void init(int n)
{
   int limit=int(sqrt(n));
   f[1]=true;
   for (int i=2;i<=limit;i++)
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
