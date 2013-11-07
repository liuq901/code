#include <cstdio>
#include <cstdlib>
#include <cstring>
struct trie
{
   int s,x,son[10];
};
trie a[400001];
int ans=0,tot=1;
int main()
{
   void insert(char *);
   int n;
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   for (int i=1;i<=n;i++)
   {
      char s[20];
      scanf("%s",s);
      insert(s);
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void insert(char *s)
{
   int x=1,l=strlen(s);
   if (l==2)
      return;
   for (int i=2;i<=l-1;i++)
   {
      int k,t=s[i]-'0';
      if (s[i+1]>='5')
         k=(t+1)%10;
   }
}

      
