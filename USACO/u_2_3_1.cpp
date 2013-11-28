/*
ID: liuq9011
LANG: C++
TASK: prefix
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("prefix.in","r");
   out=fopen("prefix.out","w");
   int n,i,j,k,l,flag;
   int f[200001];
   char s[210001],ss[100],a[260][100];
   n=0;
   while (1)
   {
      n++;
      fscanf(in,"%s",a[n]);
      if (a[n][0]=='.')
      {
         n--;
         break;
      }
   }
   memset(s,0,sizeof(s));
   while (fscanf(in,"%s",ss)!=EOF)
      strcat(s,ss);
   l=strlen(s);
   memset(f,0,sizeof(f));
   f[0]=1;
   for (i=0;i<=l-1;i++)
      if (f[i])
         for (j=1;j<=n;j++)
         {
            flag=1;
            for (k=0;k<strlen(a[j]);k++)
               if (a[j][k]!=s[i+k])
               {
                  flag=0;
                  break;
               }
            f[i+strlen(a[j])]|=flag;
         }
   for (i=l;i>=0;i--)
      if (f[i])
      {
         fprintf(out,"%d\n",i);
         break;
      }
   fclose(in),fclose(out);
   return(0);
}
