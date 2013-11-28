#include <cstdio>
#include <cstdlib>
int main()
{
   int i,j,n,x,s;
   while (scanf("%d",&n)!=EOF)
   {
      s=0;
      x=5;
      for (j=1;j<=13;j++)
      {
         s+=n/x;
         x*=5;
      }
      printf("%d\n",s);
   }
   system("pause");
   return(0);
}
