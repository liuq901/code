#include <cstdio>
#include <cstdlib>
int main()
{
   int x,s,n,k,i;
   char ch;
   scanf("%d%*c",&n);
   k=0;
   while (1)
   {
      scanf("%c",&ch);
      if (ch=='!')
         k++;
      else
         break;
   }
   if (n%k==0)
      x=k;
   else
      x=n%k;
   s=1;
   while (1)
   {
      s*=n;
      if (n==x)
         break;
      n-=k;
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
