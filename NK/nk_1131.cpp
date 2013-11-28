#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char a[2010],b[2010];
int f[2010][2010];
int main()
{
   while (gets(a) && gets(b))
   {
      int n=strlen(a),m=strlen(b);
      memset(f,63,sizeof(f));
      for (int i=1;i<=n;i++)
         f[i][0]=i;
      for (int i=1;i<=m;i++)
         f[0][i]=i;
      f[0][0]=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            f[i][j]=min(min(f[i-1][j],f[i][j-1])+1,f[i-1][j-1]+(a[i-1]!=b[j-1]));
      printf("%d\n",f[n][m]);
   }
   system("pause");
   return(0);
}
