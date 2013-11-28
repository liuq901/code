#include <cstdio>
#include <cstdlib>
int a[1001];
int main()
{
   int work(int),gcd(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   int ans=1;
   for (int i=1;i<=n;i++)
   {
      if (!a[i])
         continue;
      int len=work(i);
      ans=ans/gcd(ans,len)*len;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int work(int x)
{
   int ans=0;
   while (x)
   {
      ans++;
      int t=a[x];
      a[x]=0;
      x=t;
   }
   return(ans-1);
}
int gcd(int a,int b)
{
   return(b?gcd(b,a%b):a);
}
