#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,b[7],f[7],ans[101],a[7][7],c[101][2];
int main()
{
   int i,j,x,y,t,flag;
   void floodfill(int,int),work();
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&x,&y);
      a[x][y]++;
      a[y][x]++;
      c[i][0]=x;
      c[i][1]=y;
      b[x]++;
      b[y]++;
   }
   memset(f,-1,sizeof(f));
   for (i=0;i<=6;i++)
      if (f[i]==-1)
         floodfill(i,i);
   t=0;
   flag=1;
   for (i=0;i<=6;i++)
   {
      if (b[i]%2==1)
         t++;
      for (j=0;j<=6;j++)
         if (b[i]>0 && b[j]>0 && f[i]!=f[j])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (t!=2 && t!=0)
      flag=0;
   if (!flag)
      printf("No solution\n");
   else
      work();
   system("pause");
   return(0);
}
void floodfill(int x,int t)
{
   int i;
   f[x]=t;
   for (i=0;i<=6;i++)
      if (f[i]==-1 && a[x][i]>0)
         floodfill(i,t);
}
void work()
{
   void search(int),print();
   int i,x;
   for (i=0;i<=6;i++)
   {
      if (b[i]!=0)
         x=i;
      if (b[i]%2==1)
         break;
   }
   ans[0]=0;
   search(x);
   print();
}
void search(int x)
{
   int i;
   for (i=0;i<=6;i++)
      if (a[x][i]>0)
      {
         a[x][i]--;
         a[i][x]--;
         search(i);
      }
   ans[0]++;
   ans[ans[0]]=x;
}
void print()
{
   int i,j;
   int f[101];
   memset(f,0,sizeof(f));
   for (i=1;i<=ans[0]-1;i++)
      for (j=1;j<=n;j++)
      {
         if (f[j])
            continue;
         if (c[j][0]==ans[i] && c[j][1]==ans[i+1])
         {
            printf("%d +\n",j);
            f[j]=1;
            break;
         }
         if (c[j][0]==ans[i+1] && c[j][1]==ans[i])
         {
            printf("%d -\n",j);
            f[j]=1;
            break;
         }
      }
}
