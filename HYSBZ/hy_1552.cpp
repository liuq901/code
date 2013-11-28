#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,value[100001],pos[100001],reverse[100001];
int father[100001],left[100001],right[100001],weight[100001],sum[100001];
int main()
{
   void init(),prepare(),work();
   init();
   prepare();
   work();
   system("pause");
   return(0);
}
void init()
{
   int i;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&value[i]);
      pos[i]=i;
   }
}
void prepare()
{
   void build(int,int),sort(int,int);
   build(1,n);
   sort(1,n);
   memset(reverse,0,sizeof(reverse));
}
void build(int l,int r)
{
   int m;
   m=(l+r)/2;
   if (l<m)
   {
      build(l,m-1);
      left[m]=(l+m-1)/2;
      father[(l+m-1)/2]=m;
   }
   if (m<r)
   {
      build(m+1,r);
      right[m]=(m+r+1)/2;
      father[(m+r+1)/2]=m;
   }
   weight[m]=1;
   sum[m]=r-l+1;
}
void sort(int l,int r)
{
   int i,j,mid,t;
   i=l;
   j=r;
   mid=pos[(l+r)/2];
   while (i<=j)
   {
      while (value[pos[i]]<value[mid] || (value[pos[i]]==value[mid] && pos[i]<mid))
         i++;
      while (value[pos[j]]>value[mid] || (value[pos[j]]==value[mid] && pos[j]>mid))
         j--;
      if (i<=j)
      {
         t=pos[i],pos[i]=pos[j],pos[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void work()
{
   void splay(int);
   int i,j;
   for (i=1;i<=n;i++)
   {
      j=pos[i];
      splay(j);
      printf("%d",sum[left[j]]+i);
      if (i==n)
         printf("\n");
      else
         printf(" ");
      weight[j]--;
      sum[j]--;
      reverse[left[j]]=1-reverse[left[j]];
   }
}
void splay(int i)
{
   void updata(int),turn(int);
   int j,k;
   while (father[i]!=0)
   {
      j=father[i];
      k=father[j];
      updata(k),updata(j),updata(i);
      if (k!=0)
         if ((left[k]==j && left[j]==i) || (right[k]==j && right[j]==i))
            turn(j);
         else
            turn(i);
      turn(i);
   }
}
void updata(int i)
{
   int j;
   if (reverse[i])
   {
      reverse[i]=0;
      reverse[left[i]]=1-reverse[left[i]];
      reverse[right[i]]=1-reverse[right[i]];
      j=left[i],left[i]=right[i],right[i]=j;
   }
}
void turn(int i)
{
   int j,k;
   j=father[i];
   k=father[j];
   if (left[j]==i)
   {
      left[j]=right[i];
      father[right[i]]=j;
      right[i]=j;
   }
   else
   {
      right[j]=left[i];
      father[left[i]]=j;
      left[i]=j;
   }
   father[i]=k;
   father[j]=i;
   if (left[k]==j)
      left[k]=i;
   if (right[k]==j)
      right[k]=i;
   sum[j]=sum[left[j]]+sum[right[j]]+weight[j];
   sum[i]=sum[left[i]]+sum[right[i]]+weight[i];
}
