#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll f[30][30];
int main()
{
   f[1][0]=1;
   for (int i=1;i<=21;i++)
      for (int j=1;j<=21;j++)
         f[i][j]=f[i-1][j]+f[i][j-1];
   printf("%lld\n",f[21][21]);
   system("pause");
   return(0);
}
