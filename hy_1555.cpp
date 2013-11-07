#include <cstdio>
#include <cstdlib>
#include <cstring>
int sumw,ans,tot,d[600001],w[600001],t[600001],s[600001];
int main()
{
   void sort(int,int),print(int),cut(),insert(int);
   int n,m,maxv,i,j,p;
   scanf("%d%d%d",&n,&m,&maxv);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&w[i],&t[i]);
      t[i]+=w[i];
   }
   memset(s,0,sizeof(s));
   for (i=1;i<=m;i++)
   {
      scanf("%d",&p);
      s[p]=1;
   }
   sort(1,n);
   n++;
   w[n]=0;
   t[n]=maxv;
   s[n]=1;
   for (i=1;i<=n;i++)
      if (s[i])
      {
         while (sumw+w[i]>t[i])
         {
            if (tot==0)
               print(-1);
            cut();
         }
         ans++;
         sumw+=w[i];
      }
      else
      {
         if (sumw+w[i]<=t[i])
            insert(w[i]);
         else if (tot!=0)
            if (sumw-d[1]+w[i]<=t[i] && w[i]<d[1])
            {
               cut();
               insert(w[i]);
            }
      }
   print(ans-1);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y;
   i=l;
   j=r;
   x=t[(l+r)/2];
   while (i<=j)
   {
      while (t[i]<x)
         i++;
      while (t[j]>x)
         j--;
      if (i<=j)
      {
         y=t[i],t[i]=t[j],t[j]=y;
         y=w[i],w[i]=w[j],w[j]=y;
         y=s[i],s[i]=s[j],s[j]=y;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void print(int ans)
{
   if (ans==-1)
      printf("Foolish SD!\n");
   else
      printf("%d\n",ans);
   system("pause");
   exit(0);
}
void cut()
{
   int p,i,j;
   ans--;
   sumw-=d[1];
   p=d[tot];
   tot--;
   if (tot==0)
      return;
   i=1;
   while (1)
   {
      j=i*2;
      if (j>tot)
         break;
      if (j<tot && d[j+1]>d[j])
         j++;
      if (p>=d[j])
         break;
      d[i]=d[j];
      i=j;
   }
   d[i]=p;
}
void insert(int p)
{
   int i;
   ans++;
   sumw+=p;
   tot++;
   i=tot;
   while (i>1 && p>d[i/2])
   {
      d[i]=d[i/2];
      i/=2;
   }
   d[i]=p;
}
