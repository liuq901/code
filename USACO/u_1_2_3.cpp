/*
ID: liuq9011
LANG: C++
TASK: namenum
*/
#include <cstdio>
#include <cstring>
FILE *in,*out,*dict;
int main()
{
   in=fopen("namenum.in","r");
   out=fopen("namenum.out","w");
   dict=fopen("dict.txt","r");
   int i,j,l,x,f,flag;
   char n[26],s[5001][26],a[5001][26];
   memset(a,0,sizeof(a));
   for (i=1;i<=4617;i++)
   {
      fscanf(dict,"%s",s[i]);
      for (j=0;j<strlen(s[i]);j++)
      {
         if (s[i][j]=='A' || s[i][j]=='B' || s[i][j]=='C')
            x=2;
         else if (s[i][j]=='D' || s[i][j]=='E' || s[i][j]=='F')
            x=3;
         else if (s[i][j]=='G' || s[i][j]=='H' || s[i][j]=='I')
            x=4;
         else if (s[i][j]=='J' || s[i][j]=='K' || s[i][j]=='L')
            x=5;
         else if (s[i][j]=='M' || s[i][j]=='N' || s[i][j]=='O')
            x=6;
         else if (s[i][j]=='P' || s[i][j]=='R' || s[i][j]=='S')
            x=7;
         else if (s[i][j]=='T' || s[i][j]=='U' || s[i][j]=='V')
            x=8;
         else if (s[i][j]=='W' || s[i][j]=='X' || s[i][j]=='Y')
            x=9;
         a[i][j]=x+'0';
      }
   }
   flag=0;
   fscanf(in,"%s",n);
   l=strlen(n);
   for (i=1;i<=4617;i++)
   {
      f=1;
      for (j=0;j<strlen(n);j++)
      {
         if (l!=strlen(a[i]))
         {
            f=0;
            break;
         }
         if (n[j]!=a[i][j])
         {
            f=0;
            break;
         }
      }
      if (f)
      {
         fprintf(out,"%s\n",s[i]);
         flag=1;
      }
   }
   if (!flag)
      fprintf(out,"NONE\n");
   fclose(in),fclose(out),fclose(dict);
   return(0);
}
