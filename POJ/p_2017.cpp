#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (n==-1)
         break;
      int s=0,t=0;
      while (n--)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         s+=x*(y-t);
         t=y;
      }
      printf("%d miles\n",s);
   }
   system("pause");
   return(0);
}
