#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[101],b[101],c[201],d[201],f[3][201];
char s[2][101];
int main()
{
   void multi(),work();
   int i;
   scanf("%s %s",&s[0],&s[1]);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   a[0]=strlen(s[0]);
   b[0]=strlen(s[1]);
   for (i=1;i<=a[0];i++)
      a[i]=s[0][a[0]-i]-'0';
   for (i=1;i<=b[0];i++)
      b[i]=s[1][b[0]-i]-'0';
   multi();
   work();
   for (i=1;i<=d[0];i++)
      printf("%d",d[i]);
   printf("\n");
   system("pause");
   return(0);
}
void multi()
{
   int i,j,t;
   c[0]=a[0]+b[0];
   for (i=1;i<=a[0];i++)
      for (j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   while (c[c[0]]==0)
      c[0]--;
   for (i=1;i<=c[0]/2;i++)
      t=c[i],c[i]=c[c[0]-i+1],c[c[0]-i+1]=t;
}
void work()
{
   int compare(int);
   void print();
   int i,k,t,flag;
   memset(f[0],0,sizeof(f[0]));
   memset(f[1],0,sizeof(f[1]));
   for (i=1;i<=a[0];i++)
      f[0][i]=a[a[0]-i+1];
   for (i=1;i<=b[0];i++)
      f[1][i]=b[b[0]-i+1];
   f[0][0]=a[0];
   f[1][0]=b[0];
   flag=1;
   if (a[0]<b[0])
      flag=0;
   else if (a[0]==b[0])
      for (i=1;i<=a[0];i++)
         if (f[0][i]>f[1][i])
            break;
         else if (f[0][i]<f[1][i])
         {
            flag=0;
            break;
         }
   if (!flag)
   {
      memcpy(f[2],f[0],sizeof(f[0]));
      memcpy(f[0],f[1],sizeof(f[1]));
      memcpy(f[1],f[2],sizeof(f[2]));
   }
   while (1)
   {
      t=0;
      while (1)
      {
         t++;
         if (t>f[0][0])
            break;
         while (compare(t))
            for (i=f[0][0];i>=t;i--)
            {
               f[0][i]-=f[1][i-t+1];
               if (f[0][i]<0)
               {
                  f[0][i]+=10;
                  f[0][i-1]--;
               }
            }
      }
      k=-1;
      for (i=1;i<=f[0][0];i++)
         if (f[0][i]!=0)
         {
            k=i;
            break;
         }
      if (k==-1)
         break;
      f[0][0]-=k-1;
      memmove(&f[0][1],&f[0][k],sizeof(int)*f[0][0]);
      memset(&f[0][1+f[0][0]],0,sizeof(int)*(k-1));
      memcpy(f[2],f[0],sizeof(f[0]));
      memcpy(f[0],f[1],sizeof(f[1]));
      memcpy(f[1],f[2],sizeof(f[2]));
   }
   memcpy(f[2],f[1],sizeof(f[1]));
   print();
}
int compare(int x)
{
   int i;
   if (f[0][0]-x+1<f[1][0])
      return(0);
   if (x!=1 && f[0][x-1]!=0)
      return(1);
   for (i=x;i<=f[0][0];i++)
      if (f[0][i]>f[1][i-x+1])
         return(1);
      else if (f[0][i]<f[1][i-x+1])
         return(0);
   return(1);
}
void print()
{
   int check(int);
   int i,t;
   memset(d,0,sizeof(d));
   d[0]=c[0];
   t=0;
   while (1)
   {
      t++;
      if (t>c[0])
         break;
      while (check(t))
      {
         for (i=c[0];i>=t;i--)
         {
            c[i]-=f[2][i-t+1];
            if (c[i]<0)
            {
               c[i]+=10;
               c[i-1]--;
            }
         }
         d[t+f[2][0]-1]++;
      }
   }
   for (i=1;i<=d[0];i++)
      if (d[i]!=0)
      {
         t=i;
         break;
      }
   d[0]-=t-1;
   memmove(&d[1],&d[i],sizeof(int)*d[0]);
}
int check(int x)
{
   int i;
   if (x!=1 && c[x-1]!=0)
      return(1);
   for (i=x;i<=c[0];i++)
      if (c[i]>f[2][i-x+1])
         return(1);
      else if (c[i]<f[2][i-x+1])
         return(0);
   return(1);
}
