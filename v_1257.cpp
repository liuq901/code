#include <cstdio>
#include <cstdlib>
#include <cstring>
int n;
char p[1001][1000],q[1001][100],*a[1001],*s[1001];
int main()
{
   void sort1(int,int),sort2(int,int),sort3(int,int);
   int i,j,k;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",p[i]);
      scanf("%s",q[i]);
      a[i]=p[i];
      s[i]=q[i];
   }
   sort1(1,n);
   i=1;
   j=2;
   while (i<=n)
      if (j<=n && strlen(s[i])==strlen(s[j]))
         j++;
      else
      {
         if (i!=j-1)
            sort2(i,j-1);
         i=j;
         j++;
      }
   i=1;
   j=2;
   while (i<=n)
   {
      if (j<=n && strcmp(s[i],s[j])==0)
         j++;
      else
      {
         if (i!=j-1)
            sort3(i,j-1);
         i=j;
         j++;
      }
   }
   for (i=n;i>=1;i--)
      printf("%s\n",a[i]);
   system("pause");
   return(0);
}
void sort1(int l,int r)
{
   int i,j,x;
   char *t;
   i=l;
   j=r;
   x=(l+r)/2;
   while (i<=j)
   {
      while (strlen(s[i])<strlen(s[x]))
         i++;
      while (strlen(s[j])>strlen(s[x]))
         j--;
      if (i<=j)
      {
         t=s[i],s[i]=s[j],s[j]=t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort1(i,r);
   if (l<j)
      sort1(l,j);
}
void sort2(int l,int r)
{
   int i,j,x;
   char *t;
   i=l;
   j=r;
   x=(l+r)/2;
   while (i<=j)
   {
      while (strcmp(s[i],s[x])<0)
         i++;
      while (strcmp(s[j],s[x])>0)
         j--;
      if (i<=j)
      {
         t=s[i],s[i]=s[j],s[j]=t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort2(i,r);
   if (l<j)
      sort2(l,j);
}
void sort3(int l,int r)
{
   int i,j,x;
   char *t;
   i=l;
   j=r;
   x=(l+r)/2;
   while (i<=j)
   {
      while (strcmp(a[i],a[x])>0)
         i++;
      while (strcmp(a[j],a[x])<0)
         j--;
      if (i<=j)
      {
         t=s[i],s[i]=s[j],s[j]=t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort3(i,r);
   if (l<j)
      sort3(l,j);
}
