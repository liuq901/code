#include <cstdio>
#include <cstdlib>
int a[1000010],pre[1000010];
int main()
{
   void init(),print(int);
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      print(n);
   }
   system("pause");
   return(0);
}
void init()
{
   int t=1,x=1;
   while (t<=1000000)
   {
      int n=t-1;
      for (int i=0;i<=n;i++)
      {
         a[t]=x;
         pre[t++]=i;
         if (t==1000001)
            break;
      }
      x*=3;
   }
}
void print(int x)
{
   if (!x)
      return;
   print(pre[x]);
   printf("%d\n",a[x]);
}
