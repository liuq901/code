#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,ans;
   int s[20];
   for (i=1;i<=16;i++)
   {
      scanf("%d",&s[i]);
      if (s[i]==0)
         ans=(3-(i-1)/4)+(3-(i-1)%4);
   }
   for (i=1;i<=16;i++)
      for (j=i+1;j<=16;j++)
         if (s[i]>s[j])
            ans++;
   if (ans%2==1)
      printf("YES\n");
   else
      printf("NO\n");
   system("pause");
   return(0);
}
