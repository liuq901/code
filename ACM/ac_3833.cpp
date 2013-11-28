#include <cstdio>
#include <cstdlib>
#include <cstring>
int p[10001],d[10001],f[10001],s[10001];
int main()
{
   void sort(int,int);
   int get(int);
   int n,l;
   while (scanf("%d%d",&n,&l)!=EOF)
   {
      int m=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&p[i],&d[i]);
         m>?=p[i];
      }
      sort(1,n);
      for (int i=0;i<=m;i++)
         f[i]=i;
      int ans=0;
      memset(s,0,sizeof(s));
      for (int i=1;i<=n;i++)
      {
         if (!l)
            break;
         int x=get(d[i]);
         if (!x && s[x]==l)
            continue;
         s[x]++;
         ans+=p[i];
         if (x && s[x]==l)
         {
            int k=get(x-1);
            f[x]=k;
         }
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=p[l+r>>1];
   while (i<=j)
   {
      while (p[i]>x)
         i++;
      while (p[j]<x)
         j--;
      if (i<=j)
      {
         t=p[i],p[i]=p[j],p[j]=t;
         t=d[i],d[i]=d[j],d[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int get(int x)
{
   if (x!=f[x])
      f[x]=get(f[x]);
   return(f[x]);
}
