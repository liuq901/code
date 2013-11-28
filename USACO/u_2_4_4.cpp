/*
ID: liuq9011
LANG: C++
TASK: comehome
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("comehome.in","r");
   out=fopen("comehome.out","w");
   int i,j,k,n,s1,s2,z,min;
   int a[100][100];
   char x,y;
   fscanf(in,"%d%*c",&n);
   memset(a,31,sizeof(a));
   for (i=1;i<=n;i++)
   {
      fscanf(in,"%c%*c%c%d%*c",&x,&y,&z);
      if (x>='A' && x<='Z')
         s1=x-'A'+1;
      else
         s1=x-'a'+27;
      if (y>='A' && y<='Z')
         s2=y-'A'+1;
      else
         s2=y-'a'+27;
      if (z<a[s1][s2])
      {
         a[s1][s2]=z;
         a[s2][s1]=z;
      }
   }
   for (i=1;i<=52;i++)
      for (j=1;j<=52;j++)
         for (k=1;k<=52;k++)
            if (a[j][i]+a[i][k]<a[j][k])
               a[j][k]=a[j][i]+a[i][k];
   min=20000000;
   for (i=1;i<=25;i++)
      if (a[i][26]<min)
      {
         min=a[i][26];
         k=i;
      }
   fprintf(out,"%c %d\n",k-1+'A',min);
   fclose(in),fclose(out);
   return(0);
}
