#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int n,ans[3],a[100010],sa[100010],rank[100010],height[100010];
int b[100010],c[100010],g[100010],x[100010],f[20][100010];
char s[100010];
int main()
{
   void work();
   int i;
   i=0;
   while (1)
   {
      i++;
      scanf("%s",s);
      n=strlen(s);
      if (n==1 && s[0]=='#')
         break;
      printf("Case %d: ",i);
      work();
   }
   system("pause");
   return(0);
}
void work()
{
   void build(),find(int);
   int i,k,min;
   min=20000000;
   for (i=1;i<=n;i++)
   {
      a[i]=s[i-1];
      if (a[i]<min)
      {
         min=a[i];
         k=i;
      }
   }
   a[n+1]=-1;
   build();
   ans[0]=1;
   ans[1]=ans[2]=k;
   for (i=1;i<=n/2;i++)
      find(i);
   for (i=ans[1];i<=ans[2];i++)
      printf("%c",a[i]);
   printf("\n");
}
void build()
{
   void sort(int *);
   int count(int *,int *);
   int i,j,t,k,p,q;
   for (i=1;i<=n;i++)
   {
      b[i]=a[i];
      c[i]=-1;
      sa[i]=i;
   }
   sort(b);
   count(b,c);
   k=1;
   while (1)
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
      if (count(b,c)>=n)
         break;
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
      while (1)
      {
         if (a[p+k]!=a[q+k])
            break;
         k++;
      }
      height[rank[i]]=k;
   }
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
      f[0][i]=height[i];
   t=(int)(log(n)/log(2));
   k=1;
   for (i=1;i<=t;i++)
   {
      k*=2;
      for (j=1;j<=n;j++)
      {
         if (j+k-1>n)
            break;
         if (f[i-1][j]<f[i-1][j+k/2])
            f[i][j]=f[i-1][j];
         else
            f[i][j]=f[i-1][j+k/2];
      }
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
      g[i]=0;
   for (i=1;i<=n;i++)
      g[a[i]]++;
   for (i=1;i<=t;i++)
      g[i]+=g[i-1];
   for (i=n;i>=1;i--)
   {
      x[g[a[sa[i]]]]=sa[i];
      g[a[sa[i]]]--;
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
void find(int l)
{
   int calc(int,int);
   int i,j,x,p,q;
   i=1;
   while (1)
   {
      if (i+l>n)
         break;
      p=calc(i,i+l);
      x=p%l;
      if (x!=0)
      {
         x=l-x;
         q=calc(i-x,i+l-x);
         if (q>x)
         {
            p+=x;
            q=i-x;
         }
         else
            q=i;
      }
      if (p/l+1>=ans[0])
      {
         q=p/l+1;
         j=i+1;
         while (1)
         {
            j--;
            if (j<=0 || j==i-l)
               break;
            p=calc(j,j+l);
            if (p/l+1<q-1)
               break;
            if (p/l+1==ans[0] && rank[j]<rank[ans[1]])
            {
               ans[1]=j;
               ans[2]=j+l*ans[0]-1;
            }               
            if (p/l+1>ans[0])
            {
               ans[0]=p/l+1;
               ans[1]=j;
               ans[2]=j+l*ans[0]-1;
            }
         }
      }
      i+=l;
   }
}
int calc(int x,int y)
{
   int min(int,int);
   int p,q,t,k;
   p=rank[x];
   q=rank[y];
   if (p>q)
      t=p,p=q,q=t;
   p++;
   t=q-p+1;
   k=(int)(log(t)/log(2));
   return(min(f[k][p],f[k][q-(1<<k)+1]));
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
