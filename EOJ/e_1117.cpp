#include <cstdio>
#include <cstdlib>
int a[1010],b[1010];
int main()
{
   void gcd(int,int,int &,int &);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      int m=1;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i]);
         m*=a[i];
      }
      for (int i=1;i<=n;i++)
         scanf("%d",&b[i]);
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int x,y,p=m/a[i];
         gcd(a[i],p,x,y);
         ans=(ans+y*p*b[i])%m;
      }
      if (ans<0)
         ans+=m;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void gcd(int a,int b,int &x,int &y)
{
   if (!b)
   {
      x=1,y=0;
      return;
   }
   int p,q;
   gcd(b,a%b,p,q);
   x=q,y=p-a/b*q;
}
