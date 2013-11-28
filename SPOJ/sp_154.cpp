#include <cstdio>
#include <cstdlib>
int main()
{
   int max(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      char st[210];
      int n;
      scanf("%d%s",&n,st);
      int f[201]={0},s[201]={0},t[201]={0};
      for (int i=1;i<=n;i++)
      {
         s[i]=s[i-1],t[i]=t[i-1];
         if (st[i-1]=='1')
            s[i]++;
         else
            t[i]++;
      }
      for (int i=1;i<=n;i++)
      {
         f[i]=f[i-1];
         for (int j=0;j<=i-1;j++)
         {
            int p=s[i]-s[j],q=t[i]-t[j];
            if (p>q)
               f[i]=max(f[i],f[j]+p+q);
         }
      }
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
