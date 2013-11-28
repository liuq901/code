#include <cstdio>
#include <cstdlib>
int max,n,a[11],b[11];
int main()
{
   long long search();
   int i,j;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
   printf("%I64d\n",search());
   system("pause");
   return(0);
}
long long search()
{
   long long lcd(long long,long long);
   long long x,s;
   int i,j;
   s=a[1];
   x=b[1];
   for (i=1;i<=n-1;i++)
   {
      s=a[i]/lcd(s,a[i])*s;
      while (1)
      {
         if (x%a[i+1]==b[i+1])
            break;
         else
            x+=s;
      }
   }
   return(x);
}
long long lcd(long long a,long long b)
{
   int t;
   if (a<b)
      t=a,a=b,b=t;
   if (b==0)
      return(a);
   else
      return(lcd(b,a%b));
}
