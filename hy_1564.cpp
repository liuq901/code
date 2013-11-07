#include <cstdio>
#include <cstdlib>
#include <cstring>
struct node
{
   int value,key,weight;
};
node a[100];
int cost,s[71],f[80][80][80];
int main()
{
   int min(int,int),count(int,int,int);
   int n;
   scanf("%d%d",&n,&cost);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i].value);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i].key);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i].weight);
   for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
         if (a[i].key>a[j].key)
         {
            node t;
            t=a[i],a[i]=a[j],a[j]=t;
         }
   for (int i=1;i<=n;i++)
      a[i].key=i;
   for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
         if (a[i].value>a[j].value)
         {
            node t;
            t=a[i],a[i]=a[j],a[j]=t;
         }
   for (int i=1;i<=n;i++)
      s[i]=s[i-1]+a[i].weight;
   memset(f,-1,sizeof(f));
   printf("%d\n",min(count(1,n,0),count(1,n,1)));
   system("pause");
   return(0);
}
int count(int i,int j,int k)
{
   int min(int,int),sum(int,int);
   if (f[i][j][k]!=-1)
      return(f[i][j][k]);
   if (i>j)
      f[i][j][k]=0;
   else
   {
      f[i][j][k]=1<<30;
      for (int p=i;p<=j;p++)
      {
         f[i][j][k]=min(f[i][j][k],count(i,p-1,k)+count(p+1,j,k)+sum(i,j)+cost);
         if (a[p].key>=k)
            f[i][j][k]=min(f[i][j][k],count(i,p-1,a[p].key)+count(p+1,j,a[p].key)+sum(i,j));
      }
   }
   return(f[i][j][k]);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
int sum(int l,int r)
{
   return(s[r]-s[l-1]);
}
