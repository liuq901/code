#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b;
   scanf("%d%d",&a,&b);
   if (a>=17 || a<=6 || a==7 && b<30)
      printf("Off School\n");
   else
      printf("At School\n");
   system("pause");
   return(0);
}
