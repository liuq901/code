#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll a[40],b[40];
int main()
{
   a[0]=1;
   for (int i=1;i<=33;i++)
      a[i]=3*a[i-1]+2*b[i-1],b[i]=a[i-1]+b[i-1];
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==-1)
         break;
      printf("%I64d, %I64d\n",a[n],b[n]);
   }
   system("pause");
   return(0);
}
