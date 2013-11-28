#include <cstdio>
#include <cstdlib>
int main()
{
   int n,s=0;
   scanf("%d",&n);
label:
   if (n)
   {
      int x;
      scanf("%d",&x);
      s+=x;
      n--;
      goto label;
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
