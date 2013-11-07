#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,one[200],s[200],a[200],b[200],c[200],q[200],t[200],p[101][200],f[101][200];
int main()
{
   void init(),binary(),plus(int *,int *,int *);
   int same(),check(int *);
   int i;
   scanf("%d%d",&n,&m);
   init();
   one[0]=1;
   one[1]=1;
   a[0]=1;
   a[1]=1;
   memcpy(b,f[n],sizeof(f[n]));
   while (!same())
   {
      binary();
      if (check(c))
         memcpy(b,c,sizeof(c));
      else
         plus(a,c,one);
   }
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
void init()
{
   void multi(int *,int *,int),plus(int *,int *,int *);
   int i,j,k;
   p[0][0]=1;
   p[0][1]=1;
   for (i=1;i<=n;i++)
      multi(p[i],p[i-1],2);
   f[0][0]=1;
   f[0][1]=0;
   for (i=1;i<=n;i++)
   {
      multi(f[i],f[i-1],2);
      plus(f[i],f[i],p[i-1]);
   }
}
void binary()
{
   void plus(int *,int *,int *);
   int i,x;
   int tmp[200];
   plus(tmp,a,b);
   c[0]=tmp[0];
   x=0;
   for (i=c[0];i>=1;i--)
   {
      x=x*10+tmp[i];
      c[i]=x/2;
      x%=2;
   }
   while (c[c[0]]==0 && c[0]>0)
      c[0]--;
}
int same()
{
   int i;
   if (a[0]!=b[0])
      return(0);
   for (i=1;i<=a[0];i++)
      if (a[i]!=b[i])
         return(0);
   return(1);
}
int check(int *a)
{
   void plus(int *,int *,int *),work();
   int i;
   memset(t,0,sizeof(t));
   memset(q,0,sizeof(q));
   for (i=1;i<=m;i++)
   {
      plus(q,t,a);
      work();
   }
   for (i=1;i<=n;i++)
      if (s[i]==0)
         return(0);
   return(1);
}
void work()
{
   void multi(int *,int *,int),plus(int *,int *,int *);
   int compare(int *,int *);
   int i,l;
   int s1[200],s2[200],s3[200];
   memset(t,0,sizeof(t));
   l=0;
   for (i=n;i>=1;i--)
   {
      multi(s1,p[i-1],l);
      plus(s2,s1,f[i-1]);
      plus(s2,s2,one);
      plus(s3,s2,t);
      if (!compare(s3,q))
      {
         s[i]=1;
         l++;
         plus(t,t,s2);
      }
      else
         s[i]=0;
   }
}
int compare(int *a,int *b)
{
   int i;
   if (a[0]>b[0])
      return(1);
   if (a[0]<b[0])
      return(0);
   for (i=a[0];i>=1;i--)
   {
      if (a[i]>b[i])
         return(1);
      if (a[i]<b[i])
         return(0);
   }
   return(0);
}
void plus(int *c,int *a,int *b)
{
   int i,x;
   if (a[0]>b[0])
      c[0]=a[0];
   else
      c[0]=b[0];
   for (i=a[0]+1;i<=c[0];i++)
      a[i]=0;
   for (i=b[0]+1;i<=c[0];i++)
      b[i]=0;
   x=0;
   for (i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
}
void multi(int *a,int *b,int t)
{
   int i,x;
   a[0]=b[0];
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=b[i]*t+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
