#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,k,ans;
   scanf("%d%d",&n,&k);
   i=1;
   ans=0;
   while (i<n)
   {
      if (i<=k)
      {
         i*=2;
         ans++;
      }
      else
      {
         if ((n-1)%k!=0)
            ans++;
         ans+=(n-i)/k;
         break;
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
