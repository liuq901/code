#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   int x,father,suffix,danger;
   int son[2];
};
int m,d[30001],q[30001],f[30001];
struct tree a[30001];
char s[30010];
int main()
{
   void insert(char *,int,int,int),build();
   int sort();
   int n,i,l;
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   a[1].x=-1;
   m=1;
   for (i=1;i<=n;i++)
   {
      scanf("%s",s);
      l=strlen(s);
      insert(s,l,0,1);
   }
   build();
   if (sort())
      printf("NIE\n");
   else
      printf("TAK\n");
   system("pause");
   return(0);
}
void insert(char *s,int l,int t,int x)
{
   int k;
   if (a[x].danger)
      return;
   k=s[t]-'0';
   if (a[x].son[k] && t+1==l)
   {
      a[a[x].son[k]].danger=1;
      return;
   }
   else if (a[x].son[k] && t+1!=l)
      insert(s,l,t+1,a[x].son[k]);
   else
   {
      m++;
      a[x].son[k]=m;
      a[m].father=x;
      a[m].x=k;
      if (t+1==l)
         a[m].danger=1;
      else
         insert(s,l,t+1,m);
   }
}
void build()
{
   int i,l,r;
   l=r=1;
   q[1]=1;
   while (l<=r)
   {
      if (!a[q[l]].danger)
      {
         if (a[q[l]].son[0])
         {
            r++;
            q[r]=a[q[l]].son[0];
         }
         if (a[q[l]].son[1])
         {
            r++;
            q[r]=a[q[l]].son[1];
         }
      }
      l++;
   }
   q[0]=r;
   a[1].suffix=1;
   if (!a[1].son[0])
      a[1].son[0]=1;
   if (!a[1].son[1])
      a[1].son[1]=1;
   for (i=2;i<=r;i++)
   {
      if (a[q[i]].father==1)
         a[q[i]].suffix=1;
      else
         a[q[i]].suffix=a[a[a[q[i]].father].suffix].son[a[q[i]].x];
      if (a[a[q[i]].suffix].danger)
         a[q[i]].danger=1;
      if (a[q[i]].son[0]==0)
         a[q[i]].son[0]=a[a[q[i]].suffix].son[0];
      if (a[q[i]].son[1]==0)
         a[q[i]].son[1]=a[a[q[i]].suffix].son[1];
   }
}
int sort()
{
   void floodfill(int);
   int i,l,r;
   memset(f,0,sizeof(f));
   memset(d,0,sizeof(d));
   floodfill(1);
   r=0;
   for (i=1;i<=m;i++)
   {
      if (!f[i])
         continue;
      if (d[i]==0)
      {
         r++;
         q[r]=i;
      }
   }
   l=1;
   while (l<=r)
   {
      d[a[q[l]].son[0]]--;
      d[a[q[l]].son[1]]--;
      if (!a[a[q[l]].son[0]].danger && d[a[q[l]].son[0]]==0)
      {
         r++;
         q[r]=a[q[l]].son[0];
      }
      if (!a[a[q[l]].son[1]].danger && d[a[q[l]].son[1]]==0)
      {
         r++;
         q[r]=a[q[l]].son[1];
      }
      f[q[l]]=0;
      l++;
   }
   for (i=1;i<=m;i++)
      if (f[i])
         return(0);
   return(1);
}
void floodfill(int x)
{
   if (a[x].danger || f[x])
      return;
   f[x]=1;
   d[a[x].son[0]]++;
   d[a[x].son[1]]++;
   floodfill(a[x].son[0]);
   floodfill(a[x].son[1]);
}
