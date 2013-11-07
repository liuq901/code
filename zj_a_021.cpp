#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[510];
int a[510],b[510];
int main()
{
   void plus(),minus(),multi(),divide();
   char ch;
   int i,l;
   while (scanf("%s",s)!=EOF)
   {
      scanf("%*c%c%*c",&ch);
      memset(a,0,sizeof(a));
      l=strlen(s);
      for (i=0;i<l;i++)
         a[l-i]=s[i]-'0';
      a[0]=l;
      scanf("%s",s);
      memset(b,0,sizeof(b));
      l=strlen(s);
      for (i=0;i<l;i++)
         b[l-i]=s[i]-'0';
      b[0]=l;
      if (ch=='+')
         plus();
      if (ch=='-')
         minus();
      if (ch=='*')
         multi();
      if (ch=='/')
         divide();
   }
   system("pause");
   return(0);
}
void plus()
{
   int i,x,t;
   if (a[0]>b[0])
      t=a[0];
   else
      t=b[0];
   x=0;
   for (i=1;i<=t;i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
}
void minus()
{
   int i,t,flag;
   int c[510];
   flag=1;
   if (a[0]==b[0])
      for (i=a[0];i>=1;i--)
         if (a[i]<b[i])
         {
            flag=0;
            break;
         }
   if (a[0]<b[0] || !flag)
   {
      printf("-");
      memcpy(c,a,sizeof(a));
      memcpy(a,b,sizeof(b));
      memcpy(b,c,sizeof(c));
   }
   memset(c,0,sizeof(c));
   for (i=1;i<=a[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
      {
         c[i+1]--;
         c[i]+=10;
      }
   }
   c[0]=a[0];
   while (c[c[0]]==0 && c[0]>1)
      c[0]--;
   for (i=c[0];i>=1;i--)
      printf("%d",c[i]);
   printf("\n");
}
void multi()
{
   int i,j;
   int c[1010];
   memset(c,0,sizeof(c));
   for (i=1;i<=a[0];i++)
      for (j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   c[0]=a[0]+b[0];
   if (c[c[0]]==0)
      c[0]--;
   for (i=c[0];i>=1;i--)
      printf("%d",c[i]);
   printf("\n");
}
void divide()
{
   int compare(int,int *,int *);
   int i,k,t,sum,flag;
   int c[510];
   for (i=1;i<=a[0]/2;i++)
      t=a[i],a[i]=a[a[0]-i+1],a[a[0]-i+1]=t;
   for (i=1;i<=b[0]/2;i++)
      t=b[i],b[i]=b[b[0]-i+1],b[b[0]-i+1]=t;
   flag=1;
   if (a[0]<b[0])
      flag=0;
   else if (a[0]==b[0])
      for (i=1;i<=a[0];i++)
         if (a[i]>b[i])
            break;
         else if (a[i]<b[i])
         {
            flag=0;
            break;
         }
   if (!flag)
   {
      printf("0\n");
      return;
   }
   t=0;
   memset(c,0,sizeof(c));
   while (1)
   {
      t++;
      if (t>a[0])
         break;
      while (compare(t,a,b))
      {
         c[t]++;
         sum=t;
         for (i=a[0];i>=t;i--)
         {
            a[i]-=b[i-t+1];
            if (a[i]<0)
            {
               a[i]+=10;
               a[i-1]--;
            }
         }
      }
   }
   t=1;
   while (c[t]==0)
      t++;
   for (i=t;i<=sum;i++)
      printf("%d",c[i]);
   printf("\n");
}
int compare(int x,int *a,int *b)
{
   int i;
   if (a[0]-x+1<b[0])
      return(0);
   if (x!=1 && a[x-1]!=0)
      return(1);
   for (i=x;i<=a[0];i++)
      if (a[i]>b[i-x+1])
         return(1);
      else if (a[i]<b[i-x+1])
         return(0);
   return(1);
}
