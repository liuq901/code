#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int s,t,w,i,j,k;
   char ch,llast[260],st[260],aa[6][260],ar[27];
   char *a[6],*last=llast;
   scanf("%d%d%d%*c",&s,&t,&w);
   for (i=0;i<=6;i++)
      a[i]=aa[i];
   scanf("%s",a[0]);
   for (i=s;i<=t;i++)
      ar[i]=i+'a'-1;
   for (i=1;i<=w;i++)
      last[i-1]=t-i+'a';
   last[w]='\0';
   i=0;
   while (i!=5 && strcmp(a[i],last)!=0)
   {
      i++;
      a[i]=a[i-1];
      j=w;
      k=t;
      while (j!=1)
         if (a[i-1][j-1]<ar[k])
         {
            a[i][j-1]=a[i-1][j-1]+1;
            while (j<w)
            {
               j++;
               a[i][j-1]=a[i][j-2]+1;
            }
            break;
         }
         else
         {
            j--;
            k--;
         }
      printf("%s\n",a[i]);
   }
   system("pause");
   return(0);
}
