#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const double eps=1e-5;
const int c[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
const char s[4]={'S','N','W','E'};
double d[1000],a[31][31];
char map[33][33];
int n;
int main()
{
   void init();
   bool work(int,bool);
   while (1)
   {
      scanf("%d%*c",&n);
      if (!n)
         break;
      init();
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=n;j++)
            scanf("%c",&map[i][j]);
         scanf("%*c");
         map[0][i]=map[i][0]=map[n+1][i]=map[i][n+1]='*';
      }
      int l=1,r=n*n,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (work(mid,false))
         {
            ans=mid;
            l=mid+1;
         }
         else
            r=mid-1;
      }
      work(ans,true);
   }
   system("pause");
   return(0);
}
void init()
{
   void sort(int,int);
   int s=0;
   for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
      {
         d[++s]=sqrt(double(i*i+j*j));
         a[i][j]=d[s];
      }
   sort(1,n*n);
}
void sort(int l,int r)
{
   int i,j;
   double x,t;
   i=l,j=r;
   x=d[l+r>>1];
   while (i<=j)
   {
      while (d[i]<x)
         i++;
      while (d[j]>x)
         j--;
      if (i<=j)
      {
         t=d[i],d[i]=d[j],d[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
bool f[31][31][31][31];
int q[810001][5];
char stack[810001],st[810001][2];
bool work(int p,bool flag)
{
   double limit=d[p]-eps;
   memset(f,0,sizeof(f));
   int x1,y1,x2,y2,x3,y3,x4,y4;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (map[i][j]=='H')
            x1=i,y1=j;
         if (map[i][j]=='h')
            x2=i,y2=j;
         if (map[i][j]=='S')
            x3=i,y3=j;
         if (map[i][j]=='s')
            x4=i,y4=j;
      }
   if (a[abs(x1-x2)][abs(y1-y2)]<limit)
      return(false);
   f[x1][y1][x2][y2]=true;
   q[1][0]=x1,q[1][1]=y1,q[1][2]=x2,q[1][3]=y2;
   int l,r;
   l=r=1;
   while (l<=r)
   {
      bool ok=false;
      for (int i=0;i<4;i++)
      {
         int x=q[l][0],y=q[l][1];
         bool flag1=false;
         if (x!=x3 || y!=y3)
         {
            x+=c[i][0];
            y+=c[i][1];
            flag1=true;
         }
         if (map[x][y]=='*' || map[x][y]=='h' || map[x][y]=='s')
            continue;
         for (int j=0;j<4;j++)
         {
            int x0=q[l][2],y0=q[l][3];
            bool flag2=false;
            if (x0!=x4 || y0!=y4)
            {
               x0+=c[j][0];
               y0+=c[j][1];
               flag2=true;
            }
            if (map[x0][y0]=='*' || map[x0][y0]=='H' || map[x0][y0]=='S')
               continue;
            if (a[abs(x-x0)][abs(y-y0)]<limit || f[x][y][x0][y0])
               continue;
            f[x][y][x0][y0]=true;
            q[++r][0]=x;
            q[r][1]=y;
            q[r][2]=x0;
            q[r][3]=y0;
            q[r][4]=l;
            if (flag1)
               st[r][0]=s[i];
            else
               st[r][0]=0;
            if (flag2)
               st[r][1]=s[j];
            else
               st[r][1]=0;
            if (x==x3 && y==y3 && x0==x4 && y0==y4)
            {
               ok=true;
               break;
            }
         }
         if (ok)
            break;
      }
      if (ok)
         break;
      l++;
   }
   if (!f[x3][y3][x4][y4])
      return(false);
   if (!flag)
      return(true);
   printf("%.2lf\n",limit);
   int tot=0;
   for (int i=r;i>1;i=q[i][4])
      stack[++tot]=st[i][0];
   for (int i=tot;i>=1;i--)
   {
      if (!stack[i])
         break;
      printf("%c",stack[i]);
   }
   printf("\n");
   tot=0;
   for (int i=r;i>1;i=q[i][4])
      stack[++tot]=st[i][1];
   for (int i=tot;i>=1;i--)
   {
      if (!stack[i])
         break;
      printf("%c",stack[i]);
   }
   printf("\n");
}
