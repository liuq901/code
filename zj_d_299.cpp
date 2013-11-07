#include <cstdio>
#include <cstdlib>
int main()
{
   bool check(int,int);
   for (int i=10000;i<=99999;i++)
      for (int j=150;j<=950;j+=100)
         if (check(i,j))
            printf("%d + %d + %d = %d\n",i,j,j,i+j+j);
   system("pause");
   return(0);
}
bool check(int x,int y)
{
   int z=x+y+y;
   if (z>99999)
      return(false);
   if (x/10%10!=y/100)
      return(false);
   bool f[11]={0};
   for (int i=1;i<=5;i++)
   {
      f[x%10]=true;
      x/=10;
      f[z%10]=true;
      z/=10;
      f[y%10]=true;
      y/=10;
   }
   for (int i=0;i<=9;i++)
      if (!f[i])
         return(false);
   return(true);
}
