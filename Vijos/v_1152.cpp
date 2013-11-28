#include <cstdio>
#include <cstdlib>
int main()
{
   int n,a,b,c,x,y,z;
   scanf("%d",&n);
   scanf("%d%d%d",&a,&b,&c);
   x=abs(a-b)==1 && abs(b-c)==1;
   y=abs(b-c)==1 && abs(c-a)==1;
   z=abs(c-a)==1 && abs(a-b)==1;
   if (x || y || z)
      printf("JMcat Win\n");
   else if (n%2==1)
      printf("PZ Win\n");
   else
      printf("JMcat Win\n");
   system("pause");
   return(0);
}
