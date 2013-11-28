#include <cstdio>
#include <cstdlib>
int a[10010],b[10010];
bool f[5010],g[10010];
int main()
{
   void sort(int,int);
   int n;
   scanf("%d",&n);
   n++;
   a[2]=1000000000;
   b[1]=b[2]=1;
   f[1]=true;
   for (int i=2;i<=n;i++)
   {
      int x,y;
      char ch;
      scanf("%d%d%*c%c",&x,&y,&ch);
      a[2*i-1]=x;
      a[2*i]=y;
      b[2*i-1]=i;
      b[2*i]=i;
      f[i]=ch=='w' || x==y;
   }
   sort(1,2*n);
   for (int i=1;i<=n;i++)
   {
      int l=-1,r;
      for (int j=1;j<=2*n;j++)
      {
         if (b[j]!=i)
            continue;
         if (l==-1)
            l=j;
         else
         {
            r=j;
            break;
         }
      }
      while (a[l]==a[l+1])
         l++;
      while (a[r]==a[r+1])
         r++;
      for (int j=l+1;j<=r;j++)
         g[j]=!f[i];
   }
   int t=0,ans=0,x,y;
   a[2*n+1]=-1;
   for (int i=1;i<=2*n;i++)
   {
      if (a[i]==a[i+1])
         continue;
      if (g[i])
      {
         t=a[i];
         continue;
      }
      if (a[i]-t>ans)
      {
         ans=a[i]-t;
         x=t;
         y=a[i];
      }
   }
   printf("%d %d\n",x,y);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   y=b[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x || a[i]==x && b[i]<y)
         i++;
      while (a[j]>x || a[j]==x && b[j]>y)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
