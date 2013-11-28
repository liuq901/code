#include <cstdio>
#include <cstdlib>
const int x=1000003;
struct data
{
   int s,t,d,ss,tt;
};
struct data *a[100001];
int f[100001],g[100001];
int main()
{
   void sort(int,int);
   int findf(int),findg(int);
   int i,j,k,n,m,s,t,p,ans;
   scanf("%d%d",&n,&m);
   ans=1;
   for (i=1;i<=m;i++)
   {
      a[i]=(struct data *)malloc(sizeof(struct data));
      scanf("%d%d%d",&a[i]->s,&a[i]->t,&a[i]->d);
   }
   a[0]=(struct data *)malloc(sizeof(struct data));
   sort(1,m);
   for (i=1;i<=n;i++)
      f[i]=i;
   j=0;
   for (i=1;i<=m-1;i++)
      if (a[i]->d!=a[i+1]->d)
      {
         t=0;
         for (k=j+1;k<=i;k++)
         {
            a[k]->ss=findf(a[k]->s);
            a[k]->tt=findf(a[k]->t);
         }
         for (s=0;s<=(1<<(i-j))-1;s++)
         {
            for (k=j+1;k<=i;k++)
            {
               g[a[k]->ss]=a[k]->ss;
               g[a[k]->tt]=a[k]->tt;
            }
            p=1;
            for (k=j+1;k<=i;k++)
               if ((1<<(k-j-1)&s)>0)
                  if (findg(a[k]->ss)==findg(a[k]->tt))
                     p=0;
                  else
                     g[g[a[k]->ss]]=g[a[k]->tt];
            for (k=j+1;k<=i;k++)
               if ((1<<(k-j-1)&s)==0)
                  if (findg(a[k]->ss)!=findg(a[k]->tt))
                     p=0;
            if (p)
               t++;
         }
         ans=(ans*t)%x;
         for (j=j+1;j<=i;j++)
            if (findf(a[j]->s)!=findf(a[j]->t))
               f[f[a[j]->s]]=f[a[j]->t];
         j--;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l;
   j=r;
   x=a[(l+r)/2]->d;
   while (i<=j)
   {
      while (a[i]->d<x)
         i++;
      while (a[j]->d>x)
         j--;
      if (i<=j)
      {
         a[0]=a[i],a[i]=a[j],a[j]=a[0];
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int findf(int x)
{
   if (f[x]!=x)
      f[x]=findf(f[x]);
   return(f[x]);
}
int findg(int x)
{
   if (g[x]!=x)
      g[x]=findg(g[x]);
   return(g[x]);
}
