#include <cstdio>
#include <cstdlib>
int a[33000],b[33000],p[33000],pre[33000],next[33000];
int main()
{
   void sort(int,int);
   int min(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      b[i]=i;
   }
   sort(1,n);
   for (int i=1;i<=n;i++)
   {
      p[b[i]]=i;
      pre[i]=i-1;
      next[i]=i+1;
   }
   pre[1]=0,next[n]=0,a[0]=20000000;
   int ans=0;
   for (int i=n;i>1;i--)
   {
      int x=p[i];
      ans+=min(abs(a[x]-a[pre[x]]),abs(a[x]-a[next[x]]));
      next[pre[x]]=next[x];
      pre[next[x]]=pre[x];
   }
   ans+=a[p[1]];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
