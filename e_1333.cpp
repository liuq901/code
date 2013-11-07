#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,f[6000],a[6000][4];
int main()
{
   int hash(int);
   void sort(int,int);
   char ch;
   int i,ans,t;
   scanf("%d%*c",&n);
   for (i=1;i<=n-1;i++)
   {
      scanf("%c%d%d%d%*c",&ch,&a[i][1],&a[i][2],&a[i][3]);
      if (ch=='N')
         a[i][0]=20;
      else if (ch=='Z')
         a[i][0]=23;
      else
         a[i][0]=26;
   }
   memset(f,-1,sizeof(f));
   f[1]=hash(1);
   sort(1,n-1);
   t=f[1];
   ans=1;
   i=1;
   while (1)
   {
      i++;
      if (i==n)
         break;
      if (f[i]!=t)
      {
         ans++;
         t=f[i];
      }
   }
   printf("%d\n",ans+1);
   system("pause");
   return(0);
}
int hash(int t)
{
   int x,y,z;
   if (t==n)
      return(0);
   if (f[t]!=-1)
      return(f[t]);
   x=hash(a[t][1]);
   y=hash(a[t][2]);
   z=hash(a[t][3]);
   f[t]=((x*129^y)*129^z^987654321)+a[t][0];
   return(f[t]);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=f[(l+r)/2];
   while (i<=j)
   {
      while (f[i]<x)
         i++;
      while (f[j]>x)
         j--;
      if (i<=j)
      {
         t=f[i],f[i]=f[j],f[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
