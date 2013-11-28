#include <cstdio>
#include <cstdlib>
int n,a[1100][1100];
int main()
{
   void insert(int,int,int);
   int count(int,int);
   scanf("%*d%d",&n);
   while (1)
   {
      int x;
      scanf("%d",&x);
      if (x==3)
         break;
      if (x==1)
      {
         int x,y,c;
         scanf("%d%d%d",&x,&y,&c);
         x++,y++;
         insert(x,y,c);
      }
      else
      {
         int x0,y0,x1,y1;
         scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
         x0++,y0++,x1++,y1++;
         printf("%d\n",count(x1,y1)-count(x0-1,y1)-count(x1,y0-1)+count(x0-1,y0-1));
      }
   }
   system("pause");
   return(0);
}
void insert(int x,int y,int v)
{
   for (int i=x;i<=n;i+=i&-i)
      for (int j=y;j<=n;j+=j&-j)
         a[i][j]+=v;
}
int count(int x,int y)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      for (int j=y;j;j-=j&-j)
         ans+=a[i][j];
   return(ans);
}
