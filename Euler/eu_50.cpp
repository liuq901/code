#include <cstdio>
#include <cstdlib>
typedef long long ll;
const int n=1000000;
int a[1000010];
bool f[1000010];
ll s[1000010];
int main()
{
   void init();
   init();
   for (int i=1;i<=a[0];i++)
      s[i]=s[i-1]+a[i];
   int ans=0,k;
   for (int i=1;i<=a[0];i++)
      for (int j=i;j<=a[0];j++)
      {
         ll now=s[j]-s[i-1];
         if (now<=n && !f[now] && j-i+1>ans)
         {
            ans=j-i+1;
            k=now;
         }
      }
   printf("%d\n",k);
   system("pause");
   return(0);
}
void init()
{
   f[1]=true;
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i])
         a[++a[0]]=i;
}
