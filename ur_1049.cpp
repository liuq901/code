#include <cstdio>
#include <cstdlib>
int p,c[10001];
int main()
{
   void init(),count(int);
   init();
   for (int i=1;i<=10;i++)
   {
      int x;
      scanf("%d",&x);
      count(x);
   }
   int ans=1;
   for (int i=1;i<=p;i++)
      ans=ans*(c[i]+1)%10;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool f[10001];
int a[10001];
void init()
{
   for (int i=2;i<=10000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=10000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=10000;i++)
      if (!f[i])
         a[++p]=i;
}
void count(int x)
{
   int t=1;
   while (x!=1)
   {
      while (x%a[t])
         t++;
      c[t]++;
      x/=a[t];
   }
}
