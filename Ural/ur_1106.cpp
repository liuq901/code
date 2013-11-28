#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int s,n,x,i,j,flag;
   int f[101],a[101][101];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      a[i][0]=0;
      while (1)
      {
         scanf("%d",&x);
         if (x==0)
            break;
         a[i][0]++;
         a[i][a[i][0]]=x;
      }
   }
   memset(f,-1,sizeof(f));
   s=0;
   for (i=1;i<=n;i++)
   {
      if (f[i]!=-1)
         continue;
      f[i]=0;
      s++;
      flag=0;
      for (j=1;j<=a[i][0];j++)
      {
         if (f[a[i][j]]==0)
            continue;
         flag=1;
         f[a[i][j]]=1;
      }
      if (!flag)
         break;
   }
   if (!flag)
      printf("0\n");
   else
   {
      printf("%d\n",s);
      j=0;
      for (i=1;i<=n;i++)
         if (f[i]==0)
         {
            j++;
            printf("%d",i);
            if (j==s)
            {
               printf("\n");
               break;
            }
            printf(" ");
         }
   }
   system("pause");
   return(0);
}
