/*
ID: liuq9011
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <cstdlib>
FILE *in,*out;
int main()
{
   in=fopen("transform.in","r");
   out=fopen("transform.out","w");
   void print(int);
   int n,i,j,flag;
   char t;
   char s[11][11],a[11][11];
   fscanf(in,"%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         fscanf(in,"%c",&s[i][j]);
      fscanf(in,"%*c");
   }
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         fscanf(in,"%c",&a[i][j]);
      fscanf(in,"%*c");
   }
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[j][n-i+1])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(1);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[n-i+1][n-j+1])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(2);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[n-j+1][i])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(3);
   for (i=1;i<=n;i++)
      for (j=1;j<=n/2;j++)
         t=s[i][j],s[i][j]=s[i][n-j+1],s[i][n-j+1]=t;
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[i][j])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(4);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[j][n-i+1])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(5);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[n-i+1][n-j+1])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(5);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[n-j+1][i])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(5);
   flag=1;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         if (s[i][j]!=a[i][n-j+1])
         {
            flag=0;
            break;
         }
      if (!flag)
         break;
   }
   if (flag)
      print(6);
   else
      print(7);
}
void print(int x)
{
   fprintf(out,"%d\n",x);
   fclose(in),fclose(out);
   exit(0);
}
