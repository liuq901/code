#include <cstdio>
#include <cstdlib>
#include <cstring>
int father[400001],c[400001],ans[400001],b[400001],f[400001],a[400001][2];
int main()
{
   void floodfill(int);
   int work(int);
   int n,m,i,x,y,k;
   scanf("%d%d",&n,&m);
   memset(b,0,sizeof(b));
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      x++;
      y++;
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
   }
   memset(f,0,sizeof(f));
   scanf("%d",&k);
   for (i=1;i<=k;i++)
   {
      scanf("%d",&x);
      x++;
      c[i]=x;
      f[x]=1;
   }
   memset(father,0,sizeof(father));
   ans[k]=0;
   for (i=1;i<=n;i++)
   {
      if (f[i])
         continue;
      f[i]=1;
      father[i]=i;
      ans[k]++;
      floodfill(i);
   }
   for (i=k;i>=1;i--)
      ans[i-1]=ans[i]-work(c[i]);
   for (i=0;i<=k;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
void floodfill(int x)
{
   int i;
   i=b[x];
   while (i!=0)
   {
      if (!f[a[i][0]])
      {
         f[a[i][0]]=1;
         father[a[i][0]]=father[x];
         floodfill(a[i][0]);
      }
      i=a[i][1];
   }
}
int work(int x)
{
   int get(int);
   int i,ans;
   i=b[x];
   ans=-1;
   father[x]=x;
   while (i!=0)
   {
      if (father[a[i][0]] && get(a[i][0])!=get(x))
      {
         ans++;
         father[father[a[i][0]]]=father[x];
      }
      i=a[i][1];
   }
   return(ans);
}
int get(int x)
{
   int t;
   if (father[x]==x)
      return(x);
   t=get(father[x]);
   father[x]=t;
   return(t);
}
