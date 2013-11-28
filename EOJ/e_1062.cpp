#include <cstdio>
#include <cstdlib>
struct point
{
   int x,y;
};
point operator -(point a,point b)
{
   point c;
   c.x=a.x-b.x;
   c.y=a.y-b.y;
   return(c);
}
int operator *(point a,point b)
{
   return(a.x*b.y-a.y*b.x);
}
int main()
{
   bool check(point,point,point,point);
   point a1,b1,a2,b2;
   while (scanf("%d%d%d%d%d%d%d%d",&a1.x,&a1.y,&b1.x,&b1.y,&a2.x,&a2.y,&b2.x,&b2.y)!=EOF)
      printf("%s\n",check(a1,b1,a2,b2)?"Yes":"No");
   system("pause");
   return(0);
}
bool check(point a1,point b1,point a2,point b2)
{
   int max(int,int),min(int,int);
   if (max(a1.x,b1.x)<min(a2.x,b2.x))
      return(false);
   if (max(a1.y,b1.y)<min(a2.y,b2.y))
      return(false);
   if (max(a2.x,b2.x)<min(a1.x,b1.x))
      return(false);
   if (max(a2.y,b2.y)<min(a1.y,b1.y))
      return(false);
   if (((a2-a1)*(b1-a1))*((b2-a1)*(b1-a1))>0)
      return(false);
   if (((a1-a2)*(b2-a2))*((b1-a2)*(b2-a2))>0)
      return(false);
   return(true);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
