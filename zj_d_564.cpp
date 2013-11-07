#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   while (1)
   {
      char s[10];
      scanf("%s",s);
      if (s[0]=='E')
         break;
      int x;
      scanf("%d",&x);
      if (s[0]=='B')
         printf("\"Basic\" can use Print n to show integer like %d.\n",x);
      else if (s[0]=='P')
         printf("\"Pascal\" can use Write(n); to show integer like %d.\n",x);
      else if (s[0]=='J')
         printf("\"Java\" can use System.out.print(n); to show integer like %d.\n",x);
      else if (strlen(s)==1)
         printf("\"C\" can use printf(\"%%d\",n); to show integer like %d.\n",x);
      else
         printf("\"C++\" can use cout<<n; to show integer like 100.\n",x);
   }
   system("pause");
   return(0);
}
