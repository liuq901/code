#include <cstdio>
#include <cstdlib>
struct FountainOfLife
{
   double elixirOfDeath(int x,int y,int z)
   {
      if (y<=x)
         return(-1);
      return(double(z)/double(y-x));
   }
};
int main()
{
   int x,y,z;
   scanf("%d%d%d",&x,&y,&z);
   FountainOfLife t;
   printf("%.10lf\n",t.elixirOfDeath(x,y,z));
   system("pause");
   return(0);
}
