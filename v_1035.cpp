#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char name[11][15],p[11],*s[11];
   int i,j,n,x,y,k;
   int a[11];
   scanf("%d%*c",&n);
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      scanf("%s",name[i]);
      s[i]=name[i];
   }
   for (i=1;i<=n;i++)
   {
      scanf("%s",p);
      for (j=1;j<=n;j++)
         if (strcmp(s[j],p)==0)
         {
            k=j;
            break;
         }
      scanf("%d%d%*c",&x,&y);
      if (x!=0 && y!=0)
      {
         x/=y;
         a[k]-=x*y;
         for (j=1;j<=y;j++)
         {
            scanf("%s",p);
            for (k=1;k<=n;k++)
               if (strcmp(s[k],p)==0)
                  a[k]+=x;
         }
      }  
   }
   for (i=1;i<=n;i++)
      printf("%s %d\n",s[i],a[i]);
   system("pause");
   return(0);
}
