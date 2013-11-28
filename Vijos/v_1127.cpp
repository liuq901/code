#include <cstdio>
#include <cstdlib>
int main()
{
  double s=0;
  int i=0,k;
  scanf("%d",&k);
  while (1)
  {
     i++;
     s+=1.0/i;
     if (s>k)
        break;
   }
   printf("%d\n",i);
   system("pause");
   return(0);
}
