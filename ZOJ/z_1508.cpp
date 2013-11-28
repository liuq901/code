#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[50010],a[200000][3];
int main()
{
   void spfa(int,int);
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      int m=-1,q=100000000;
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         y++;
         a[i][0]=y;
         a[i][1]=z;
         a[i][2]=b[x];
         b[x]=i;
         if (y>m)
            m=y;
         if (x<q)
            q=x;
      }
      for (int i=q+1;i<=m;i++)
      {
         a[i+n][0]=i-1;
         a[i+n][1]=-1;
         a[i+n][2]=b[i];
         b[i]=i+n;
         a[i+n+m][0]=i;
         a[i+n+m][1]=0;
         a[i+n+m][2]=b[i-1];
         b[i-1]=i+n+m;
      }
      spfa(m,q);
   }
   system("pause");
   return(0);
}
int q[50010],d[50010];
bool f[50010];
void spfa(int n,int s)
{
   memset(d,-26,sizeof(d));
   memset(f,0,sizeof(f));
   int l=0,r=1;
   q[1]=s;
   d[s]=0;
   f[s]=true;
   while (l!=r)
   {
      l++;
      if (l>50000)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]>d[y])
         {
            d[y]=d[x]+a[i][1];
            if (!f[y])
            {
               f[y]=true;
               r++;
               if (r>50000)
                  r=1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
   printf("%d\n",d[n]-d[s]);
}
