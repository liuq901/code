#include <cstdio>
#include <cstdlib>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool f[1010][1010];
int ans[26000],q[1000001][4];
int main()
{
   int n,m,p,t;
   scanf("%d%d%d%d",&n,&m,&p,&t);
   for (int i=1;i<=n;i++)
      f[i][0]=f[i][m+1]=true;
   for (int i=1;i<=m;i++)
      f[0][i]=f[n+1][i]=true;
   int l,r;
   l=1,r=0;
   for (int i=1;i<=p;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      f[x][y]=true;
      q[++r][0]=x,q[r][1]=y,q[r][2]=i,q[r][3]=0;
      ans[i]=1;
   }
   while (l<=r)
   {
      if (q[l][3]!=t)
         for (int i=0;i<4;i++)
         {
            int x=q[l][0]+c[i][0],y=q[l][1]+c[i][1];
            if (f[x][y])
               continue;
            f[x][y]=true;
            q[++r][0]=x,q[r][1]=y,q[r][2]=q[l][2],q[r][3]=q[l][3]+1;
            ans[q[r][2]]++;
         }
      l++;
   }
   for (int i=1;i<=p;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
