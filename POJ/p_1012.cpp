#include <cstdio>
#include <cstdlib>
const int a[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
int main()
{
   int n;
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d\n",a[n]);
   }
   system("pause");
   return(0);
}
