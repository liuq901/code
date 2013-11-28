#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> a;
int main()
{
   int T,sum=0,tot=0;
   scanf("%d",&T);
   while (T--)
   {
      char s[10];
      int x;
      scanf("%s%d",s,&x);
      if (s[0]=='i')
      {
         int p=++a[x];
         if (p==2)
            sum++;
         if (p==1)
            tot++;
      }
      else
      {
         if (!a[x])
            goto print;
         int p=--a[x];
         if (p==1)
            sum--;
         if (!p)
            tot--;
      }
print:
      bool homo=sum,hetero=tot>1;
      if (homo && hetero)
         printf("both\n");
      if (homo && !hetero)
         printf("homo\n");
      if (!homo && hetero)
         printf("hetero\n");
      if (!homo && !hetero)
         printf("neither\n");
   }
   system("pause");
   return(0);
}
