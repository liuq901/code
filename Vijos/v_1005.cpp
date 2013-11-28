#include <cstdio>
#include <cstdlib>
#include <cstring>
int len,c,lq;
int t[2001],best[2002],a[2002],b[2002];
int main()
{
   void init(),program();
   init();
   program();
   system("pause");
   return(0);
}
void init()
{
   char st[200];
   int i;
   gets(st);
   len=strlen(st);
   for (i=0;i<len;i++)
      t[i+1]=st[i]-'0';
}
void program()
{
   void print();
   void dec1(int[]);
   int match(int);
   int can(int);
   int bigger(int[],int[]);
   int i,j,l,tem,flag;
   flag=1;
   for (i=1;i<=len;i++)
      if (t[i]!=0)
      {
         flag=0;
         break;
      }
   if (flag)
   {
      best[0]=len+1;
      best[best[0]]=c=1;
      print();
   }
   for (i=1;i<=len;i++)
      best[i]=t[len-i+1];
   best[0]=len;
   if (t[1]==0)
   {
      best[0]++;
      best[best[0]]=1;
   }
   for (i=len-len/2-1;i>=0;i--)
   {
      flag=1;
      for (j=1;j<=i;j++)
         if (t[j]!=t[len-i+j])
         {
            flag=0;
            break;
         }
      if (flag)
      {
         a[0]=len-i;
         tem=0;
         for (j=1;j<=a[0];j++)
            a[j]=t[a[0]-j+1];
         for (j=1;j<=a[0]-i;j++)
         {
            if (a[a[0]]!=0 && (i==0 || a[1]!=9 || t[i+1]!=9))
               if (bigger(best,a))
               {
                  for (lq=0;lq<=2002;lq++)
                     best[lq]=a[lq];
                  c=tem;
               }
            a[a[0]+1]=a[1];
            for (l=1;l<=a[0];l++)
               a[l]=a[l+1];
            a[a[0]+1]=0;
            tem++;
         }
      }
   }
   for (l=1;l<=best[0];l++)
   {
      for (i=l;i>=1;i--)
         if (i<len && t[i+1]!=0)
         {
            memset(b,0,sizeof(b));
            b[0]=l;
            for (j=l;j>=1;j--)
            {
               if (i+l-j+1>len)
                  break;
               b[j]=t[i+l-j+1];
            }
            if (b[0]==1 && b[1]==1)
               continue;
            for (lq=0;lq<=2002;lq++)
               a[lq]=b[lq]; 
            dec1(a);
            if (match(i) && can(i+l))
            {
               if (bigger(best,a))
               {
                  c=a[0]-i;
                  for (lq=0;lq<=2002;lq++)
                     best[lq]=a[lq];
               }
            }
         }
   }
   print();
}
void print()
{
   void dec1(int[]);
   void mul(int[]);
   void minus(int[],int[]);
   void inc1(int[]);
   void printnum(int[]);
   int i;
   int tem[2002];
   dec1(best);
   i=best[0]-1;
   mul(best);
   memset(tem,0,sizeof(tem));
   while (tem[0]<i)
   {
      tem[0]++;
      tem[tem[0]]=9;
      minus(best,tem);
   }
   inc1(best);
   for (i=1;i<=c;i++)
      inc1(best);
   printnum(best);
   system("pause");
   exit(0);
}
void dec1(int a[])
{
   int i;
   i=1;
   while (a[i]==0)
   {
      a[i]=9;
      i++;
   }
   a[i]--;
   if (a[0]>1 && a[a[0]]==0 )
      a[0]--;
}
int match(int i)
{
   int j;
   if (a[0]<i)
   {
      if (t[1]!=8)
         return(0);
      for (j=1;j<=a[0];j++)
         if (t[i-j+1]!=a[j])
            return(0); 
      return(1);
   }
   else
   {
      for (j=1;j<=i;j++)
         if (t[i-j+1]!=a[j])
            return(0);
      return(1);
   }
}
int can(int i)
{
   void inc1(int[]);
   int j;
   while (i<len)
   {
      inc1(b);
      j=i+1;
      while (j<=len && j-i<=b[0])
      {
         if (b[b[0]-j+i+1]!=t[j])
            return(0);
         j++;
      }
      i+=b[0];
   }
   return(1);
}
int bigger(int a[],int b[])
{
   int i;
   if (a[0]>b[0])
      return(1);
   if (a[0]<b[0])
      return(0);
   for (i=a[0];i>=1;i--)
   {
      if (a[i]>b[i])
         return(1);
      if (a[i]<b[i])
         return(0);
   }
   return(0);
}
void mul(int a[])
{
   int b,i;
   b=a[0];
   for (i=1;i<=a[0];i++)
      a[i]*=b;
   for (i=1;i<=a[0];i++)
   {
      a[i+1]+=a[i]/10;
      a[i]%=10;
   }
   while (a[i+1]!=0)
   {
      i++;
      a[i+1]=a[i]/10;
      a[i]%=10;
   }
   a[0]=i;
}
void minus(int a[],int b[])
{
   int i;
   for (i=1;i<=a[0];i++)
   {
      if (a[i]-b[i]<0)
      {   
         a[i+1]--;
         a[i]+=10;
      }
      a[i]-=b[i];
   }
   while (a[0]>1 && a[a[0]]==0)
      a[0]--;
}
void inc1(int a[])
{
   int i;
   i=1;
   a[i]++;
   while (a[i]==10)
   {
      a[i]=0;
      i++;
      a[i]++;
   }
   if (a[a[0]+1]!=0) 
      a[0]++;
}
void printnum(int a[])
{
   int i;
   int flag=0;
   for (i=a[0];i>=1;i--)
   {
      if (a[i]!=0)
         flag=1;
      if (flag)
         printf("%d",a[i]);
   }
   printf("\n");
}
