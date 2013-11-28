#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b;
   while (scanf("%d%d",&a,&b)==2)
   {
      if (!a)
      {
         printf("0\n");
         continue;
      }
      int low=a==2?8:10,ans=(b-low)*3+1;
      if (b>=120)
         ans+=5;
      else if (b>=70)
         ans+=2;
      else if (b>=30)
         ans++;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
