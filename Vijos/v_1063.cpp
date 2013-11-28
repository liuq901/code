#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int min(int,int,int);
   int a[526][526];
   int i,j,k,n,ans,max;
   char ch;
   scanf("%d%*c",&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=i-1;j++)
         scanf("%*c");
      for (j=1;j<=2*(n-i+1)-1;j++)
      {
         scanf("%c",&ch);
         if (ch=='#')
            a[i][j]=0;
         if (ch=='-')
            a[i][j]=1;
      }
      scanf("%*c");
   }
   for (i=2;i<=n;i++)
      for (j=1;j<=2*(n-i+1)-1;j++)
         if (a[i][j]==1)
         {
            a[i][j]=3*min(a[i-1][j],a[i-1][j+1],a[i-1][j+2]);
            if (a[i][j]<1)
               a[i][j]=1;
         }
   max=0;
   for (i=1;i<=n;i++)
      for (j=1;j<=2*(n-i+1)-1;j++)
         if (a[i][j]>max && j%2==1)
            max=a[i][j];
   ans=0;
   i=1;
   while (1)
   {
      if (max==0)
      {
         ans=0;
         break;
      }
      if (max==1)
      {
         ans++;
         break;
      }
      max/=3;
      i+=2;
      ans+=i;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int min(int a,int b,int c)
{
   int ans;
   if (a<b)
      ans=a;
   else
      ans=b;
   if (c<ans)
      ans=c;
   return(ans);
}
