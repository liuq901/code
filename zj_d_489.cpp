#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   int p=a+b+c>>1;
   printf("%d\n",p*(p-a)*(p-b)*(p-c));
   system("pause");
   return(0);
}
