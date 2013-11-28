/*
ID: liuq9011
LANG: C++
TASK: contact
*/
#include <cstdio>
#include <cstring>
#include <cmath>
FILE *in,*out;
int m,f[20][5000];
char s[200001];
int main()
{
   in=fopen("contact.in","r");
   out=fopen("contact.out","w");
   void search(int),print(int,int);
   int i,j,k,x,y,n,t,p,max,flag;
   char ch;
   fscanf(in,"%d%d%d",&x,&y,&n);
   m=0;
   while (1)
   {
      fscanf(in,"%c",&ch);
      if (ch=='0' || ch=='1')
      {
         m++;
         s[m]=ch;
      }
      if (feof(in))
         break;
   }
   memset(f,0,sizeof(f));
   for (i=x;i<=y;i++)
      search(i);
   for (i=1;i<=n;i++)
   {
      max=0;
      for (j=x;j<=y;j++)
         for (k=0;k<=pow(2,j)+0.5;k++)
            if (f[j][k]>max)
               max=f[j][k];
      if (max==0)
         break;
      fprintf(out,"%d\n",max);
      flag=1;
      p=0;
      for (j=x;j<=y;j++)
         for (k=0;k<=pow(2,j)+0.5;k++)
            if (f[j][k]==max)
               p++;
      t=0;
      for (j=x;j<=y;j++)
         for (k=0;k<=pow(2,j)+0.5;k++)
            if (f[j][k]==max)
            {
               if (!flag)
                  fprintf(out," ");
               print(j,k);
               t++;
               flag=0;
               if (t%6==0 && t!=p)
               {
                  fprintf(out,"\n");
                  flag=1;
               }
               f[j][k]=0;
            }
      fprintf(out,"\n");
   }
   fclose(in),fclose(out);
   return(0);  
}
void search(int t)
{
   int i,j,k;
   for (i=1;i<=m-t+1;i++)
   {
      k=0;
      for (j=1;j<=t;j++)
         k=k*2+s[i+j-1]-'0';
      f[t][k]++;
   }
}
void print(int t,int n)
{
   int f[26];
   int i;
   for (i=1;i<=t;i++)
   {
      f[i]=n%2;
      n/=2;
   }
   for (i=t;i>=1;i--)
      fprintf(out,"%d",f[i]);
}
