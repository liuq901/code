#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int m,n,i,j,k,l;
   int a[10];
   char st[260];
   scanf("%d%d",&m,&n);
   memset(a,0,sizeof(a));
   for (i=m;i<=n;i++)
   {
      itoa(i,st,10);
      l=strlen(st);
      for (j=0;j<l;j++)
      {
         k=st[j]-'0';
         a[k]++;
      }
   }
   for (i=0;i<=8;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[9]);
   system("pause");
   return(0);
}
