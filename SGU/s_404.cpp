#include <cstdio>
#include <cstdlib>
int main()
{
   int n,m,i;
   int s[101][101];
   scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++)
      scanf("%s",s[i]);
   n%=m;
   if (n==0)
      n=m;
   printf("%s\n",s[n]);
   system("pause");
   return(0);
}
