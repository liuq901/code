#include <cstdio>
#include <cstdlib>
int main()
{
   int t;
   scanf("%*d%*d%d",&t);
   while (t--)
   {
      int x,y,x0,y0,x1,y1;
      scanf("%d%d%d%d%d%d",&x,&y,&x0,&y0,&x1,&y1);
      if (abs(x0-x1)!=abs(y0-y1))
      {
         printf("YES\n");
         continue;
      }
      int dx,dy;
      if (x0<x1)
         dx=1;
      else
         dx=-1;
      if (y0<y1)
         dy=1;
      else
         dy=-1;
      int p=x0,q=y0;
      bool flag=false;
      while (p!=x1 && q!=y1)
      {
         if (p==x && q==y)
         {
            flag=true;
            break;
         }
         p+=dx,q+=dy;
      }
      printf("%s\n",flag?"NO":"YES");
   }
   system("pause");
   return(0);
}
