/*
ID: liuq9011
LANG: C++
TASK: msquare
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
const int w[9]={0,1,2,6,24,120,720,5040,40320};
int a[100000][8],b[8],f[50000],t[100000];
char s[100000][30];
int main()
{
   in=fopen("msquare.in","r");
   out=fopen("msquare.out","w");
   int cantor(int),work();
   int i,l,r,x,y,n;
   for (i=0;i<=7;i++)
   {
      fscanf(in,"%d",&b[i]);
      a[1][i]=i+1;
   }
   l=r=1;
   y=work();
   memset(f,0,sizeof(f));
   memset(s,0,sizeof(s));
   memset(t,0,sizeof(t));
   f[1]=1;
   while (1)
   {
      r++;
      for (i=0;i<=7;i++)
         a[r][i]=a[l][7-i];
      x=cantor(r);
      if (f[x])
         r--;
      else
      {
         f[x]=1;
         t[r]=t[l]+1;
         for (i=1;i<=t[l];i++)
            s[r][i]=s[l][i];
         s[r][t[r]]='A';
      }
      r++;
      for (i=1;i<=3;i++)
         a[r][i]=a[l][i-1];
      for (i=4;i<=6;i++)
         a[r][i]=a[l][i+1];
      a[r][0]=a[l][3];
      a[r][7]=a[l][4];
      x=cantor(r);
      if (f[x])
         r--;
      else
      {
         f[x]=1;
         t[r]=t[l]+1;
         for (i=1;i<=t[l];i++)
            s[r][i]=s[l][i];
         s[r][t[r]]='B';
      }
      r++;
      a[r][0]=a[l][0];
      a[r][3]=a[l][3];
      a[r][4]=a[l][4];
      a[r][7]=a[l][7];
      a[r][1]=a[l][6];
      a[r][2]=a[l][1];
      a[r][5]=a[l][2];
      a[r][6]=a[l][5];
      x=cantor(r);
      if (f[x])
         r--;
      else
      {
         f[x]=1;
         t[r]=t[l]+1;
         for (i=1;i<=t[l];i++)
            s[r][i]=s[l][i];
         s[r][t[r]]='C';
      }
      x=cantor(l);
      if (x==y)
      {
         fprintf(out,"%d\n",t[l]);
         for (i=1;i<=t[l];i++)
         {
            fprintf(out,"%c",s[l][i]);
            if (i%60==0 && i!=t[l])
               fprintf(out,"\n");
         }
         fprintf(out,"\n");
         break;
      }
      l++;
   }
   fclose(in),fclose(out);
   return(0);
}
int cantor(int x)
{
   int i,j,s,t;
   int c[8];
   for (i=0;i<=7;i++)
      c[i]=a[x][i];
   t=0;
   for (i=0;i<=6;i++)
   {
      s=0;
      for (j=i+1;j<=7;j++)
         if (c[j]<c[i])
            s++;
      t+=s*w[7-i];
   }
   return(t+1);
}
int work()
{
   int i,j,s,t;
   int c[8];
   for (i=0;i<=7;i++)
      c[i]=b[i];
   t=0;
   for (i=0;i<=6;i++)
   {
      s=0;
      for (j=i+1;j<=7;j++)
         if (c[j]<c[i])
            s++;
      t+=s*w[7-i];
   }
   return(t+1);
}
