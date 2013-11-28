#include <cstdio>
#include <cstdlib>
const int q=1024523;
char a[510],b[510];
int f[2][501][501];
int main()
{
   void work(int &,int);
   int n,m,ans;
   scanf("%d%d%s%s",&n,&m,&a,&b);
   f[0][0][0]=1;
   for (int i=0;i<=n;i++)
      for (int j=0;j<=m;j++)
         for (int k=0;k<=n;k++)
         {
            if (!f[i&1][j][k])
               continue;
            int t=f[i&1][j][k],l=i+j-k;
            if (i<n && k<n && a[i]==a[k])
               work(f[i+1&1][j][k+1],t);
            if (i<n && l<m && a[i]==b[l])
               work(f[i+1&1][j][k],t);
            if (k<n && j<m && a[k]==b[j])
               work(f[i&1][j+1][k+1],t);
            if (j<m && l<m && b[j]==b[l])
               work(f[i&1][j+1][k],t);
            ans=t;
            f[i&1][j][k]=0;
         }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void work(int &a,int b)
{
   a+=b;
   if (a>=q)
      a-=q;
}
