#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
   bool first=true;
   while (1)
   {
      char ch;
      cin>>ch;
      if (ch=='@')
         break;
      int n;
      scanf("%d",&n);
      if (!first)
         printf("\n");
      first=false;
      for (int i=1;i<=n-1;i++)
         printf(" ");
      printf("%c\n",ch);
      if (n==1)
         continue;
      for (int i=1;i<=n-2;i++)
      {
         for (int j=1;j<n-i;j++)
            printf(" ");
         printf("%c",ch);
         for (int j=1;j<=(i<<1)-1;j++)
            printf(" ");
         printf("%c\n",ch);
      }
      for (int i=1;i<=(n<<1)-1;i++)
         printf("%c",ch);
      printf("\n");
   }
   system("pause");
   return(0);
}
