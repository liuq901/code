#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   if (n<=m)
      printf("2\n");
   else
      printf("%d\n",(n<<1)/m+((n<<1)%m!=0));
   system("pause");
   return(0);
}
