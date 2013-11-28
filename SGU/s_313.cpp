#include <cstdio> 
#include <cstdlib>
int x[400001],y[400001],a[400001],b[400001],z[400001],stack[400001],ans[400001];
bool visit[400001];
int n,m,top;
long long tot; 
int main()
{
   void sort(int,int),solve(int *);
   int cost(int,int),min(int,int);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=2*n;i++)
   {
      scanf("%d",&x[i]);
      y[i]=i;
      z[i]=x[i];
   }
   sort(1,2*n);
   solve(a);
   for (int i=1;i<=2*n;i++)
   {
      x[i]=x[4*n+1-i];
      y[i]=y[4*n+1-i];
   }
   solve(b);
   for (int i=n+1;i<=2*n;i++)
      a[i]=b[i];
   tot=0; 
   for (int i=1;i<=n;i++)
      if (!visit[i])
      {
         top=0; 
         int k=i;
         do
         {
            visit[k]=1;
            top++;
            stack[top]=k;
            k=a[k];
         }
         while(k!=i);
         int cost1=0,cost2=0;
         stack[0]=stack[top];
         stack[top+1]=stack[1]; 
         for (int j=1;j<=top;j++)
            if (j&1)
            {
               cost1+=cost(z[stack[j]],z[stack[j+1]]);
               cost2+=cost(z[stack[j+1]],z[stack[j+2]]);
            }
         for (int j=1;j<=top;j++)
            if (j&1)
               if (cost1<cost2)
                  ans[stack[j]]=stack[j+1]-n;
               else
                  ans[stack[j]]=stack[j-1]-n;                
         tot+=min(cost1,cost2);
      }
   printf("%I64d\n",tot);
   for (int i=1;i<=n-1;i++) 
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,t;
   i=l;
   j=r;
   x[0]=x[l+r>>1];
   y[0]=y[l+r>>1];
   while (i<=j)
   {
      while (x[i]<x[0] || x[i]==x[0] && y[i]<y[0])
         i++;
      while (x[j]>x[0] || x[j]==x[0] && y[j]>y[0])
         j--;
      if (i<=j)
      {
         t=x[i],x[i]=x[j],x[j]=t;
         t=y[i],y[i]=y[j],y[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void solve(int *a)
{
   for (int i=1;i<=2*n;i++)
   {
      x[n*2+i]=x[i];
      y[n*2+i]=y[i];
   }
   top=0;
   for (int i=1;i<=n*4;i++)
      if (!a[y[i]])
         if (y[i]<=n)
         {
            top++;
            stack[top]=y[i];
         }
         else if (top>0)
         {
            int u=stack[top],v=y[i];
            a[u]=v;
            a[v]=u;
            top--;
         }
}
int cost(int x,int y)
{
   int min(int,int);
   return(min(abs(x-y),m-abs(x-y)));
}
int min(int x,int y)
{
   return(x<y?x:y);
}
