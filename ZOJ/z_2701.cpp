#include <cstdio>
#include <cstdlib>
int s,d[20001],f[20001];
int main()
{
   void insert(int,int,int);
   int calc(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int a[201][201];
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      s=n;
      insert(2,1,a[1][2]);
      f[1]=0;
      bool flag=true;
      for (int i=3;i<=n;i++)
      {
         int max=0,k;
         for (int j=2;j<i;j++)
         {
            int p1=a[1][i],p2=a[1][j],p3=a[i][j];
            if (p1+p2<=p3 || p1+p3<=p2 || p2+p3<=p1 || p1+p2-p3&1)
            {
               flag=false;
               break;
            }
            int x=p1+p2-p3>>1;
            if (x>max)
            {
               max=x;
               k=j;
            }
         }
         if (!flag)
            break;
         int t=a[1][k];
         while (t>max)
         {
            k=f[k];
            t--;
         }
         insert(i,k,a[1][i]-max);
      }
      if (!flag)
         f[1]=-1;
      for (int i=1;i<=n;i++)
         d[i]=a[1][i];
      for (int i=2;i<n;i++)
      {
         for (int j=i+1;j<=n;j++)
            if (calc(i,j)!=a[i][j])
            {
               f[1]=-1;
               break;
            }
         if (f[1]==-1)
            break;
      }
      if (f[1]==-1)
         printf("-1\n");
      else
      {
         printf("%d\n",s);
         for (int i=2;i<=s;i++)
            printf("%d %d\n",i,f[i]);
      }
   }
   system("pause");
   return(0);
}
void insert (int x,int y,int z)
{
   int i;
   if (z==1)
      f[x]=y;
   else
      f[x]=++s;
   for (int i=2;i<z;i++)
   {
      f[s]=s+1;
      s++;
   }
   if (z>1)
      f[s]=y;
}
int calc(int x,int y)
{
   int p=d[x],q=d[y],ans=0;
   while (x!=y)
   {
      ans++;
      if (p>q)
      {
         p--;
         x=f[x];
      }
      else
      {
         q--;
         y=f[y];
      }
   }
   return(ans);
}
