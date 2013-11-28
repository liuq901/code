#include <cstdio>
#include <cstdlib>
int main()
{
   int A,a,B,b,p;
   scanf("%d%d%d%d%d",&A,&a,&B,&b,&p);
   if (A<=b)
      A=a=0;
   if (B<=a)
      B=b=0;
   printf("%s\n",A+B<=p?"Yes":"No");
   system("pause");
   return(0);
}
