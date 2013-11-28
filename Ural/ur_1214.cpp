#include <cstdio>
#include <cstdlib>
int main()
{
   int x,y;
   scanf("%d%d",&x,&y);
   if (x>0 && y>0 && x+y&1)
      printf("%d %d\n",y,x);
   else
      printf("%d %d\n",x,y);
   system("pause");
   return(0);
}
