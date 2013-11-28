#include <cstdio>
#include <cstdlib>
int b[10001],link[10001],a[20001][2];
bool f[10001];
int main()
{
   void add(int,int,int);
   bool hungary(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      int p=i+x,q=i-x;
      if (p>n)
         p-=n;
      if (q<=0)
         q+=n;
      if (p<q)
      {
         int t;
         t=p,p=q,q=t;
      }
      add(i,i,p);
      add(i+n,i,q);
   }
   bool flag=true;
   for (int i=n;i>=1;i--)
      if (!hungary(i))
      {
         flag=false;
         break;
      }
   if (!flag)
      printf("No Answer\n");
   else
   {
      for (int i=1;i<=n;i++)
         b[link[i]]=i;
      for (int i=1;i<n;i++)
         printf("%d ",b[i]-1);
      printf("%d\n",b[n]-1);
   }
   system("pause");
   return(0);
}
void add(int id,int x,int y)
{
   a[id][0]=y,a[id][1]=b[x],b[x]=id;
}
bool hungary(int x)
{
   if (!x)
      return(true);
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (f[y])
         continue;
      f[y]=true;
      if (hungary(link[y]))
      {
         link[y]=x;
         f[y]=false;
         return(true);
      }
   }
   return(false);
}
