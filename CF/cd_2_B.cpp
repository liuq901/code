#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010][1010],b[1010][1010],v[1010][1010];
int main()
{
   int calc(int,int),get(int,int,int [][1010],int);
   void print(int,int,int [][1010],int);
   int n,x0,y0;
   scanf("%d",&n);
   memset(a,63,sizeof(a));
   memset(b,63,sizeof(b));
   a[1][0]=b[1][0]=0;
   x0=y0=-1;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         int x;
         scanf("%d",&x);
         v[i][j]=x;
         if (!x)
         {
            a[i][j]=b[i][j]=1<<20;
            x0=i,y0=j;
            continue;
         }
         a[i][j]=min(a[i-1][j],a[i][j-1])+calc(x,2);
         b[i][j]=min(b[i-1][j],b[i][j-1])+calc(x,5);
      }
   int p=min(get(n,n,a,5),a[n][n]),q=min(get(n,n,b,2),b[n][n]);
   if (x0!=-1 && min(p,q)>=1)
   {
      printf("1\n");
      for (int i=1;i<x0;i++)
         printf("D");
      for (int i=1;i<y0;i++)
         printf("R");
      for (int i=x0+1;i<=n;i++)
         printf("D");
      for (int i=y0+1;i<=n;i++)
         printf("R");
      printf("\n");
   }
   else if (p<q)
   {
      printf("%d\n",p);
      print(n,n,a,2);
      printf("\n");
   }
   else
   {
      printf("%d\n",q);
      print(n,n,b,5);
      printf("\n");
   }
   system("pause");
   return(0);
}
int get(int x,int y,int a[][1010],int value)
{
   int calc(int,int);
   int p=calc(v[x][y],value);
   if (!v[x][y])
      p=1;
   if (x==1 && y==1)
      return(p);
   else if (a[x][y-1]+calc(v[x][y],10/value)==a[x][y])
      return(p+get(x,y-1,a,value));
   else
      return(p+get(x-1,y,a,value));
}
void print(int x,int y,int a[][1010],int value)
{
   int calc(int,int);
   if (x==1 && y==1)
      return;
   if (a[x][y]==a[x-1][y]+calc(v[x][y],value))
   {
      print(x-1,y,a,value);
      printf("D");
   }
   else
   {
      print(x,y-1,a,value);
      printf("R");
   }
}
int calc(int x,int value)
{
   int ans=0;
   while (x && !(x%value))
   {
      ans++;
      x/=value;
   }
   return(ans);
}
