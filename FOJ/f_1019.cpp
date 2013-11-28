#include <cstdio>
#include <cstdlib>
#include <iostream>
#define STEP 100000
using namespace std;
const int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
class state
{
   int x,y,direct;
   friend bool operator ==(state,state);
public:
   static bool map[20][20];
   state(){}
   state(int x,int y,int direct):x(x),y(y),direct(direct){}
   void move()
   {
      int x0=x+c[direct][0],y0=y+c[direct][1];
      if (map[x0][y0])
         x=x0,y=y0;
      else
      {
         direct++;
         if (direct==4)
            direct=0;
      }
   }
};
bool operator ==(state a,state b)
{
   return(a.x==b.x && a.y==b.y);
}
bool state::map[20][20];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      state cat,mouse;
      for (int i=1;i<=10;i++)
         for (int j=1;j<=10;j++)
         {
            char ch;
            cin>>ch;
            if (ch=='*')
               state::map[i][j]=false;
            else
            {
               state::map[i][j]=true;
               if (ch=='c')
                  cat=state(i,j,0);
               if (ch=='m')
                  mouse=state(i,j,0);
            }
         }
      int ans=0;
      for (int i=1;i<=STEP;i++)
      {
         cat.move(),mouse.move();
         if (cat==mouse)
         {
            ans=i;
            break;
         }
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
