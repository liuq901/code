#include <cstdio>
#include <cstdlib>
#include <cstring>
int flag,f[100],a[100][100];
int main()
{
   void floodfill(int,int);
   int n,x,i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      a[i][0]=0;
   for (i=1;i<=n;i++)
      while (1)
      {
         scanf("%d",&x);
         if (x==0)
            break;
         a[i][0]++;
         a[i][a[i][0]]=x;
         a[x][0]++;
         a[x][a[x][0]]=i;
      }
   flag=1;
   memset(f,-1,sizeof(f));
   for (i=1;i<=n;i++)
   {
      if (f[i]==-1)
      {
         f[i]=0;
         floodfill(i,0);
      }
      if (!flag)
         break;
   }
   if (n==0)
      flag=0;
   if (flag)
   {
      for (i=1;i<=n;i++)
         printf("%d",f[i]);
      printf("\n");
   }
   else
      printf("-1\n");
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   int i;
   for (i=1;i<=a[x][0];i++)
   {
      if (a[x][i]==father)
         continue;
      if (f[a[x][i]]==f[x])
      {
         flag=0;
         return;
      }
      if (f[a[x][i]]==-1)
      {
         f[a[x][i]]=1-f[x];
         floodfill(a[x][i],x);
      }
   }
}
