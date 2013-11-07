#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p=40000;
struct data
{
   int x,y;
};
int n,e,tot,top,now;
int aa[40001],bb[40001],num[80001],next[80001],stack[80001];
int visited[80001],flag[80001],dfn[80001],low[80001],belong[80001];
int a[201][201],b[201][201],last[201][201];
struct data na[40001][2],nb[40001][2],c[80001][2];
int main()
{
   void init();
   int ans();
   int i,t,x;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
      init();
      x=ans();
      if (x==-1)
         printf("no\n");
      else
         printf("%d\n",x);
   }
   system("pause");
   return(0);
}
void init()
{
   int i,j;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&a[i][j]);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         scanf("%d",&b[i][j]);
}
int ans()
{
   int nosolution(),case0(),case1(),case2();
   void turn();
   if (nosolution())
      return(-1);
   if (case0())
      return(0);
   if (case1())
      return(1);
   turn();
   if (case1())
      return(1);
   if (case2())
      return(2);
   turn();
   if (case2())
      return(2);
   return(3);
}
int nosolution()
{
   int i,j;
   memset(aa,0,sizeof(aa));
   memset(bb,0,sizeof(bb));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         aa[a[i][j]]++;
         bb[b[i][j]]++;
      }
   for (i=1;i<=n*n;i++)
      if (aa[i]!=bb[i])
         return(1);
   return(0);
}
int case0()
{
   int i,j;
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (a[i][j]!=b[i][j])  
            return(0);
   return(1);
}
int case1()
{
   int i,j;
   memset(aa,0,sizeof(aa));
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=n;j++)
         aa[a[i][j]]++;
      for (j=1;j<=n;j++)
      {
         aa[b[i][j]]--;
         if (aa[b[i][j]]<0)
            return(0);
      }
   }
   return(1);
}
int case2()
{
   void make(int,int,int,int);
   int find(int);
   int i,j;
   memset(aa,0,sizeof(aa));
   memset(bb,0,sizeof(bb));
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
      {
         aa[a[i][j]]++;
         na[a[i][j]][aa[a[i][j]]-1].x=i;
         na[a[i][j]][aa[a[i][j]]-1].y=j;
         bb[b[i][j]]++;
         nb[b[i][j]][bb[b[i][j]]-1].x=i;
         nb[b[i][j]][bb[b[i][j]]-1].y=j;
      }
   memset(last,0,sizeof(last));
   e=0;
   for (i=1;i<=n*n;i++)
      if (aa[i]==1)
      {
         make(i,1,na[i][0].x,nb[i][0].y);
         make(-i,1,na[i][0].x,nb[i][0].y);
      }
      else if (aa[i]==2)
      {
         if (na[i][0].x==na[i][1].x && nb[i][0].y==nb[i][1].y)
            return(0);
         make(i,1,na[i][0].x,nb[i][0].y);
         make(i,2,na[i][1].x,nb[i][1].y);
         make(-i,1,na[i][0].x,nb[i][1].y);
         make(-i,2,na[i][1].x,nb[i][0].y);
      }
   memset(visited,0,sizeof(visited));
   memset(flag,0,sizeof(flag));
   memset(belong,0,sizeof(belong));
   tot=top=now=0;
   for (i=-n*n;i<=n*n;i++)
      if (aa[abs(i)]>0 && !visited[i+p] && !find(i))
         return(0);
   return(1);
}
void make(int i,int j,int xx,int yy)
{
   c[i+p][j-1].x=xx;
   c[i+p][j-1].y=yy;
   e++;
   num[e]=i;
   next[e]=last[xx][yy];
   last[xx][yy]=e;
}
int find(int i)
{
   int j,k;
   visited[i+p]=1;
   flag[i+p]=1;
   tot++;
   dfn[i+p]=tot;
   low[i+p]=tot;
   top++;
   stack[top]=i;
   for (j=1;j<=aa[abs(i)];j++)
   {
      k=last[c[i+p][j-1].x][c[i+p][j-1].y];
      while (k!=0)
      {
         if (num[k]!=i)
         {
            if (!visited[p-num[k]])
            {
               if (!find(-num[k]))
                  return(0);
               if (low[p-num[k]]<low[i+p])
                  low[i+p]=low[p-num[k]];
            }
            else if (flag[p-num[k]] && dfn[p-num[k]]<low[i+p])
               low[i+p]=dfn[p-num[k]];
         }
         k=next[k];
      }
   }
   if (dfn[i+p]==low[i+p])
   {
      now++;
      while (1)
      {
         belong[stack[top]+p]=now;
         if (belong[stack[top]+p]==belong[p-stack[top]])
            return(0);
         top--;
         if (stack[top+1]==i)
            break;
      }
   }
   flag[i+p]=0;
   return(1);
}
void turn()
{
   int i,j,k;
   for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
      {
         k=a[i][j],a[i][j]=a[j][i],a[j][i]=k;
         k=b[i][j],b[i][j]=b[j][i],b[j][i]=k;
      }
}
