#include <cstdio>
#include <cstdlib>
typedef long long ll;
int a[110];
int main()
{
   while (1)
   {
      int n,k;
      scanf("%d%d",&n,&k);
      if (!n && !k)
         break;
      ll p=1,t=9,sum=0;
      while (sum<n)
      {
         sum+=p*t;
         p++,t*=10;
      }
      p--,t/=10;
      sum-=p*t;
      n-=sum;
      int x=(n-1)/p,begin=t/9+x;
      n-=x*p+1;
      int j=begin;
      while (k)
      {
         a[0]=0;
         int tmp=j;
         while (tmp)
         {
            a[++a[0]]=tmp%10;
            tmp/=10;
         }
         for (int i=a[0];i;i--)
            if (n)
               n--;
            else if (k)
            {
               k--;
               printf("%d",a[i]);
            }
         j++;
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
