#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[1010],s2[1010];
int f[1010][1010];
int main()
{
   while (1)
   {
      int K;
      scanf("%d",&K);
      if (!K)
         break;
      scanf("%s%s",s1,s2);
      int n=strlen(s1),m=strlen(s2);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            for (int k=1;;k++)
            {
               if (i-k<0 || j-k<0 || s1[i-k]!=s2[j-k])
                  break;
               if (k>=K)
                  f[i][j]=max(f[i][j],f[i-k][j-k]+k);
            }
         }
      printf("%d\n",f[n][m]);
   }
   system("pause");
   return(0);
}
