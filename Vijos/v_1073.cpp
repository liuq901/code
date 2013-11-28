#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,j,s,x,ans;
   scanf("%d",&n);
   ans=1;
   i=1;
   s=1;
   x=1;
   while (1)
   {
      i++;
      s+=i;
      x=x*2%10000;
      if (s>=n)
      {
         for (j=s-i+1;j<=n;j++)
            ans=(ans+x)%10000;
         break;
      }
      else
         ans=(ans+x*i)%10000;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
