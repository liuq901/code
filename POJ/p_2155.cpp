#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,c[1001][1001];
int main()
{
   void work();
   int i,t;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
      work();
      printf("\n");
   }
   system("pause");
   return(0);
}
void work()
{
   void insert(int,int);
   int find(int,int);
   int m,i,x1,y1,x2,y2;
   char ch;
   memset(c,0,sizeof(c));
   scanf("%d%d%*c",&n,&m);
   for (i=1;i<=m;i++)
   {
      scanf("%c",&ch);
      if (ch=='C')
      {
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         insert(x1,y1);
         insert(x1,y2+1);
         insert(x2+1,y1);
         insert(x2+1,y2+1);
      }
      else
      {
         scanf("%d%d",&x1,&y1);
         printf("%d\n",find(x1,y1));
      }
      scanf("%*c");
   }
}
void insert(int x,int y)
{
   int t;
   t=y;
   while (x<=n)
   {
      y=t;
      while (y<=n)
      {
         c[x][y]++;
         y+=y&-y;
      }
      x+=x&-x;
   }
}
int find(int x,int y)
{
   int ans,t;
   ans=0;
   t=y;
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
   return(ans%2);
}
