#include <cstdio>
#include <cstdlib>
int a[102],a1[102];
int b[101]={0};
int c[10001],d[10001];
int max,l,s,t,m,ans=0,low,i,j,k,temp,flag;
int main()
{
   void work1();
   void work2();
   max=105;
   scanf("%d",&l);
   scanf("%d%d%d",&s,&t,&m);
   for (i=1;i<=m;i++)
      scanf("%d",&a[i]);
   a[0]=0;
   a[m+1]=l;
   for (i=1;i<=m-1;i++)
      for (j=i+1;j<=m;j++)
         if (a[i]>a[j])
            temp=a[i],a[i]=a[j],a[j]=temp;
   if (s==t)
      work1();
   else
      work2();
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void work1()
{
   for (i=1;i<=m;i++)
      if (a[i]%s==0)
         ans++;
}
void work2()
{
   b[0]=1;
   for (i=s;i<=t;i++)
      for (j=0;j<=100;j++)
         if (b[j])
         {
            k=1;
            while (k*i+j<=100)
            {
               b[k*i+j]=1;
               k++;
            }
         }
   for (i=1;i<=100;i++)
   {
      flag=1;
      for (j=0;j<=t-1;j++)
         if (!b[i+j])
         {
            flag=0;
            break;
         }
      if (flag)
      {
         low=i;
         break;
      }
   }
   if (low<t)
      low=t;
   for (i=1;i<=m+1;i++)
      a1[i]=(a[i]-a[i-1]-low)%low+a1[i-1]+low;
   for (i=0;i<=102;i++)
      a[i]=a1[i];
   for (i=1;i<=m;i++)
      d[a[i]]=1;
   l=a[m+1];
   for (i=1;i<=l+t-1;i++)
      c[i]=max;
   for (i=1;i<=l+t-1;i++)
      for (j=s;j<=t;j++)
         if (i-j>=0 && c[i]>c[i-j]+d[i])
            c[i]=c[i-j]+d[i];
   ans=max;
   for (i=l;i<=l+t-1;i++)
      if (ans>c[i])
         ans=c[i];
}
