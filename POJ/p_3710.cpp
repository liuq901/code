#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int work();
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int s=0;
      for (int i=1;i<=n;i++)
         s^=work();
      if (s==0)
         printf("Harry\n");
      else
         printf("Sally\n");
   }
   system("pause");
   return(0);
}
int n,a[101][101];
int work()
{
   int tree_dp();
   int m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      a[i][0]=0;
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[x][0]++;
      a[x][a[x][0]]=y;
      a[y][0]++;
      a[y][a[y][0]]=x;
   }
   return(tree_dp());
}
int tot,f[101],stack[101];
int tree_dp()
{
   int count(int,int);
   tot=stack[1]=1;
   memset(f,-1,sizeof(f));
   f[1]=0;
   return(count(1,0));
}
int count(int x,int father)
{
   if (a[x][0]==2 && a[x][1]==father && a[x][2]==father)
   {
      f[x]=father;
      return(-1);
   }
   int p=0;
   for (int i=1;i<=a[x][0];i++)
   {
      if (a[x][i]==father || f[a[x][i]]>0)
         continue;
      if (f[a[x][i]]==0)
      {
         f[x]=a[x][i];
         int k=tot,s=1;
         while (stack[k]!=a[x][i])
         {
            k--;
            s++;
         }
         if (s%2==0)
            return(-1);
         else
            return(0);
      }
      tot++;
      stack[tot]=a[x][i];
      f[a[x][i]]=0;
      int k=count(a[x][i],x);
      tot--;
      if (f[a[x][i]]>0 && f[a[x][i]]!=x)
      {
         f[x]=f[a[x][i]];
         return(k);
      }
      p^=(k+1);
   }
   return(p);
}
