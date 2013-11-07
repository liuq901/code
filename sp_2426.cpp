#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,sa[60010],rank[60010],a[60010],height[60010],p[60010];
char s[30010];
int main()
{
   void init();
   int k;
   scanf("%d\n",&k);
   gets(s);
   n=strlen(s);
   for (int i=1;i<=n;i++)
      a[i]=s[i-1]-'a'+1;
   for (int i=1;i<=n;i++)
      a[i+n]=s[n-i]-'a'+1;
   n<<=1;
   init();
   p[0]=0;
   for (int i=1;i<=n;i++)
   {
      if (height[i]<k)
      {
         p[sa[i]]=++p[0];
         continue;
      }
      p[sa[i]]=p[0];
   }
   int ans=0;
   n>>=1;
   for (int i=1;i<=n-k+1;i++)
      if (p[i]==p[(n<<1)-i-k+2])
         ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int b[60010],c[60010];
void init()
{
   void sort(int *);
   int count(int *,int *);
   for (int i=1;i<=n;i++)
   {
      c[i]=a[i];
      b[i]=-1;
      sa[i]=i;
   }
   sort(c);
   count(c,b);
   int k=1;
   while (1)
   {
      for (int i=1;i<=n;i++)
      {
         c[i]=rank[i];
         if (i+k<=n)
            b[i]=rank[i+k];
         else
            b[i]=0;
      }
      sort(b),sort(c);
      if (count(c,b)>=n)
         break;
      k<<=1;
   }
   k=0;
   for (int i=1;i<=n;i++)
   {
      k=k?k-1:0;
      if (rank[i]==1)
      {
         height[rank[i]]=0;
         continue;
      }
      int p=sa[rank[i]-1],q=sa[rank[i]];
      while (a[p+k]==a[q+k])
         k++;
      height[rank[i]]=k;
   }
}
int x[60010],f[60010];
void sort(int *a)
{
   memset(f,0,sizeof(f));
   int t=0;
   for (int i=1;i<=n;i++)
   {
      f[a[i]]++;
      if (a[i]>=t)
         t=a[i];
   }
   for (int i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (int i=n;i>=1;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (int i=1;i<=n;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   rank[sa[1]]=1;
   int t=1;
   for (int i=2;i<=n;i++)
   {
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
