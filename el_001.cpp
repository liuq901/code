#include <cstdio>
#include <cstdlib>
int main()
{
   int max=-1<<30,x;
   while (scanf("%d",&x)!=EOF)
      max=max>x?max:x;
   printf("%d\n",max);
   system("pause");
   return(0);
}
