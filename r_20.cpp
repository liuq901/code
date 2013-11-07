#include <cstdio>
#include <cstdlib>
int main()
{
   int ans=8,k=0;
   for (int i=1;i<=7;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      if (x+y>ans)
      {
         ans=x+y;
         k=i;
      }
   }
   printf("%d\n",k);
   system("pause");
   return(0);
}
