#include <cstdio>
#include <cstdlib>
int main()
{
   int A,B,C;
   while (scanf("%d%d%d",&A,&B,&C)==3)
   {
      long long a=A,b=B,c=C;
      if (a<b && a<c)
      {
         if (b<c)
            b+=a;
         else if (c<b)
            c+=a;
         printf("%c\n",b<c?'C':'B');
      }
      else if (b<a && b<c)
      {
         if (a<c)
            a+=b;
         else if (c<a)
            c+=b;
         printf("%c\n",a<c?'C':'A');
      }
      else if (c<a && c<b)
      {
         if (a<b)
            a+=c;
         else if (b<a)
            b+=c;
         printf("%c\n",a<b?'B':'A');
      }
      else if (a>b && a>c)
         printf("A\n");
      else if (b>a && b>c)
         printf("B\n");
      else if (c>a && c>b)
         printf("C\n");
   }
   system("pause");
   return(0);
}
