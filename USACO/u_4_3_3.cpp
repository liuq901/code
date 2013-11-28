/*
ID: liuq9011
LANG: C++
TASK: race3
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,a[50][50];
int main()
{
   in=fopen("race3.in","r");
   out=fopen("race3.out","w");
   int work(int),check(int);
   int i,x,t,s1,s2;
   int f[50],ans[2][50];
   t=-1;
   memset(a,0,sizeof(a));
   while (1)
   {
      t++;
      while (1)
      {
         fscanf(in,"%d",&x);
         if (x<0)
            break;
         a[t][x]=1;
      }
      if (x==-1)
         break;
   }
   n=t-1;
   memset(f,0,sizeof(f));
   for (i=1;i<=n-1;i++)
      f[i]=work(i);
   memset(ans,0,sizeof(ans));
   s1=s2=0;
   for (i=1;i<=n-1;i++)
      if (f[i])
      {
         s1++;
         ans[0][s1]=i;
         if (check(i))
         {
            s2++;
            ans[1][s2]=i;
         }
      }
   fprintf(out,"%d",s1);
   for (i=1;i<=s1;i++)
      fprintf(out," %d",ans[0][i]);
   fprintf(out,"\n");
   fprintf(out,"%d",s2);
   for (i=1;i<=s2;i++)
      fprintf(out," %d",ans[1][i]);
   fprintf(out,"\n");
   fclose(in),fclose(out);
   return(0);
}
int work(int x)
{
   int i,l,r;
   int q[50],f[50];
   memset(f,0,sizeof(f));
   l=r=1;
   q[1]=0;
   f[0]=1;
   while (1)
   {
      for (i=1;i<=n;i++)
      {
         if (i==x)
            continue;
         if (f[i])
            continue;
         if (a[q[l]][i])
         {
            r++;
            q[r]=i;
            f[i]=1;
         }
      }
      if (q[l]==n)
         return(0);
      l++;
      if (l>r)
         break;
   }
   return(1);
}
int check(int x)
{
   int i,l,r;
   int q[50],f[50],g[50];
   memset(f,0,sizeof(f));
   memset(g,0,sizeof(g));
   l=r=1;
   q[1]=x;
   f[x]=1;
   while (1)
   {
      for (i=0;i<=n;i++)
      {
         if (f[i])
            continue;
         if (a[q[l]][i])
         {
            r++;
            q[r]=i;
            f[i]=1;
            g[i]=1;
         }
      }
      if (q[l]==0)
         return(0);
      l++;
      if (l>r)
         break;
   }
   memset(f,0,sizeof(f));
   l=r=1;
   q[1]=0;
   f[0]=1;
   while (1)
   {
      for (i=1;i<=n;i++)
      {
         if (i==x)
            continue;
         if (f[i])
            continue;
         if (a[q[l]][i])
         {
            r++;
            q[r]=i;
            f[i]=1;
         }
      }
      if (g[l])
         return(0);
      l++;
      if (l>r)
         break;
   }
   return(1);
}
