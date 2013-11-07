#include <cstdio>
#include <cstdlib>
int v[100001],l[100001],r[100001],d[100001],f[100001];
int main()
{
   int find(int),merge(int,int);
   d[0]=-1;
   int n;
   while (scanf("%d",&n)!=EOF)
   {
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&v[i]);
         f[i]=i;
         l[i]=r[i]=d[i]=0;
      }
      int m;
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (find(x)==find(y))
         {
            printf("-1\n");
            continue;
         }
         int p=f[x],q=f[y],t;
         t=merge(merge(l[p],r[p]),merge(l[q],r[q]));
         v[p]/=2,v[q]/=2;
         l[p]=r[p]=l[q]=r[q]=d[p]=d[q]=0;
         t=merge(t,merge(p,q));
         f[p]=f[q]=f[t]=t;
         printf("%d\n",v[t]);
      }
   }
   system("pause");
   return(0);
}
int find(int x)
{
   if (f[x]!=x)
      f[x]=find(f[x]);
   return(f[x]);
}
int merge(int x,int y)
{
   void swap(int &,int &);
   if (!x)
      return(y);
   if (!y)
      return(x);
   if (v[x]<v[y])
      swap(x,y);
   r[x]=merge(r[x],y);
   if (d[l[x]]<d[r[x]])
      swap(l[x],r[x]);
   d[x]=d[r[x]]+1;
   return(x);
}
void swap(int &x,int &y)
{
   int t;
   t=x,x=y,y=t;
}
