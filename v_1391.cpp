#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,a[2001][2001],f[2001];
int main()
{
   void dijkstra();
   int x,y,z,i;
   scanf("%d",&n);
   i=0;
   memset(a,0,sizeof(a));
   while (1)
   {
      scanf("%d%d%d",&x,&y,&z);
      if (x==0 && y==0 && z==0)
         break;
      a[x][y]=z;
      i++;
   }
   m=i;
   dijkstra();
   for (i=2;i<=n;i++)
      printf("%d\n",f[i]);
   system("pause");
   return(0);
}
void dijkstra()
{
   int min(int,int);
   int i,j,k,max;
   int flag[2001];
   memset(f,0,sizeof(f));
   memset(flag,0,sizeof(flag));
   flag[1]=1;
   f[1]=0;
   for (i=2;i<=n;i++)
      f[i]=a[1][i];
   for (i=2;i<=n-1;i++)
   {
      k=0;
      max=0;
      for (j=2;j<=n;j++)
         if (!flag[j] && f[j]>max)
         {
            max=f[j];
            k=j;
         }
      if (k==0)
         break;
      flag[k]=1;
      for (j=2;j<=n;j++)
         if (min(a[k][j],f[k])>f[j])
            f[j]=min(a[k][j],f[k]);
   }
}
int min(int a,int b)
{
   if (a<b)
      return(a);
   else
      return(b);
}
