#include <cstdio>
#include <cstdlib>
struct data
{
   int l,r,u,d,x,y;
};
struct data p[1001001];
int sum[1001],ans[1001];
int main()
{
   int count(int,int,int),search();
   int i,j,k,n,m,tmp;
   int t[1001],b[101];
   while (scanf("%d%d",&n,&m)!=EOF)
   {
      for (i=1;i<=m;i++)
      {
         p[i].l=i-1;
         p[i].r=i+1;
         sum[i]=0;
         p[i].x=0;
         p[i].y=i;
         t[i]=i;
      }
      p[0].r=1;
      p[0].l=m;
      p[m].r=0;
      for (i=1;i<=n;i++)
      {
         scanf("%d",&k);
         for (j=1;j<=k;j++)
         {
            scanf("%d",&b[j]);
            sum[b[j]]++;
            tmp=count(m,i,b[j]);
            p[tmp].x=i;
            p[tmp].y=b[j];
            if (j!=1)
            {
               p[tmp].l=count(m,i,b[j-1]);
               p[count(m,i,b[j-1])].r=tmp;
            }
            p[tmp].u=t[b[j]];
            p[t[b[j]]].d=tmp;
            t[b[j]]=tmp;
         }
         p[count(m,i,b[1])].l=count(m,i,b[k]);
         p[count(m,i,b[k])].r=count(m,i,b[1]);
      }
      for (i=1;i<=m;i++)
      {
         p[i].u=t[i];
         p[t[i]].d=i;
      }
      ans[0]=0;
      if (!search())
         printf("NO\n");
   }
   system("pause");
   return(0);
}
int count(int t,int x,int y)
{
   return(x*t+y);
}
int search()
{
   void del(int),renew(int);
   int i,j,t,min;
   if (p[0].r==0)
   {
      printf("%d",ans[0]);
      for (i=1;i<=ans[0];i++)
         printf(" %d",ans[i]);
      printf("\n");
      return(1);
   }
   min=20000000;
   i=p[0].r;
   while (i!=0)
   {
      if (sum[p[i].y]<min)
      {
         min=sum[p[i].y];
         t=i;
      }
      i=p[i].r;
   }
   del(t);
   i=p[t].d;
   while (i!=t)
   {
      ans[0]++;
      ans[ans[0]]=p[i].x;
      j=p[i].r;
      while (j!=i)
      {
         del(p[j].y);
         j=p[j].r;
      }
      if (search())
         return(1);
      ans[0]--;
      j=p[i].l;
      while (j!=i)
      {
         renew(p[j].y);
         j=p[j].l;
      }
      i=p[i].d;
   }
   renew(t);
   return(0);
}
void del(int t)
{
   int i,j;
   p[p[t].r].l=p[t].l;
   p[p[t].l].r=p[t].r;
   i=p[t].d;
   while (i!=t)
   {
      j=p[i].r;
      while (j!=i)
      {
         sum[p[j].y]--;
         p[p[j].u].d=p[j].d;
         p[p[j].d].u=p[j].u;
         j=p[j].r;
      }
      i=p[i].d;
   }
}
void renew(int t)
{
   int i,j;
   i=p[t].u;
   while (i!=t)
   {
      j=p[i].l;
      while (j!=i)
      {
         sum[p[j].y]++;
         p[p[j].u].d=j;
         p[p[j].d].u=j;
         j=p[j].l;
      }
      i=p[i].u;
   }
   p[p[t].r].l=t;
   p[p[t].l].r=t;
}
