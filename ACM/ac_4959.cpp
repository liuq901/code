#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,q[2100000],pre[2100000],f[2100000],a[30][30];
short now[2100000];
int main()
{
   int calc(int,int);
   void print(int);
   while (1)
   {
      int m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         x++,y++;
         a[x][++a[x][0]]=y;
         a[y][++a[y][0]]=x;
      }
      memset(f,-1,sizeof(f));
      f[(1<<n)-1]=0;
      int l,r;
      l=r=1,q[1]=(1<<n)-1;
      while (l<=r)
      {
         int x=q[l++];
         for (int i=1;i<=n;i++)
         {
            int p=calc(x,i);
            if (f[p]==-1)
            {
               f[p]=f[x]+1;
               q[++r]=p;
               pre[p]=x;
               now[p]=i-1;
            }
         }
      }
      if (f[0]==-1)
         printf("Impossible\n");
      else
      {
         printf("%d:",f[0]);
         print(0);
         printf("\n");
      }
   }
   system("pause");
   return(0);
}
bool b[30],c[30];
int calc(int state,int shoot)
{
   for (int i=1;i<=n;i++)
   {
      b[i]=state&1;
      state>>=1;
   }
   b[shoot]=false;
   memset(c,0,sizeof(c));
   for (int i=1;i<=n;i++)
   {
      if (!b[i])
         continue;
      for (int j=1;j<=a[i][0];j++)
      {
         int x=a[i][j];
         c[x]=true;
      }
   }
   int p=0;
   for (int i=n;i;i--)
      p=p<<1|c[i];
   return(p);
}
void print(int x)
{
   if (x+1==1<<n)
      return;
   print(pre[x]);
   printf(" %d",now[x]);
}
