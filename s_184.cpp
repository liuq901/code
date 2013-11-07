#include <cstdio>
#include <cstdlib>
int main()
{
   int min(int,int);
   int p,m,c,k,r,v;
   scanf("%d%d%d",&p,&m,&c);
   scanf("%d%d%d",&k,&r,&v);
   printf("%d\n",min(min(p/k,m/r),c/v));
   system("pause");
   return(0);
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
