#include <cstdio>
#include <cstdlib>
char ans[1000];
int main()
{
   void search(int,int,int);
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      search(n,m,0);
      printf("\n");
   }
   system("pause");
   return(0);
}
void search(int n,int m,int dep)
{
   if (!n && !m)
   {
      ans[dep]='\0';
      printf("%s\n",ans);
      return;
   }
   if (n)
   {
      ans[dep]='S';
      search(n-1,m,dep+1);
   }
   if (m)
   {
      ans[dep]='L';
      search(n,m-1,dep+1);
   }
}
