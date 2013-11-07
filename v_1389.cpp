#include <cstdio>
#include <cstdlib>
int a[1001];
char *s[1001];
int main()
{
   void sort(int,int);
   int n,i;
   char ss[1001][260];
   char ch;
   i=0;
   while (1)
   {
      i++;  
      scanf("%d%c",&a[i],&ch);
      if (ch=='\n')
         break;
   }
   n=i;
   for (i=1;i<=n;i++)
   {
      scanf("%s",ss[i]);
      s[i]=ss[i];
   }
   sort(1,n);
   for (i=1;i<=n;i++)
      printf("%s\n",s[i]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   char *k;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         k=s[i],s[i]=s[j],s[j]=k;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
