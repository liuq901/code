#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char a[10010],b[10010];
   int x,y,i;
   for (i=1;i<=10;i++)
   {
      scanf("%s",a);
      scanf("%s",b);
      x=a[strlen(a)-1]-'0';
      y=b[strlen(b)-1]-'0';
      if (x==2 || x==3 || x==7 || x==8)
         if (y==2 || y==3 || y==7 || y==8)
            printf("Shadow\n");
         else
            printf("Matrix67\n");
      else
         printf("Matrix67\n");
   }
   system("pause");
   return(0);
}
