#include <cstdio>
#include <cstdlib>
int main()
{
   int x,s;
   s=0;
   while (scanf("%d",&x)!=EOF)
      s+=x;
   printf("%d\n",s);
   system("pause");
   return(0);
}
