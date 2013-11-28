/*
ID: liuq9011
LANG: C++
TASK: lgame
*/
#include <cstdio>
#include <cstring>
FILE *in,*dict,*out;
const int f[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int flag[26],a[3][100000];
char s[40001][10],ans[2][40001][10];
int main()
{
   in=fopen("lgame.in","r");
   dict=fopen("lgame.dict","r");
   out=fopen("lgame.out","w");
   int check(char *),count(char *),work(char *,char *);
   void print(int,int);
   int i,j,n,m,max;
   char p[10],q[10];
   fscanf(in,"%s",p);
   memset(flag,0,sizeof(flag));
   for (i=0;i<strlen(p);i++)
      flag[p[i]-'a']++;
   n=0;
   while (1)
   {
      fscanf(dict,"%s",q);
      if (q[0]=='.')
         break;
      if (check(q))
      {
         n++;
         memcpy(s[n],q,sizeof(q));
      }
   }
   m=0;
   for (i=1;i<=n;i++)
   {
      m++;
      a[0][m]=count(s[i]);
      a[1][m]=i;
      a[2][m]=0;
   }
   for (i=1;i<=n;i++)
      for (j=i;j<=n;j++)
      {
         m++;
         a[0][m]=work(s[i],s[j]);
         a[1][m]=i;
         a[2][m]=j;
      }
   max=0;
   for (i=1;i<=m;i++)
      if (a[0][i]>max)
         max=a[0][i];
   print(m,max);
   fclose(in),fclose(dict),fclose(out);
   return(0);
}
int check(char *s)
{
   int i,l;
   int f[26];
   memset(f,0,sizeof(f));
   l=strlen(s);
   for (i=0;i<l;i++)
      f[s[i]-'a']++;
   for (i=0;i<=25;i++)
      if (f[i]>flag[i])
         return(0);
   return(1);
}
int count(char *s)
{
   int i,l,ans;
   ans=0;
   l=strlen(s);
   for (i=0;i<l;i++)
      ans+=f[s[i]-'a'];
   return(ans);
}
int work(char *p,char *q)
{
   int i,l,ans;
   int g[26];
   ans=0;
   l=strlen(p);
   memset(g,0,sizeof(g));
   for (i=0;i<l;i++)
   {
      ans+=f[p[i]-'a'];
      g[p[i]-'a']++;
   }
   l=strlen(q);
   for (i=0;i<l;i++)
   {
      ans+=f[q[i]-'a'];
      g[q[i]-'a']++;
   }
   for (i=0;i<=25;i++)
      if (g[i]>flag[i])
         return(0);
   return(ans);
}
void print(int m,int max)
{
   int i,j,p;
   char t[10];
   fprintf(out,"%d\n",max);
   p=0;
   s[0][0]='\0';
   for (i=1;i<=m;i++)
      if (a[0][i]==max)
      {
         p++;
         memcpy(ans[0][p],s[a[1][i]],sizeof(s[a[1][i]]));
         memcpy(ans[1][p],s[a[2][i]],sizeof(s[a[2][i]]));
      }
   for (i=1;i<=p-1;i++)
      for (j=i+1;j<=p;j++)
      {
         if (strcmp(ans[0][i],ans[0][j])>0)
         {
            memcpy(t,ans[0][i],sizeof(ans[0][i]));
            memcpy(ans[0][i],ans[0][j],sizeof(ans[0][j]));
            memcpy(ans[0][j],t,sizeof(t));
            memcpy(t,ans[1][i],sizeof(ans[1][i]));
            memcpy(ans[1][i],ans[1][j],sizeof(ans[1][j]));
            memcpy(ans[1][j],t,sizeof(t));
         }
         if (strcmp(ans[0][i],ans[0][j])==0 && strcmp(ans[1][i],ans[1][j])>0)
         {
            memcpy(t,ans[0][i],sizeof(ans[0][i]));
            memcpy(ans[0][i],ans[0][j],sizeof(ans[0][j]));
            memcpy(ans[0][j],t,sizeof(t));
            memcpy(t,ans[1][i],sizeof(ans[1][i]));
            memcpy(ans[1][i],ans[1][j],sizeof(ans[1][j]));
            memcpy(ans[1][j],t,sizeof(t));
         }
      }
   for (i=1;i<=p;i++)
   {
      fprintf(out,"%s",ans[0][i]);
      if (ans[1][i][0]!='\0')
         fprintf(out," %s",ans[1][i]);
      fprintf(out,"\n");
   }
}
