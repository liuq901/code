#include <cstdio>
#include <cstdlib>
int main()
{
   long v,n,x,i,j;
   long a[20001]={0};
   scanf("%ld",&v);
   scanf("%ld",&n);
   a[0]=1;
   for (i=1;i<=n;i++)
   {
      scanf("%ld",&x);
      for (j=v;j>=0;j--)
      {
         if (x+j>v)
            continue;
         if (a[j])
            a[x+j]=1;
      }
   }
   for (i=v;i>=1;i--)
      if (a[i])
      {
         printf("%ld\n",v-i);
         break;
      }
   system("pause");
   return(0);
}
