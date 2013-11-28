#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef set <int>::iterator iter;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char b[1010][1010];
int ans[1000010],a[1010][1010];
set <int> s[1000010];
int main()
{
   int n,m;
   scanf("%d%d",&n,&m);
   gets(b[0]);
   for (int i=1;i<=n;i++)
      gets(b[i]+1);
   int t=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (j<m && b[i][j]=='.' && !a[i][j] && b[i][j+1]=='.' && !a[i][j+1])
            a[i][j]=a[i][j+1]=++t;
         if (i<n && b[i][j]=='.' && !a[i][j] && b[i+1][j]=='.' && !a[i+1][j])
            a[i][j]=a[i+1][j]=++t;
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (b[i][j]=='#' || a[i][j])
            continue;
         for (int k=0;k<4;k++)
         {
            int x=i+c[k][0],y=j+c[k][1];
            if (x>0 && x<=n && y>0 && y<=m && b[x][y]=='.')
            {
               a[i][j]=a[x][y];
               break;
            }
         }
         if (!a[i][j])
         {
            printf("-1\n");
            goto last;
         }
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         for (int k=0;k<4;k++)
         {
            if (b[i][j]=='#')
               continue;
            int x=i+c[k][0],y=j+c[k][1];
            if (x>0 && x<=n && y>0 && y<=m && b[x][y]=='.')
            {
               int p=a[i][j],q=a[x][y];
               if (p!=q)
                  s[max(p,q)].insert(min(p,q));
            }
         }
   for (int i=1;i<=t;i++)
   {
      bool g[10]={0};
      for (iter k=s[i].begin();k!=s[i].end();k++)
         g[ans[*k]]=true;
      for (int j=0;j<10;j++)
         if (!g[j])
         {
            ans[i]=j;
            break;
         }
   }
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
         printf("%c",b[i][j]=='#'?'#':ans[a[i][j]]+'0');
      printf("\n");
   }
last:
   system("pause");
   return(0);
}
