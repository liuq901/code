#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
const int inf=1<<30;
int k,m,n,ans=inf,a[2001][2001];
int main()
{
   void read(int &),init(),work(),change();
   scanf("%d%d%d%*c",&k,&m,&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         read(a[i][j]);
   init();
   work();
   change();
   init();
   work();
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void read(int &x)
{
   x=0;
   while (1)
   {
      char c=getchar();
      if (isdigit(c))
         x=x*10+c-'0';
      else
         return;
   }
}
int s[2001][2001];
void init()
{
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
}
void work()
{
   int get(int,int,int,int);
   for (int i=1;i<=n;i++)
   {
      int s=0,u=1,d=n,l=1,r=m;
      while (l<=r)
      {
         if (u>d || u>i)
         {
            s=inf;
            break;
         }
         while (l<=r)
         {
            int x=get(u,l,d,l);
            if (x>k)
               break;
            l++;
            s++;
         }
         while (l<=r)
         {
            int x=get(u,r,d,r);
            if (x>k)
               break;
            r--;
            s++;
         }
         if (l>r)
            break;
         int x=get(u,l,u,r);
         if (x<=k && u!=i)
         {
            u++;
            s++;
         }
         else
         {
            x=get(d,l,d,r);
            if (x>k)
            {
               s=inf;
               break;
            }
            d--;
            s++;
         }
         if (s+(r-l+1<?d-u+1)>=ans)
         {
            s=inf;
            break;
         }
      }
      if (s<ans)
         ans=s;
   }
}
int get(int x1,int y1,int x2,int y2)
{
   return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int b[2001][2001];
void change()
{
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         b[j][i]=a[i][j];
   for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
         a[i][j]=b[i][j];
   int t;
   t=n,n=m,m=t;
}
