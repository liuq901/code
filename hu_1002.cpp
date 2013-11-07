#include <cstdio>
#include <cstdlib>
#include <cstring>
const int n=1001;
struct data
{
   int c[n+1][n+1];
   void insert(int x,int y,int k)
   {
      int t=y;
      while (x<=n)
      {
         y=t;
         while (y<=n)
         {
            c[x][y]+=k;
            y+=y&-y;
         }
         x+=x&-x;
      }
   }
   void init()
   {
      memset(c,0,sizeof(c));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            insert(i,j,1);
   }
   void del(int x,int y,int n)
   {
      insert(x,y,-n);
   }
   int find(int x,int y)
   {
      int ans=0,t=y;
      while (x>0)
      {
         y=t;
         while (y>0)
         {
            ans+=c[x][y];
            y-=y&-y;
         }
         x-=x&-x;
      }
      return(ans);
   }
};
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   for (int i=1;i<=t;i++)
   {
      printf("Case %d:\n",i);
      work();
   }
   system("pause");
   return(0);
}
data a;
int f[1010][1010];
void work()
{
   int q;
   scanf("%d%*c",&q);
   a.init();
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         f[i][j]=1;
   for (int i=1;i<=q;i++)
   {
      char ch;
      int x1,x2,y1,y2,n;
      scanf("%c",&ch);
      if (ch=='S')
      {
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         if (x1>x2)
         {
            int t;
            t=x1,x1=x2,x2=t;
         }
         if (y1>y2)
         {
            int t;
            t=y1,y1=y2,y2=t;
         }
         x1++,y1++,x2++,y2++;
         printf("%d\n",a.find(x2,y2)+a.find(x1-1,y1-1)-a.find(x1-1,y2)-a.find(x2,y1-1));
      }
      else if (ch=='A')
      {
         scanf("%d%d%d",&x1,&y1,&n);
         x1++,y1++;
         f[x1][y1]+=n;
         a.insert(x1,y1,n);
      }
      else if (ch=='D')
      {
         scanf("%d%d%d",&x1,&y1,&n);
         x1++,y1++;
         if (n>f[x1][y1])
            n=f[x1][y1];
         f[x1][y1]-=n;
         a.del(x1,y1,n);
      }
      else
      {
         scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
         x1++,y1++,x2++,y2++;
         if (n>f[x1][y1])
            n=f[x1][y1];
         f[x1][y1]-=n;
         f[x2][y2]+=n;
         a.del(x1,y1,n);
         a.insert(x2,y2,n);
      }
      scanf("%*c");
   }
}
