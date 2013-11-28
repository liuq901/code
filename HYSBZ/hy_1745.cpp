#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[102],s[10001],a[10001][101],b[10001][101];
int main()
{
   void sort(int,int,int *,int *);
   int m,n,c;
   scanf("%d%d%d",&m,&n,&c);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[x][++s[x]]=y;
      b[x][s[x]]=z;
   }
   int ans=0;
   f[f[0]=1]=10000000;
   for (int i=1;i<=n;i++)
   {
      sort(1,s[i],a[i],b[i]);
      int j=1;
      while (j<=f[0] && f[j]==i)
         j++;
      ans+=j-1;
      int g[102],k=1;
      g[0]=0;
      while (g[0]<=c && k<=s[i])
      {
         if (f[j]<a[i][k])
         {
            g[++g[0]]=f[j];
            j++;
            continue;
         }
         for (int p=1;p<=b[i][k];p++)
         {
            if (a[i][k]<i)
               break;
            g[++g[0]]=a[i][k];
            if (g[0]>c)
               break;
         }
         k++;
      }
      while (g[0]<=c && j<f[0])
         g[++g[0]]=f[j++];
      if (g[0]<=c)
         g[0]++;
      g[g[0]]=10000000;
      memcpy(f,g,sizeof(g));
   }
   f[f[0]=1]=0;
   for (int i=n;i>=1;i--)
   {
      int j=1;
      while (j<=f[0] && f[j]==i)
         j++;
      ans+=j-1;
      int g[102],k=s[i];
      g[0]=0;
      while (g[0]<=c && k)
      {
         if (f[j]>a[i][k])
         {
            g[++g[0]]=f[j];
            j++;
            continue;
         }
         for (int p=1;p<=b[i][k];p++)
         {
            if (a[i][k]>i)
               break;
            g[++g[0]]=a[i][k];
            if (g[0]>c)
               break;
         }
         k--;
      }
      while (g[0]<=c && j<f[0])
         g[++g[0]]=f[j++];
      if (g[0]<=c)
         g[0]++;
      g[g[0]]=0;
      memcpy(f,g,sizeof(g));
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r,int *a,int *b)
{
   int i,j,x,t;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b);
   if (l<j)
      sort(l,j,a,b);
}
