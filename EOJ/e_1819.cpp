#include <cstdio>
#include <cstdlib>
#include <cctype>
int a[1100000];
int main()
{
   void read(int &);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      int x;
      read(x);
      a[x]++;
   }
   int p=1,j=0;
   while (p<=m)
   {
      if (a[j])
         printf("%d: %d\n",p++,j);
      j++;
   }
   system("pause");
   return(0);
}
void read(int &x)
{
   x=0;
   char ch=0;
   while (!isdigit(ch))
      ch=getchar();
   while (1)
   {
      x=x*10+ch-'0';
      ch=getchar();
      if (!isdigit(ch))
         return;
   }
}
