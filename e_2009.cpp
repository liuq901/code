#include <cstdio>
#include <cstdlib>
bool f[100010];
int main()
{
   int n;
   scanf("%d",&n);
   while (n--)
   {
      int x;
      scanf("%d",&x);
      f[x]=true;
   }
   scanf("%d",&n);
   while (n--)
   {
      int x;
      scanf("%d",&x);
      printf("%s\n",f[x]?"yes!":"no!");
   }
   system("pause");
   return(0);
}
