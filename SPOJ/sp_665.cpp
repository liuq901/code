#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char a[600000],b[600000],c[600000];
int main()
{
   bool check();
   int t;
   scanf("%d\n",&t);
   while (t--)
   {
      gets(a);
      gets(b);
      int n,m,l,r,ans;
      n=strlen(a),m=strlen(b);
      while (!isalpha(a[n-1]))
         n--;
      while (!isalpha(b[m-1]))
         m--;
      a[n]=b[m]='\0';
      ans=0,l=1,r=m/n;
      while (l<=r)
      {
         int mid=l+r>>1,p=0;
         for (int i=0;i<n;i++)
            for (int j=1;j<=mid;j++)
               c[p++]=a[i];
         c[p]='\0';
         if (check())
         {
            ans=mid;
            l=mid+1;
         }
         else
            r=mid-1;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
bool check()
{
   int n=strlen(c),m=strlen(b);
   int p=0;
   for (int i=0;i<m;i++)
      if (b[i]==c[p])
         p++;
   return(p==n);
}
