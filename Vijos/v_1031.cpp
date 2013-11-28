#include <cstdio>
#include <cstdlib>
#include <cstring>
const char ans[50]="Begin the Escape execution at the Break of Dawn";
char s[100];
int n,l,f[100000];
int main()
{
   void did();
   for (int i=1;i<=10;i++)
      did();
   system("pause");
   return(0);
}
void did()
{
   void work();
   int i,flag;
   gets(s);
   if (s[strlen(s)-1]=='\n')
      s[strlen(s)-1]='\0';
   if (strlen(s)!=strlen(ans))
      work();
   else
   {
      flag=0;
      for (i=0;i<strlen(s);i++)
         if (ans[i]!=s[i])
         {
            flag=1;
            break;
         }
      if (flag)
         work();
      else
         printf("YES\n");
   }
}
void work()
{
   int search(int);
   int k;
   l=strlen(ans);
   n=strlen(s);
   if ((n-l)%3!=0)
   {
      printf("NO\n");
      return;
   }
   memset(f,0,sizeof(f));
   k=search(0);
   if (k==0)
      printf("NO\n");
   else
      printf("YES\n");
}
int search(int t)
{
   int check(),same();
   void move(int,int,int);
   int i,j,k,p,n;
   char q[100];
   if (same())
      return(t);
   if (!check())
      return(0);
   n=strlen(s);
   for (i=0;i<n;i++)
   {
      if (s[i]!='O')
         continue;
      for (j=i-1;j>=0;j--)
      {
         if (s[j]!='C')
            continue;
         for (k=n-1;k>=i+1;k--)
         {
            if (s[k]!='W')
               continue;
            memcpy(q,s,sizeof(s));
            move(j,i,k);
            p=search(t+1);
            if (p!=0)
               return(p);
            memcpy(s,q,sizeof(q));
         }
      }
   }
   return(0);
}
int check()
{
   int hash(char *);
   int len,i,j,k,t,m,flag;
   len=strlen(s);
   k=hash(s);
   if (f[k])
      return(0);
   f[k]=1;
   k=len;
   for (i=0;i<len;i++)
      if (s[i]=='C')
      {
         k=i;
         break;
      }
   flag=1;
   for (i=0;i<k;i++)
      if (s[i]!=ans[i])
      {
         flag=0;
         break;
      }
   if (!flag)
      return(0);
   k=-1;
   for (i=len-1;i>=0;i--)
      if (s[i]=='W')
      {
         k=i;
         break;
      }
   j=l-1;
   for (i=len-1;i>=k+1;i--)
   {
      if (s[i]!=ans[j])
      {
         flag=0;
         break;
      }
      j--;
   }
   if (!flag)
      return(0);
   k=0;
   for (i=1;i<len;i++)
      if (s[i]=='C' || s[i]=='O' || s[i]=='W')
      {
         k=i;
         break;
      }
   if (k!=0)
   {
      j=0;
      for (i=k+1;i<len;i++)
         if (s[i]=='C' || s[i]=='O' || s[i]=='W')
         {
            j=i;
            break;
         }
      if (j==0)
         return(0);
      i=k;
      while (1)
      {
         for (t=0;t<=i-j+l+1;t++)
         {
            m=0;
            flag=0;
            for (k=i+1;k<=j-1;k++)
            {
               if (ans[t+m]!=s[k])
               {
                  flag=1;
                  break;
               }
               m++;
            }
            if (!flag)
               break;
         }
         if (flag)
            return(0);
         flag=0;
         for (k=j+1;k<len;k++)
            if (s[k]=='C' || s[k]=='O' || s[k]=='W')
            {
               i=j;
               j=k;
               flag=1;
               break;
            }
         if (!flag)
            break;
      }
   }
   return(1);
}
int hash(char *s)
{
   int i,l,h,g;
   l=strlen(s);
   h=0;
   for (i=0;i<l;i++)
   {
      h=(h<<4)+s[i];
      g=h&0xf0000000;
      if (g!=0)
         h^=g>>24;
      h&=~g;
   }
   return(h%99991);
}
int same()
{
   int len,i;
   len=strlen(s);
   if (len!=l)
      return(0);
   for (i=0;i<l;i++)
      if (s[i]!=ans[i])
         return(0);
   return(1);
}
void move(int x,int y,int z)
{
   int i,j,len;
   char p[100];
   j=-1;
   len=strlen(s);
   for (i=0;i<x;i++)
   {
      j++;
      p[j]=s[i];
   }
   for (i=y+1;i<=z-1;i++)
   {
      j++;
      p[j]=s[i];
   }
   for (i=x+1;i<=y-1;i++)
   {
      j++;
      p[j]=s[i];
   }
   for (i=z+1;i<len;i++)
   {
      j++;
      p[j]=s[i];
   }
   p[j+1]='\0';
   memcpy(s,p,sizeof(p));
}
