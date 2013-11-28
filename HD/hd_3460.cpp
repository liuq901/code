#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct trie
{
   char ch;
   int son,next;
};
trie a[500010];
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      int m=1,p=0;
      a[1].son=a[1].next=0;
      for (int i=1;i<=n;i++)
      {
         char s[60];
         scanf("%s",s);
         int len=strlen(s);
         p=max(p,len);
         int now=1;
         for (int i=0;i<len;i++)
         {
            int k=-1;
            for (int j=a[now].son;j;j=a[j].next)
               if (a[j].ch==s[i])
               {
                  k=j;
                  break;
               }
            if (k==-1)
            {
               if (!a[now].son)
                  a[now].son=++m;
               else
               {
                  int t=a[now].son;
                  while (a[t].next)
                     t=a[t].next;
                  a[t].next=++m;
               }
               a[m].ch=s[i];
               a[m].son=a[m].next=0;
               now=m;
            }
            else
               now=k;
         }
      }
      printf("%d\n",(m-1<<1)+n-p);
   }
   system("pause");
   return(0);
}
