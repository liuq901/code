#include <cstdio>
#include <cstdlib>
const int x=26,y=32767,q=99997;
int n,m,p1,q1,p2,q2;
long long a[501][501],b[501][501],c[250001][4];
char s[501][501];
int main()
{
   int work(int);
   int i,j,l,r,ans,mid;
   scanf("%d%d%*c",&n,&m);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m;j++)
         scanf("%c",&s[i][j]);
      scanf("%*c");
   }
   l=1;
   if (n==m)
      r=n-1;
   else if (n<m)
      r=n;
   else
      r=m;
   ans=0;
   while (l<=r)
   {
      mid=(l+r)/2;
      if (work(mid))
      {
         ans=mid;
         l=mid+1;
      }
      else
         r=mid-1;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int work(int len)
{
   void sort(int,int);
   int check(int,int,int,int,int);
   int i,j,k;
   long long t;
   t=1;
   for (i=1;i<=len-1;i++)
      t=t*x%q;
   for (i=1;i<=n;i++)
   {
      a[i][1]=0;
      for (j=1;j<=len;j++)
         a[i][1]=(a[i][1]*x+s[i][j]-'a')%q;
      for (j=2;j<=m-len+1;j++)
      {
         a[i][j]=(x*(a[i][j-1]-t*(s[i][j-1]-'a')%q)+s[i][j+len-1]-'a')%q;
         while (a[i][j]<0)
            a[i][j]+=q;
      }
   }
   t=1;
   for (i=1;i<=len-1;i++)
      t=t*y%q;
   for (i=1;i<=m-len+1;i++)
   {
      b[1][i]=0;
      for (j=1;j<=len;j++)
         b[1][i]=(b[1][i]*y+a[j][i])%q;
      for (j=2;j<=n-len+1;j++)
      {
         b[j][i]=(y*(b[j-1][i]-t*a[j-1][i]%q)+a[j+len-1][i])%q;
         while (b[j][i]<0)
            b[j][i]+=q;
      }
   }
   k=0;
   for (i=1;i<=n-len+1;i++)
      for (j=1;j<=m-len+1;j++)
      {
         k++;
         c[k][0]=a[i][j];
         c[k][1]=b[i][j];
         c[k][2]=i;
         c[k][3]=j;
      }
   sort(1,k);
   for (i=1;i<=k-1;i++)
      for (j=i+1;j<=k;j++)
         if (c[i][0]==c[j][0] && c[i][1]==c[j][1])
         {
            if (check(c[i][2],c[i][3],c[j][2],c[j][3],len))
            {
               p1=c[i][2];
               q1=c[i][3];
               p2=c[j][2];
               q2=c[j][3];
               return(1);
            }
         }
         else
            break;
   return(0);
}
void sort(int l,int r)
{
   int i,j,k;
   long long x,y,t;
   i=l;
   j=r;
   x=c[(l+r)/2][0];
   y=c[(l+r)/2][1];
   while (i<=j)
   {
      while (c[i][0]<x || c[i][0]==x && c[i][1]<y)
         i++;
      while (c[j][0]>x || c[j][0]==x && c[j][1]>y)
         j--;
      if (i<=j)
      {
         for (k=0;k<=3;k++)
            t=c[i][k],c[i][k]=c[j][k],c[j][k]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int check(int x1,int y1,int x2,int y2,int len)
{
   int i,j,x,y,p,q;
   x=x1-1;
   y=x2-1;
   for (i=1;i<=len;i++)
   {
      p=y1-1;
      q=y2-1;
      x++;
      y++;
      if (a[x][y1]!=a[y][y2])
         return(0);
      for (j=1;j<=len;j++)
      {
         p++;
         q++;
         if (s[x][p]!=s[y][q])
            return(0);
      }
   }
   return(1);
}
