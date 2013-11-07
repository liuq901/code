#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   if (n==1 || m==1)
      printf("%d\n",(n+m)/2);
   else if (n*m%3==0)
      printf("2\n");
   else
      printf("1\n");
   system("pause");
   return(0);
}
