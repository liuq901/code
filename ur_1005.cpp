#include <cstdio>
#include <cstdlib>
int ans,n,a[21],f[21];
int main()
{
   void search(int);
   int i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   ans=20000000;
   search(1);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int t)
{
   int i,s1,s2;
   if (t==n+1)
   {
      s1=s2=0;
      for (i=1;i<=n;i++)
         if (f[i])
            s1+=a[i];
         else
            s2+=a[i];
      if (abs(s1-s2)<ans)
         ans=abs(s1-s2);
      return;
   }
   f[t]=0;
   search(t+1);
   f[t]=1;
   search(t+1);
}
