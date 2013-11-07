#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[200010],sa[200010],rank[200010],height[200010];
int b[200010],c[200010],f[200010],x[200010],stack[200010][2];
char s[200010];
int main()
{
   void build(),print(int,int);
   int m,k,i,l;
   while (1)
   {
      scanf("%d",&k);
      if (k==0)
         break;
      scanf("%s",s);
      m=l=strlen(s);
      for (i=1;i<=l;i++)
         a[i]=s[i-1];
      n=m+1;
      a[n]=0;
      scanf("%s",s);
      l=strlen(s);
      for (i=1;i<=l;i++)
         a[n+i]=s[i-1];
      n+=l;
      a[n+1]=-1;
      build();
      print(k,m);
   }
   system("pause");
   return(0);
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,k,p,q;
   for (i=1;i<=n;i++)
   {
      b[i]=a[i];
      c[i]=-1;
      sa[i]=i;
   }
   sort(b);
   k=1;
   while (count(b,c)<n)
   {
      for (i=1;i<=n;i++)
      {
         b[i]=rank[i];
         if (i+k<=n)
            c[i]=rank[i+k];
         else
            c[i]=0;
      }
      sort(c);
      sort(b);
      k*=2;
   }
   k=0;
   for (i=1;i<=n;i++)
   {
      if (k>0)
         k--;
      if (rank[i]==1)
      {
         height[rank[i]]=0;
         continue;
      }
      p=sa[rank[i]-1];
      q=sa[rank[i]];
      while (a[p+k]==a[q+k])
         k++;
      height[rank[i]]=k;
   }
}
void sort(int *a)
{
   int i,t;
   t=0;
   for (i=1;i<=n;i++)
      if (a[i]>t)
         t=a[i];
   for (i=0;i<=t;i++)
      f[i]=0;
   for (i=1;i<=n;i++)
      f[a[i]]++;
   for (i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (i=n;i>=1;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (i=1;i<=n;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   int i,t;
   rank[sa[1]]=t=1;
   for (i=2;i<=n;i++)
   {
      if (a[sa[i-1]]!=a[sa[i]] || b[sa[i-1]]!=b[sa[i]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
void print(int k,int m)
{
   int i,t,tot;
   long long ans,sum;
   for (i=1;i<=n;i++)
   {
      height[i]-=k-1;
      if (height[i]<0)
         height[i]=0;
   }
   height[n+1]=-1;
   tot=0;
   stack[tot][0]=-1;
   ans=sum=0;
   for (i=2;i<=n+1;i++)
   {
      if (sa[i-1]<=m)
         ans+=sum;
      if (height[i]==0)
      {
         tot=0;
         sum=0;
      }
      if (sa[i-1]<=m && height[i]>=stack[tot][0] || height[i]==0)
         continue;
      if (sa[i-1]<=m)
         t=0;
      else
         t=1;
      while (1)
      {
         if (height[i]>stack[tot][0])
         {
            sum+=height[i]*t;
            tot++;
            stack[tot][0]=height[i];
            stack[tot][1]=t;
            break;
         }
         if (height[i]<stack[tot][0])
         {
            sum-=(long long)stack[tot][0]*stack[tot][1];
            t+=stack[tot][1];
            tot--;
            continue;
         }
         sum+=(long long)stack[tot][0]*t;
         stack[tot][1]+=t;
         break;
      }
   }
   sum=0;
   tot=0;
   for (i=2;i<=n+1;i++)
   {
      if (sa[i-1]>m)
         ans+=sum;
      if (height[i]==0)
      {
         tot=0;
         sum=0;
      }
      if (sa[i-1]>m && height[i]>=stack[tot][0] || height[i]==0)
         continue;
      if (sa[i-1]>m)
         t=0;
      else
         t=1;
      while (1)
      {
         if (height[i]>stack[tot][0])
         {
            sum+=height[i]*t;
            tot++;
            stack[tot][0]=height[i];
            stack[tot][1]=t;
            break;
         }
         if (height[i]<stack[tot][0])
         {
            sum-=(long long)stack[tot][0]*stack[tot][1];
            t+=stack[tot][1];
            tot--;
            continue;
         }
         sum+=(long long)stack[tot][0]*t;
         stack[tot][1]+=t;
         break;
      }
   }
   printf("%I64d\n",ans);
}
