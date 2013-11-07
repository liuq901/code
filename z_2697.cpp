#include <cstdio>
#include <cstdlib>
int main()
{
   void work(int,int);
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
      work(n,m);
   system("pause");
   return(0);
}
int q[1001],ans[1001][2],d[1001][2],a[1001][1001],b[1001][1001],c[10001][6];
bool f[1001][1001];
void work(int n,int m)
{
   void sort(int,int);
   for (int i=1;i<=n;i++)
   {
      a[i][0]=b[i][0]=d[i][0]=d[i][1]=0;
      for (int j=1;j<=n;j++)
         f[i][j]=false;
   }
   int sum=0;
   f[0][0]=true;
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (f[x][y] && z==1)
         f[0][0]=false;
      c[i][0]=x,c[i][1]=y,c[i][2]=z,c[i][3]=i;
      f[x][y]=true;
      a[x][0]++;
      a[x][a[x][0]]=y;
      d[y][0]++;
      if (z==0)
      {
         b[x][0]++;
         b[x][b[x][0]]=y;
         d[y][1]++;
      }
      else
      {
         b[y][0]++;
         b[y][b[y][0]]=x;
         d[x][1]++;
         sum++;
      }
   }
   if (!f[0][0])
   {
      printf("-1\n\n");
      return;
   }
   int r=0;
   for (int i=1;i<=n;i++)
      if (d[i][0]==0)
      {
         r++;
         q[r]=i;
      }
   int l=1;
   while (l<=r)
   {
      int x=q[l];
      ans[x][0]=l;
      for (int i=1;i<=a[x][0];i++)
      {
         d[a[x][i]][0]--;
         if (d[a[x][i]][0]==0)
         {
            r++;
            q[r]=a[x][i];
         }
      }
      l++;
   }
   r=0;
   for (int i=1;i<=n;i++)
      if (d[i][1]==0)
      {
         r++;
         q[r]=i;
      }
   l=1;
   while (l<=r)
   {
      int x=q[l];
      ans[x][1]=l;
      for (int i=1;i<=b[x][0];i++)
      {
         d[b[x][i]][1]--;
         if (d[b[x][i]][1]==0)
         {
            r++;
            q[r]=b[x][i];
         }
      }
      l++;
   }
   for (int i=1;i<=m;i++)
   {
      c[i][4]=ans[c[i][0]][1];
      c[i][5]=ans[c[i][1]][0];
   }
   sort(1,m);
   int s=0;
   printf("%d\n",sum);
   for (int i=1;i<=m;i++)
      if (c[i][2]==1)
      {
         s++;
         printf("%d",c[i][3]);
         if (s==sum)
         {
            printf("\n\n");
            break;
         }
         else
            printf(" ");
      }
   if (sum==0)
      printf("\n");
}
void sort(int l,int r)
{
   int i=l,j=r,x=c[(l+r)/2][4],y=c[(l+r)/2][5];
   while (i<=j)
   {
      while (c[i][4]>x || c[i][4]==x && c[i][5]<y)
         i++;
      while (c[j][4]<x || c[j][4]==x && c[j][5]>y)
         j--;
      if (i<=j)
      {
         int t;
         t=c[i][2],c[i][2]=c[j][2],c[j][2]=t;
         t=c[i][3],c[i][3]=c[j][3],c[j][3]=t;
         t=c[i][4],c[i][4]=c[j][4],c[j][4]=t;
         t=c[i][5],c[i][5]=c[j][5],c[j][5]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
