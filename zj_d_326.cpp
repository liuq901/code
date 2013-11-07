#include <cstdio>
#include <cstdlib>
const unsigned int m=4294967295u;
int main()
{
   void print(unsigned int);
   unsigned int n;
   int a,b;
   while (scanf("%u%d%d",&n,&a,&b)!=EOF)
   {
      unsigned int p;
      p=1u<<a; 
      if (b)
         print(n|p);
      else
      {
         p=m-p;
         print(n&p);
      }
   }
   system("pause");
   return(0);
}
void print(unsigned int p)
{
   for (int i=31;i>=0;i--)
      printf("%d",p>>i&1);
   printf("\n");
}
