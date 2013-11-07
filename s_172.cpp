#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,flag,f[201],a[201][201];
int main()
{
   void floodfill(int);
   int i,m,x,y,s,t;
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      a[x][y]=a[y][x]=1;
   }
   memset(f,0,sizeof(f));
   flag=1;
   for (i=1;i<=n;i++)
      if (!f[i])
      {
         f[i]=1;
         floodfill(i);
      }
   if (!flag)
      printf("no\n");
   else
   {
      printf("yes\n");
      s=0;
      for (i=1;i<=n;i++)
         if (f[i]==1)
            s++;
      printf("%d\n",s);
      t=0;
      for (i=1;i<=n;i++)
         if (f[i]==1)
         {
            t++;
            printf("%d",i);
            if (t==s)
            {
               printf("\n");
               break;
            }
            printf(" ");
         }
   }
   system("pause");
   return(0);
}
void floodfill(int x)
{
   int i;
   for (i=1;i<=n;i++)
   {
      if (!flag)
         return;
      if (!a[x][i])
         continue;
      if (!f[i])
      {
         f[i]=3-f[x];
         floodfill(i);
      }
      if (f[i]==f[x])
      {
         flag=0;
         return;
      }
   }
}
