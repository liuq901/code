#include <cstdio>
#include <cstdlib>
int n,x;
int a[27],b[27],c[27],d[27],p[27],t[27],f[27];
int main()
{
   void init();
   void solve(int);
   int i,tot;
   init();
   for (i=0;i<=26;i++)
      f[i]=1;
   tot=0;
   for (i=n;i>=1;i--)
   {
      if (f[a[i]])
      {
         tot++;
         d[tot]=a[i];
         f[a[i]]=0;
      }
      if (f[b[i]])
      {
         tot++;
         d[tot]=b[i];
         f[b[i]]=0;
      }
      if (f[c[i]])
      {
         tot++;
         d[tot]=c[i];
         f[c[i]]=0;
      }
   }
   for (i=0;i<=26;i++)
   {
      p[i]=-1;
      f[i]=1;
   }
   solve(1);
   system("pause");
   return(0);
}
void init()
{
   int i;
   char ch;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      a[i]=ch-'A'+1;
   }
   scanf("%*c");
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      b[i]=ch-'A'+1;
   }
   scanf("%*c");
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      c[i]=ch-'A'+1;
   }
}
void solve(int k)
{
   int ok(int,int);
   int can(int,int,int,int);
   void print();
   int i;
   for (i=0;i<=26;i++)
      t[i]=-1;
   t[n]=0;
   for (i=n;i>=1;i--)
   {
      if (t[i]>=0 && p[a[i]]>=0 && p[b[i]]>=0)
         if (t[i]+p[a[i]]+p[b[i]]>=n)
            t[i-1]=1;
         else
            t[i-1]=0;
      if (p[a[i]]>=0 && p[b[i]]>=0)
      {
         if (t[i]>=0 && !can(p[a[i]],p[b[i]],t[i],p[c[i]])) 
            return;
         if (t[i]==-1 && !can(p[a[i]],p[b[i]],0,p[c[i]]) && !can(p[a[i]],p[b[i]],1,p[c[i]]))
            return;
      }
      else if (p[b[i]]>=0 && p[c[i]]>=0)
      {
         if (t[i]>=0 && !ok(p[b[i]]+t[i],p[c[i]]))
            return;
         if (t[i]==-1 && !ok(p[b[i]],p[c[i]]) && !ok(p[b[i]]+1,p[c[i]]))
            return;
      }
      else if (p[a[i]]>=0 && p[c[i]]>=0)
      {
         if (t[i]>=0 && !ok(p[a[i]]+t[i],p[c[i]]))
            return;
         if (t[i]==-1 && !ok(p[a[i]],p[c[i]]) && !ok(p[a[i]]+1,p[c[i]]))
            return;
      }
   }
   if (t[0]>0)
      return;
   if (k>n)
      print();
   for (i=n-1;i>=0;i--)
      if (f[i])
      {
         p[d[k]]=i;
         f[i]=0;
         solve(k+1);
         f[i]=1;
      }
   p[d[k]]=-1;
}
int ok(int a,int b)
{
   x=b-a;
   if (x<0)
      x+=n;
   return(f[x]);
}
int can(int a,int b,int t,int c)
{
   x=a+b+t;
   if (x>=n)
      x-=n;
   if (c>=0 && c==x)
      return(1);
   if (c==-1 && f[x])
      return(1);
    return(0);
}
void print()
{
   int i;
   for (i=1;i<=n-1;i++)
      printf("%d ",p[i]);
   printf("%d\n",p[n]);
   system("pause");
   exit(0);
}
