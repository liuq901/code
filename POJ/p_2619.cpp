#include <cstdio>
#include <cstdlib>
#include <cmath>
class point
{
   int x,y,z;
   friend int operator -(point,point);
public:
   point(int n)
   {
      x=int(sqrt(double(n-1)))+1;
      y=(n-(x-1)*(x-1)+1)/2;
      z=(x*x-n)/2+1;
   }
};
int operator -(point a,point b)
{
   return(abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z));
}
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   point p(n),q(m);
   printf("%d\n",p-q);
   system("pause");
   return(0);
}
