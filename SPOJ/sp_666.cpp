#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[100100],g[100100],s[100100],t[100100],b[100100],a[200200][2];
int main()
{
   void floodfill(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      memset(b,0,sizeof(b));
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
      printf("%d %d\n",f[1],s[1]);
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   f[x]=0,g[x]=s[x]=t[x]=1;
   for (int i=b[x];i;i=a[i][1])
   {
      if (a[i][0]==father)
         continue;
      int y=a[i][0];
      floodfill(a[i][0],x);
      g[x]+=f[y],t[x]=t[x]*s[y]%10007;
      f[x]+=g[y],s[x]=s[x]*t[y]%10007;
   }
   if (g[x]<f[x])
   {
      f[x]=g[x];
      s[x]=t[x];
   }
   else if (g[x]==f[x])
      s[x]=(s[x]+t[x])%10007;
}
