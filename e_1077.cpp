#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
basic_string <int> a[1010];
int f[100010];
int main()
{
   while (1)
   {
      int m,n,Q;
      scanf("%d%d",&m,&n);
      if (!m && !n)
         break;
      scanf("%d",&Q);
      for (int i=1;i<=m;i++)
         a[i].clear();
      memset(f,0,sizeof(f));
      while (Q--)
      {
         char op[10];
         scanf("%s",op);
         if (op[0]=='B')
         {
            int x,y;
            scanf("%d%d",&x,&y);
            if (f[y])
               printf("The book is not in the library now\n");
            else if (a[x].size()==9)
               printf("You are not allowed to borrow any more\n");
            else
            {
               f[y]=x;
               a[x].push_back(y);
               printf("Borrow success\n");
            }
         }
         else if (op[0]=='R')
         {
            int x;
            scanf("%d",&x);
            if (!f[x])
               printf("The book is already in the library\n");
            else
            {
               int p=f[x];
               for (int i=0;i<a[p].size();i++)
                  if (a[p][i]==x)
                     a[p].erase(i,1);
               f[x]=0;
               printf("Return success\n");
            }
         }
         else
         {
            int x;
            scanf("%d",&x);
            if (a[x].empty())
               printf("Empty\n");
            else
            {
               sort(a[x].begin(),a[x].end());
               for (int i=0;i<a[x].size();i++)
                  printf("%d%c",a[x][i],i==a[x].size()-1?'\n':' ');
            }
         }
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
