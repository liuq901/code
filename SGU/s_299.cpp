#include <cstdio>
#include <cstdlib>
#include <cstring>
char *a[1001],s[1001][510];
int main()
{
   void sort(int,int);
   int check(int);
   int n,i,flag;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",s[i]);
      a[i]=s[i];
   }
   sort(1,n);
   flag=0;
   for (i=1;i<=n-2;i++)
      if (check(i))
      {
         flag=1;
         printf("%s %s %s\n",a[i],a[i+1],a[i+2]);
         break;
      }
   if (!flag)
      printf("0 0 0\n");
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int compare(char *,char *);
   int i,j;
   char *x,*t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (compare(a[i],x)<0)
         i++;
      while (compare(a[j],x)>0)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int compare(char *a,char *b)
{
   int l1,l2;
   l1=strlen(a);
   l2=strlen(b);
   if (l1<l2)
      return(-1);
   if (l1>l2)
      return(1);
   return(strcmp(a,b));
}
int check(int t)
{
   int x,i;
   int b[510],c[510],d[510];
   memset(b,0,sizeof(b));
   memset(c,0,sizeof(c));
   b[0]=strlen(a[t]);
   for (i=1;i<=b[0];i++)
      b[i]=a[t][b[0]-i]-'0';
   c[0]=strlen(a[t+1]);
   for (i=1;i<=c[0];i++)
      c[i]=a[t+1][c[0]-i]-'0';
   d[0]=strlen(a[t+2]);
   for (i=1;i<=d[0];i++)
      d[i]=a[t+2][d[0]-i]-'0';
   x=0;
   if (b[0]<c[0])
      b[0]=c[0];
   for (i=1;i<=b[0];i++)
   {
      b[i]+=c[i]+x;
      x=b[i]/10;
      b[i]%=10;
   }
   while (x!=0)
   {
      b[0]++;
      b[b[0]]=x%10;
      x/=10;
   }
   if (b[0]>d[0])
      return(1);
   if (b[0]<d[0])
      return(0);
   for (i=b[0];i>=1;i--)
   {
      if (b[i]>d[i])
         return(1);
      if (b[i]<d[i])
         return(0);
   }
   return(0);
}
