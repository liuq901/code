#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
int n,m,min,best,root,ans,tot;
int temp[30001],fa[30001],left[30001],right[30001],maxv[30001],ran[30001];
int visited[30001],father[30001],sum[30001],max[30001],sumc[30001],sumv[30001];
int start[30001],last[30001],link[60001],next[60001],cost[60001],value[60001];
int main()
{
   void insert(int,int,int,int,int),work(int);
   int i,x,y,z,w;
   scanf("%d%*d%d",&n,&m);
   for (i=1;i<=n-1;i++)  
   {
      scanf("%d%d%d%d",&x,&y,&z,&w);
      insert(i*2-1,x,y,z,w);
      insert(i*2,y,x,z,w);
   }
   srand((unsigned)time(NULL));
   work(1);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void insert(int i,int x,int y,int z,int w)
{
   link[i]=y;
   cost[i]=z;
   value[i]=w;
   if (start[x]==0)
      start[x]=i;
   else
      next[last[x]]=i;
   last[x]=i;
}
void work(int i)
{
   void build(int),add(int),find(int,int);
   int j;
   visited[i]=1;
   root=i;
   sumc[i]=sumv[i]=0;
   left[i]=right[i]=0;
   ran[i]=0;
   j=start[i];
   while (j!=0)
   {
      if (!visited[link[j]])
      {
         tot=0;
         father[link[j]]=0;
         sumc[link[j]]=cost[j];
         sumv[link[j]]=value[j];
         build(link[j]);
         while (tot>0)
         {
            add(temp[tot]);
            tot--;
         }
      }
      j=next[j];
   }
   j=start[i];
   while (j!=0)
   {
      if (!visited[link[j]])
      {
         min=20000000;
         find(link[j],0);
         work(best);
      }
      j=next[j];
   }
}
void build(int i)
{
   void get(int);
   int k;
   get(i);
   tot++;
   temp[tot]=i;
   sum[i]=1;
   max[i]=0;
   k=start[i];
   while (k!=0)
   {
      if (!visited[link[k]] && link[k]!=father[i])
      {
         father[link[k]]=i;
         sumc[link[k]]=sumc[i]+cost[k];
         sumv[link[k]]=sumv[i]+value[k];
         build(link[k]);
         sum[i]+=sum[link[k]];
         if (sum[link[k]]>max[i])
            max[i]=sum[link[k]];
      }
      k=next[k];
   }
}
void get(int x)
{
   int i;
   i=root;
   while (i!=0)
   {
      if (sumc[i]+sumc[x]<=m)
      {
         if (maxv[left[i]]+sumv[x]>ans)
            ans=maxv[left[i]]+sumv[x];
         if (sumv[i]+sumv[x]>ans)
            ans=sumv[i]+sumv[x];
         i=right[i];
      }
      else
         i=left[i];
   }
}
void add(int x)
{
   void turn(int);
   int i,j;
   i=j=root;
   while (i!=0)
   {
      j=i;
      if (sumv[x]>maxv[i])
         maxv[i]=sumv[x];
      if (sumc[x]==sumc[i])
      {
         if (sumv[x]>sumv[i])
            sumv[i]=sumv[x];
         return;
      }
      if (sumc[x]<sumc[i])
         i=left[i];
      else
         i=right[i];
   }
   fa[x]=j;
   if (sumc[x]<sumc[j])
      left[j]=x;
   else
      right[j]=x;
   left[x]=0;
   right[x]=0;
   maxv[x]=sumv[x];
   ran[x]=rand()%1000;
   while (fa[x]!=0 && ran[x]<ran[fa[x]])
      turn(x);
}
void turn(int i)
{
   void updata(int);
   int j,k;
   j=fa[i];
   k=fa[j];
   if (left[j]==i)
   {
      left[j]=right[i];
      fa[right[i]]=j;
      right[i]=j;
   }
   else
   {
      right[j]=left[i];
      fa[left[i]]=j;
      left[i]=j;
   }
   fa[j]=i;
   fa[i]=k;
   if (left[k]==j)
      left[k]=i;
   else
      right[k]=i;
   updata(j);
   updata(i);
}
void updata(int i)
{
   maxv[i]=sumv[i];
   if (maxv[left[i]]>maxv[i])
      maxv[i]=maxv[left[i]];
   if (maxv[right[i]]>maxv[i])
      maxv[i]=maxv[right[i]];
}
void find(int i,int j)
{
   int k;
   if (max[i]<min && j<min)
   {
      if (max[i]>j)
         min=max[i];
      else
         min=j;
      best=i;
   }
   k=start[i];
   while (k!=0)
   {
      if (!visited[link[k]] && link[k]!=father[i])
         find(link[k],j+sum[i]-sum[link[k]]);
      k=next[k];
   }
}
