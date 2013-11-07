#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[20],q[10010],d[10010];
bool f[10010];
int main()
{
   while (1)
   {
      int S,T,n;
      scanf("%d%d%d",&S,&T,&n);
      if (!S && !T && !n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      memset(f,0,sizeof(f));
      int l,r;
      d[S]=0;
      q[l=r=1]=S;
      while (l<=r)
      {
         int x=q[l++];
         for (int i=1;i<=n;i++)
         {
            int y=(x+a[i])%10000;
            if (!f[y])
            {
               f[y]=true;
               q[++r]=y;
               d[y]=d[x]+1;
            }
         }
      }
      static int id=0;
      printf("Case %d: ",++id);
      if (!f[T])
         printf("Permanently Locked\n");
      else
         printf("%d\n",d[T]);
   }
   system("pause");
   return(0);
}
