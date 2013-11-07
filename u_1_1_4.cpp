/*
ID: liuq9011
LANG: C++
TASK: beads
*/
#include <cstdio>
FILE *in,*out;
int main()
{
   in=fopen("beads.in","r");
   out=fopen("beads.out","w");
   int n,i,j,s1,s2,max;
   char ch,a[10001];
   fscanf(in,"%d%*c",&n);
   for (i=1;i<=n;i++)
      fscanf(in,"%c",&a[i]);
   max=0;
   for (i=1;i<=n;i++)
   {
      j=i;
      ch=a[i];
      s1=0;
      while (1)
      {
         if (ch=='w')
         {
            j++;
            if (j>n)
               j=1;
            ch=a[j];
            s1++;
         }
         else if (a[j]==ch || a[j]=='w')
         {
            j++;
            if (j>n)
               j=1;
            s1++;
         }
         else
            break;
         if (s1>=n)
            break;
      }
      s2=0;
      j=i-1;
      ch=a[j];
      if (j==0)
         j=n;
      while (1)
      {
         if (ch=='w')
         {
            j--;
            if (j==0)
               j=n;
            ch=a[j];
            s2++;
         }
         else if (a[j]==ch || a[j]=='w')
         {
            j--;
            if (j==0)
               j=n;
            s2++;
         }
         else
            break;
         if (s2>=n)
            break;
      }
      if (s1+s2>max)
         max=s1+s2;
      if (max>=n)
      {
         max=n;
         break;
      }
   }
   fprintf(out,"%d\n",max);
   fclose(in),fclose(out);
   return(0);
}
