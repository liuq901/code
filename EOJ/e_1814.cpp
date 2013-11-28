#include <cstdio>
#include <cstdlib>
int b[1100],a[2100][2];
int main()
{
   bool dfs(int,int);
   int n,root;
   scanf("%d%d",&n,&root);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y,a[i][1]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
   }
   printf("%s\n",dfs(root,0)?"yes":"no");
   system("pause");
   return(0);
}
bool dfs(int x,int father)
{
   int sum=0;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      if (!dfs(y,x))
         return(false);
      sum++;
   }
   return(!sum || sum==2);
}
