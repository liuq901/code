#include <cstdio>
#include <cstdlib>
#include <cctype>
const int c[]={0,1,2,3,2,1,2,3,4,2};
int main()
{
   int s=0;
   char ch;
   while (scanf("%c",&ch)!=EOF)
   {
      if (!isdigit(ch))
         break;
      s+=c[ch-'0'];
   }
   printf("%d\n",s);
   system("pause");
   return(0);
}
