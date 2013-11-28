#include <cstdio>
#include <cstdlib>
#include <cstring>
int s[10][10];
int main()
{
   int check();
   int a[26];
   int i,j,k,n;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=9;j++)
         for (k=1;k<=9;k++)
            scanf("%d%*c",&s[j][k]);
      if (i!=n)
         scanf("%*c");
      a[i]=check();
   }
   for (i=1;i<=n;i++)
      if (a[i])
         printf("Right\n");
      else
         printf("Wrong\n");
   system("pause");
   return(0);
}
int check()
{
   int i,j,k,l,ans,flag;
   int a[10];
   flag=1;
   for (i=1;i<=9;i++)
   {
      ans=0;
      memset(a,0,sizeof(a));
      for (j=1;j<=9;j++)
         a[s[i][j]]=1;
      for (j=1;j<=9;j++)
         if (a[j])
            ans+=j;
      if (ans!=45)
      {
         flag=0;
         break;
      }
   }
   for (i=1;i<=9;i++)
   {
      ans=0;
      memset(a,0,sizeof(a));
      for (j=1;j<=9;j++)
         a[s[j][i]]=1;
      for (j=1;j<=9;j++)
         if (a[j])
            ans+=j;
      if (ans!=45)
      {
         flag=0;
         break;
      }
   }
   for (i=0;i<=2;i++)
      for (j=0;j<=2;j++)
      {
         ans=0;
         memset(a,0,sizeof(a));
         for (k=i*3+1;k<=i*3+3;k++)
            for (l=j*3+1;l<=j*3+3;l++)
               a[s[k][l]]=1;
         for (k=1;k<=9;k++)
            if (a[k])
               ans+=k;
         if (ans!=45)
         {
            flag=0;
            break;
         }
      }
   return(flag);
}
