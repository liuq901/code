#include <cstdio>
#include <cstdlib>
int s[101],f[101][101];
int main()
{
   void init();
   init();
   int n;
   while (scanf("%d",&n)!=EOF)
      printf("%d\n",s[n]+1);
   system("pause");
   return(0);
}
void init()
{
   f[1][1]=0;
   for (int i=2;i<=100;i++)
      for (int j=1;j<=i/2;j++)
      {
         for (int k=j;k<=(i-j)/2;k++)
            f[i][j]+=f[i-j][k];
         s[i]+=++f[i][j];
      }
}
