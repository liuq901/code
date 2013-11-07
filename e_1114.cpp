#include <cstdio>
#include <cstdlib>
bool f[21],p[40];
int n,a[21];
int main()
{
   void search(int);
   p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=true;
   scanf("%d",&n);
   a[1]=1;
   f[1]=true;
   search(2);
   system("pause");
   return(0);
}
void search(int dep)
{
   if (dep==n+1)
   {
      if (p[a[n]+a[1]])
      {
         for (int i=1;i<n;i++)
            printf("%d ",a[i]);
         printf("%d\n",a[n]);
      }
      return;
   }
   for (int i=1;i<=n;i++)
   {
      if (f[i])
         continue;
      if (p[a[dep-1]+i])
      {
         a[dep]=i;
         f[i]=true;
         search(dep+1);
         f[i]=false;
      }
   }
}
