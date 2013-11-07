#include <cstdio>
#include <cstdlib>
int a[30010];
bool f[30010];
int main()
{
   int calc(int);
   for (int i=1;i<=30000;i++)
      if (calc(i)>i)
         a[++a[0]]=i;
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=a[0];j++)
      {
         if (a[i]+a[j]>30000)
            break;
         f[a[i]+a[j]]=true;
      }
   int sum=0;
   for (int i=1;i<=30000;i++)
      if (!f[i])
         sum+=i;
   printf("%d\n",sum);
   system("pause");
   return(0);
}
int calc(int x)
{
   int sum=0;
   for (int i=1;i*i<=x;i++)
   {
      if (x%i)
         continue;
      int q=x/i;
      sum+=i+q;
      if (i==q)
      {
         sum-=i;
         break;
      }
   }
   return(sum-x);
}
