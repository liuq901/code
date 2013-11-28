#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,l,r,n,x,y;
   int a[201],f[201],q[201];
   scanf("%d%d%d",&n,&x,&y);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,0,sizeof(f));
   f[x]=1;
   l=r=1;
   q[1]=x;
   while (l<=r)
   {
      if (q[l]+a[q[l]]<=n && !f[q[l]+a[q[l]]])
      {
         r++;
         q[r]=q[l]+a[q[l]];
         f[q[r]]=f[q[l]]+1;
      }
      if (q[l]-a[q[l]]>0 && !f[q[l]-a[q[l]]])
      {
         r++;
         q[r]=q[l]-a[q[l]];
         f[q[r]]=f[q[l]]+1;
      }
      if (q[l]==y)
         break;
      l++;
   }
   printf("%d\n",f[y]-1);
   system("pause");
   return(0);
}
