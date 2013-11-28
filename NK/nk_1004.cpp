#include <cstdio>
#include <cstdlib>
#include <cmath>
#define SQR(x) ((x)*(x))
int a[60];
int main()
{
   bool check(int);
   int n;
   scanf("%d",&n);
   int ans=1;
   while (1)
   {
      bool flag=false;
      for (int i=1;i<=n;i++)
         if (!a[i] || check(ans+a[i]))
         {
            a[i]=ans++;
            flag=true;
            break;
         }
      if (!flag)
         break;
   }
   printf("%d\n",ans-1);
   system("pause");
   return(0);
}
bool check(int x)
{
   int t=int(sqrt(double(x)));
   return(SQR(t-1)==x || SQR(t)==x || SQR(t+1)==x);
}
