#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char a[270],s[270];
vector <int> b[270];
int f[270];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",a);
      int n=strlen(a);
      for (int i=1;i<=n;i++)
         b[i].clear();
      int m;
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
      {
         scanf("%s",s);
         int len=strlen(s);
         for (int j=0;j<n;j++)
         {
            if (j+len>n)
               break;
            bool flag=true;
            for (int k=0;k<len;k++)
               if (a[j+k]!=s[k])
               {
                  flag=false;
                  break;
               }
            if (flag)
               b[j+len].push_back(len);
         }
      }
      memset(f,63,sizeof(f));
      f[0]=0;
      for (int i=1;i<=n;i++)
         for (int j=0;j<b[i].size();j++)
            f[i]=min(f[i],f[i-b[i][j]]+1);
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
