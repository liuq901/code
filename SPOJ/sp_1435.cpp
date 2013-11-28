#include <cstdio>
#include <cstdlib>
int b[100001],f[100001],g[100001],a[200001][2];
int main()
{
   void floodfill(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i][0]=y;
      a[i][1]=b[x];
      b[x]=i;
      a[i+n][0]=x;
      a[i+n][1]=b[y];
      b[y]=i+n;
   }
   floodfill(1,0);
   printf("%d\n",f[1]);
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   int s1=0,s2=0;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      floodfill(a[i][0],x);
      s1+=f[a[i][0]];
      s2+=g[a[i][0]];
   }
   g[x]=s1+1;
   f[x]=g[x]<s2?g[x]:s2;
}
