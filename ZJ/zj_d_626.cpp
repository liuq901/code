#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[110][110];
int main()
{
   void floodfill(int,int);
   int n;
   scanf("%d",&n);
   for (int i=0;i<n;i++)
      scanf("%s",a[i]);
   int x,y;
   scanf("%d%d",&x,&y);
   floodfill(x,y);
   for (int i=0;i<n;i++)
      printf("%s\n",a[i]);
   system("pause");
   return(0);
}
void floodfill(int x0,int y0)
{
   a[x0][y0]='+';
   for (int i=0;i<4;i++)
   {
      int x=x0+c[i][0],y=y0+c[i][1];
      if (a[x][y]=='-')
         floodfill(x,y);
   }
}

