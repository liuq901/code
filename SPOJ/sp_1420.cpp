#include <cstdio>
#include <cstdlib>
int main()
{
   int x,y,a,b;
   scanf("%d%d%*d%d%d",&x,&y,&a,&b);
   printf("YES\n%d.0 %d.0\n",x+y-b,y-x+a);
   system("pause");
   return(0);
}
