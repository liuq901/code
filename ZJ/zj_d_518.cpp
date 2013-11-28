#include <cstdio>
#include <cstdlib>
#include <cstring>
struct trie
{
   char ch;
   int danger,son,next;
};
trie a[200010];
int n,m;
bool flag;
int main()
{
   int insert(int,char *,int,int);
   int T;
   while (scanf("%d",&T)==1)
   {
      n=0,m=1;
      memset(a,0,sizeof(a));
      while (T--)
      {
         char s[30];
         scanf("%s",s);
         flag=true;
         int p=insert(1,s,0,strlen(s));
         printf("%s %d\n",flag?"New!":"Old!",p);
      }
   }
   system("pause");
   return(0);
}
int insert(int x,char *s,int t,int l)
{
   for (int i=a[x].son;i;i=a[i].next)
      if (a[i].ch==s[t])
      {
         if (t==l-1)
         {
            flag=false;
            if (!a[i].danger)
            {
               flag=true;
               a[i].danger=++n;
            }
            return(a[i].danger);
         }
         return(insert(i,s,t+1,l));
      }
   if (!a[x].son)
      a[x].son=++m;
   else
   {
      int p=a[x].son;
      while (a[p].next)
         p=a[p].next;
      a[p].next=++m;
   }
   a[m].ch=s[t];
   if (t==l-1)
   {
      a[m].danger=++n;
      return(n);
   }
   return(insert(m,s,t+1,l));
}
