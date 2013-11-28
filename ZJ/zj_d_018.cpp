#include <cstdio>
#include <cstdlib>
int main()
{
   void print(double);
   char ch;
   int n;
   double x,y,s;
   x=y=0;
   while (scanf("%d",&n)!=EOF)
   {
      scanf("%*c%lf",&s);
      if (n%2==1)
         x+=s;
      else
         y+=s;
      scanf("%c",&ch);
      if (ch=='\n')
      {
         print(x-y);
         x=y=0;
      }
   }
   system("pause");
   return(0);
}
void print(double x)
{
   int n;
   n=(int)x;
   printf("%d",n);
   x-=n;
   x*=10000000;
   n=(int)x;
   if (n<0)
      n=-n;
   while (n!=0 && n%10==0)
      n/=10;
   if (n!=0)
      printf(".%d",n);
   printf("\n");
}
