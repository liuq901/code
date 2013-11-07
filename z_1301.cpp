#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[11][11],b[11][11],f[1025][11],q[10241][2],dep[1025][11];
int main()
{
   void print(int,int);
   int test_id=0;
   while (1)
   {
      int n,d,s;
      scanf("%d%d%d",&n,&d,&s);
      if (!n && !d && !s)
         break;
      memset(f,0,sizeof(f));
      memset(a,0,sizeof(a));
      memset(b,0,sizeof(b));
      for (int i=1;i<=d;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][++a[x][0]]=y;
         a[y][++a[y][0]]=x;
      }
      for (int i=1;i<=s;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         b[x][++b[x][0]]=y;
      }
      int l,r;
      l=r=1;
      f[1][1]=1;
      q[1][0]=1;
      q[1][1]=1;
      dep[1][1]=0;
      while (l<=r)
      {
         int k=q[l][0],x=q[l][1];
         for (int i=1;i<=a[x][0];i++)
         {
            int y=a[x][i];
            if (1<<y-1&k)
            {
               if (f[k][y])
                  continue;
               f[k][y]=l;
               dep[k][y]=dep[k][x]+1;
               q[++r][0]=k;
               q[r][1]=y;
            }
         }
         for (int i=1;i<=b[x][0];i++)
         {
            int y=b[x][i],p=1<<y-1^k;
            if (f[p][x] || y==x)
               continue;
            f[p][x]=l;
            dep[p][x]=dep[k][x]+1;
            q[++r][0]=p;
            q[r][1]=x;
         }
         l++;
      }
      printf("Villa #%d\n",++test_id);
      if (f[1<<n-1][n])
      {
         printf("The problem can be solved in %d steps:\n",dep[1<<n-1][n]);
         print(1<<n-1,n);
      }
      else
         printf("The problem cannot be solved.\n");
      printf("\n");
   }
   system("pause");
   return(0);
}
void print(int x,int y)
{
   if (x==1 && y==1)
      return;
   int p=f[x][y];
   print(q[p][0],q[p][1]);
   if (q[p][1]!=y)
      printf("- Move to room %d.\n",y);
   else if (x>q[p][0])
   {
      int t=x-q[p][0],s=0;
      while (t)
      {
         s++;
         t>>=1;
      }
      printf("- Switch on light in room %d.\n",s);
   }
   else
   {
      int t=q[p][0]-x,s=0;
      while (t)
      {
         s++;
         t>>=1;
      }
      printf("- Switch off light in room %d.\n",s);
   }
}
