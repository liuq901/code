#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef int matrix[30][30];
int n,m;
matrix a;
int main()
{
   int calc(int,int);
   bool check(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%d%d%*c",&n,&m);
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int x1,y1,x2,y2,x3,y3,x4,y4;
            scanf("%*c%*c%d%*c%d%*c%*c%*c%d%*c%d%*c%*c%*c%d%*c%d%*c%*c%*c%d%*c%d%*c%*c%*c",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            if (i==n && j==m)
               continue;
            a[calc(i,j)][calc(x1,y1)]=1;
            a[calc(i,j)][calc(x2,y2)]=1;
            a[calc(i,j)][calc(x3,y3)]=1;
            a[calc(i,j)][calc(x4,y4)]=1;
         }
      int tot=0;
      for (int i=0;i<=(n*m<<1)+3;i++)
         tot+=check(i);
      int Q;
      scanf("%d",&Q);
      while (Q--)
      {
         int x;
         scanf("%d",&x);
         if (!check(x))
            printf("False\n");
         else
            printf("%s\n",tot==1?"True":"Maybe");
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
int calc(int x,int y)
{
   return((x-1)*m+y);
}
matrix ans;
bool check(int x)
{
   void multiply(int);
   memset(ans,0,sizeof(ans));
   for (int i=1;i<=n*m;i++)
      ans[i][i]=1;
   multiply(x);
   return(ans[1][n*m]);
}
void multiply(int x)
{
   void work(matrix,matrix);
   if (!x)
      return;
   multiply(x>>1);
   work(ans,ans);
   if (x&1)
      work(ans,a);
}
void work(matrix a,matrix b)
{
   matrix c={0};
   for (int i=1;i<=n*m;i++)
      for (int j=1;j<=n*m;j++)
         for (int k=1;k<=n*m;k++)
            c[i][j]+=a[i][k]*b[k][j];
   for (int i=1;i<=n*m;i++)
      for (int j=1;j<=n*m;j++)
         ans[i][j]=c[i][j]>0;
}
