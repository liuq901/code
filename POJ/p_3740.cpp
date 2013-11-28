#include <cstdio>
#include <cstdlib>
struct data
{
   int l,r,u,d,x,y;
};
data a[5101];
int sum[301];
int main()
{
   bool search();
   int n,m,b[301];
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (int i=1;i<=m;i++)
      {
         a[i].l=i-1;
         a[i].r=i+1;
         a[i].x=0;
         a[i].y=i;
         b[i]=i;
      }
      a[0].r=1;
      a[0].l=m;
      a[m].r=0;
      int t=m;
      for (int i=1;i<=n;i++)
      {
         int p,q;
         p=q=0;
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            if (x==0)
               continue;
            sum[j]++;
            t++;
            a[t].x=i;
            a[t].y=j;
            a[t].u=b[j];
            a[b[j]].d=t;
            b[j]=t;
            if (p==0)
               p=t;
            else
            {
               a[q].r=t;
               a[t].l=q;
            }
            q=t;
         }
         if (p!=0)
         {
            a[p].l=q;
            a[q].r=p;
         }
      }
      for (int i=1;i<=m;i++)
      {
         a[b[i]].d=i;
         a[i].u=b[i];
      }
      if (search())
         printf("Yes, I found it\n");
      else
         printf("It is impossible\n");
   }
   system("pause");
}
bool search()
{
   void del(int),renew(int);
   if (a[0].r==0)
      return(true);
   int k,min=20000000;
   for (int i=a[0].r;i!=0;i=a[i].r)
      if (sum[i]<min)
         min=sum[k=i];
   del(k);
   for (int i=a[k].d;i!=k;i=a[i].d)
   {
      for (int j=a[i].r;j!=i;j=a[j].r)
         del(a[j].y);
      if (search())
         return(true);
      for (int j=a[i].l;j!=i;j=a[j].l)
         renew(a[j].y);
   }
   renew(k);
   return(false);
}
void del(int x)
{
   a[a[x].l].r=a[x].r;
   a[a[x].r].l=a[x].l;
   for (int i=a[x].d;i!=x;i=a[i].d)
      for (int j=a[i].r;j!=i;j=a[j].r)
      {
         sum[a[j].y]--;
         a[a[j].u].d=a[j].d;
         a[a[j].d].u=a[j].u;
      }
}
void renew(int x)
{
   a[a[x].l].r=x;
   a[a[x].r].l=x;
   for (int i=a[x].u;i!=x;i=a[i].u)
      for (int j=a[i].l;j!=i;j=a[j].l)
      {
         sum[a[j].y]++;
         a[a[j].u].d=j;
         a[a[j].d].u=j;
      }
}
