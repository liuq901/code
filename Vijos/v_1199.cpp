#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,k,l,m,n,s,ans;
   int a[260][260];
   char ch;
   scanf("%d",&m);
   scanf("%d%*c",&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=m;i++)
      for (j=1;j<=m+1;j++)
      {
         scanf("%c",&ch);
         if (ch=='#')
            a[i][j]=1;
      }
   ans=0;
   for (i=1;i<=m;i++)
      for (j=1;j<=m;j++)
      {
         s=0;
         for (k=i;k<=i+n-1;k++)
            for (l=j;l<=j+n-1;l++)
               s+=a[k][l];
         if (s>ans)
            ans=s;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
