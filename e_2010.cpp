#include <cstdio>
#include <cstdlib>
int main()
{
   void print(int,char);
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
      {
         print(n-i+1,' ');
         print((i<<1)-1,'*');
         print(n-i+1,' ');
         printf("\n");
      }
      print((n<<1)+1,'*');
      printf("\n");
      for (int i=n;i;i--)
      {
         print(n-i+1,' ');
         print((i<<1)-1,'*');
         print(n-i+1,' ');
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
void print(int x,char ch)
{
   while (x--)
      printf("%c",ch);
}
