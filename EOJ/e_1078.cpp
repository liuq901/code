#include <cstdio>
#include <cstdlib>
const int a[11]={0,31,28,31,30,31,30,31,31,30,20};
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (n>10 || n==10 && m>21)
         printf("What a pity, it has passed!\n");
      else if (n==10 && m==21)
         printf("It's today!!\n");
      else
      {
         int ans=0;
         for (int i=n+1;i<=10;i++)
            ans+=a[i];
         ans+=a[n]-m+1;
         printf("%d\n",ans);
      }
   }
   system("pause");
   return(0);
}
