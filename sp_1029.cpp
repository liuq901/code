#include <cstdio>
#include <cstdlib>
int n,a[1100][1100],c[1100][1100];
int main()
{
   void insert(int,int,int);
   int get(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            a[i][j]=c[i][j]=0;
      while (1)
      {
         char s[10];
         scanf("%s",s);
         if (s[0]=='E')
            break;
         if (s[1]=='E')
         {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            insert(x+1,y+1,z-a[x+1][y+1]);
            a[x+1][y+1]=z;
         }
         else
         {
            int x0,y0,x1,y1;
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            printf("%d\n",get(x1+1,y1+1)-get(x0,y1+1)-get(x1+1,y0)+get(x0,y0));
         }
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
void insert(int x,int y,int v)
{
   for (int i=x;i<=n;i+=i&-i)
      for (int j=y;j<=n;j+=j&-j)
         c[i][j]+=v;
}
int get(int x,int y)
{
   int sum=0;
   for (int i=x;i;i-=i&-i)
      for (int j=y;j;j-=j&-j)
         sum+=c[i][j];
   return(sum);
}
