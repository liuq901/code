#include <cstdio>
#include <cstdlib>
char s[10];
int main()
{
   while (scanf("%s",s)==1)
   {
      for (int i=0;i<6;i++)
         printf("%d",abs(s[i]-s[i+1]));
      printf("\n");
   }
   system("pause");
   return(0);
}
