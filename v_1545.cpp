#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
   int n,k,m,i,j,x,p,q;
   int a[30001];
   char s[220000],f[220000];
   scanf("%d%d",&k,&m);
   a[1]=1;
   p=1;
   q=1;
   for (i=2;i<=k;i++)
   {
      if (2*a[p]+1<4*a[q]+5)
      {
         a[i]=2*a[p]+1;
         p++;
         continue;
      }
      if (2*a[p]+1>4*a[q]+5)
      {
         a[i]=4*a[q]+5;
         q++;
         continue;
      }
      a[i]=2*a[p]+1;
      p++;
      q++;
   }
   n=0;
   for (i=1;i<=k;i++)
   {
      printf("%d",a[i]);
      x=(int)log10(a[i])+1;
      n+=x;
      for (j=n;j>=n-x+1;j--)
      {
         s[j]=a[i]%10+'0';
         a[i]/=10;
         f[j]=0;
      }
   }
   printf("\n");
   p=2;
   while (m!=0 && p<=n)
   {
      q=p-1;
      while (f[q] && q>0)
         q--;
      if (q!=0 && s[q]<s[p])
      {
         f[q]=1;
         m--;
      }
      else
         p++;
   }
   p=n+1;
   while (m!=0)
   {
      p--;
      if (f[p])
         continue;
      f[p]=1;
      m--;
   }
   for (i=1;i<=n;i++)
      if (!f[i])
         printf("%c",s[i]);
   printf("\n");
   system("pause");
   return(0);
}
