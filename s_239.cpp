#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,n,a[1001],f[1001];
int main()
{
   void search(int);
   int i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,0,sizeof(f));
   ans=0;
   search(2);
   f[1]=1;
   search(2);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int t)
{
   int check(int);
   if (t==n+1)
   {
      if (check(t))
         ans++;
      return;
   }
   if (check(t))
      search(t+1);
   f[t]=1;
   if (check(t))
      search(t+1);
   f[t]=0;
}
int check(int t)
{
   int s,i;
   s=0;
   for (i=t-2;i<=t;i++)
   {
      if (i<=0 || i>n)
         continue;
      s+=f[i];
   }
   if (s!=a[t-1])
      return(0);
   else
      return(1);
}
