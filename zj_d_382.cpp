#include <cstdio>
#include <cstdlib>
int a[10001][1001];
int main()
{
   void sort(int,int,int *);
   bool find(int,int *);
   int n,m;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][++a[x][0]]=y;
      }
      for (int i=1;i<=n;i++)
         sort(1,a[i][0],a[i]);
      int t;
      scanf("%d",&t);
      for (int i=1;i<=t;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%s\n",find(y,a[x])?"Yes":"No");
      }
   }
   system("pause");
   return(0);
}
void sort(int l,int r,int *a)
{
   int i,j,x;
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
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
int find(int x,int *a)
{
   int l=1,r=a[0];
   while (l<=r)
   {
      int mid=l+r>>1;
      if (a[mid]==x)
         return(true);
      if (a[mid]<x)
         l=mid+1;
      else
         r=mid-1;
   }
   return(false);
}
