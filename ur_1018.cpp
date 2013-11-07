#include <cstdio>
#include <cstdlib>
#include <cstring>
int l[101],r[101],b[101],v[101],f[101][101],a[201][3];
int main()
{
   void floodfill(int,int);
   int count(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<n;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
      a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
   }
   floodfill(1,0);
   v[1]=0;
   memset(f,-1,sizeof(f));
   printf("%d\n",count(1,m+1));
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   for (int i=b[x];i;i=a[i][2])
   {
      if (a[i][0]==father)
         continue;
      v[a[i][0]]=a[i][1];
      if (!l[x])
         l[x]=a[i][0];
      else
         r[x]=a[i][0];
      floodfill(a[i][0],x);
   }
}
int count(int x,int k)
{
   int max(int,int);
   if (f[x][k]!=-1)
      return(f[x][k]);
   if (!k)
      f[x][k]=0;
   else if (!l[x])
      f[x][k]=k==1?v[x]:-1<<30;
   else if (!r[x])
      f[x][k]=count(l[x],k-1)+v[x];
   else
   {
      f[x][k]=-1<<30;
      for (int i=0;i<k;i++)
         f[x][k]=max(f[x][k],count(l[x],i)+count(r[x],k-i-1));
      f[x][k]+=v[x];
   }
   return(f[x][k]);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
