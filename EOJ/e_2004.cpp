#include <cstdio>
#include <cstdlib>
int main()
{
   bool check(int);
   for (int i=1000;i<=9999;i++)
      if (check(i))
         printf("%d\n",i);
   system("pause");
   return(0);
}
bool check(int x)
{
   int y=x,s=0;
   for (int i=1;i<=4;i++)
   {
      int p=x%10;
      x/=10;
      s+=p*p*p*p;
   }
   return(s==y);
}
