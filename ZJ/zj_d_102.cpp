#include <cstdio>
#include <cstdlib>
int sum,s,n,a[101],q[101];
int main()
{
   void search(int,int);
   char ch;
   int i,j,t;
   n=sum=0;
   while (1)
   {
      while (1)
      {
         n++;
         scanf("%d%c",&a[n],&ch);
         if (ch=='\n')
            break;
      }
      if (n==1 && a[n]==0)
         break;
      for (i=1;i<=n-1;i++)
         for (j=i+1;j<=n;j++)
            if (a[i]>a[j])
               t=a[i],a[i]=a[j],a[j]=t;
      for (i=3;i<=n;i++)
         for (j=1;j<=n-i+1;j++)
         {
            q[1]=j;
            s=a[j];
            search(1,i-1);
         }
      printf("%d\n",sum);
      n=sum=0;
   }
   system("pause");
   return(0);
}
void search(int t,int x)
{
   int i;
   if (t==x)
   {
      for (i=q[t]+1;i<=n;i++)
      {
         if (s<=a[i])
            break;
         sum++;
      }
      return;
   }
   for (i=q[t]+1;i<=n;i++)
   {
      if (i+x-t>n)
         break;
      s+=a[i];
      q[t+1]=i;
      search(t+1,x);
      s-=a[i];
   }
}
