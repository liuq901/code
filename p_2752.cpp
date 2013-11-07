#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[400010];
int next[400010],ans[400010];
int main()
{
   void kmp();
   while (scanf("%s",s)!=EOF)
      kmp();
   system("pause");
   return(0);
}
void kmp()
{
   int l,i,k;
   l=strlen(s);
   next[0]=k=-1;
   for (i=1;i<l;i++)
   {
      while (k>=0 && s[k+1]!=s[i])
         k=next[k];
      if (s[i]==s[k+1])
         k++;
      next[i]=k;
   }
   ans[0]=1;
   ans[1]=l;
   i=l-1;
   while (i!=-1)
   {
      if (next[i]!=-1)
      {
         ans[0]++;
         ans[ans[0]]=next[i]+1;
      }
      i=next[i];
   }
   for (i=ans[0];i>1;i--)
      printf("%d ",ans[i]);
   printf("%d\n",ans[1]);
}
