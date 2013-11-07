#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   scanf("%d",&n);
   int ans=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j*j<=i;j++)
         if (!(i%j))
            ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
