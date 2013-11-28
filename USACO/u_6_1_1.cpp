/*
ID: liuq9011
LANG: C++
TASK: vans
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int main()
{
   in=fopen("vans.in","r");
   out=fopen("vans.out","w");
   void plus(int[],int[]),work(int[],int[]);
   int n,i;
   int ans[10000],a[10000],b[10000],c[10000],d[10000];
   fscanf(in,"%d",&n);
   if (n==1)
      fprintf(out,"0\n");
   else if (n==2)
      fprintf(out,"2\n");
   else if (n==3)
      fprintf(out,"4\n");
   else if (n==4)
      fprintf(out,"12\n");
   else
   {
      a[0]=1;
      a[1]=0;
      b[0]=1;
      b[1]=2;
      c[0]=1;
      c[1]=4;
      d[0]=2;
      d[1]=2;
      d[2]=1;
      ans[0]=0;
      for (i=5;i<=n;i++)
      {
         memset(ans,0,sizeof(ans));
         plus(ans,c);
         plus(ans,c);
         plus(ans,d);
         plus(ans,d);
         plus(ans,a);
         work(ans,b);
         work(ans,b);
         memcpy(a,b,sizeof(b));
         memcpy(b,c,sizeof(c));
         memcpy(c,d,sizeof(d));
         memcpy(d,ans,sizeof(ans));
      }
      for (i=ans[0];i>=1;i--)
         fprintf(out,"%d",ans[i]);
      fprintf(out,"\n");
   }
   fclose(in),fclose(out);
   return(0);
}
void plus(int a[],int b[])
{
   int x,l,i;
   if (a[0]>b[0])
      l=a[0];
   else
      l=b[0];
   x=0;
   for (i=1;i<=l;i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   a[0]=l;
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
void work(int a[],int b[])
{
   int i;
   for (i=1;i<=b[0];i++)
   {
      a[i]-=b[i];
      if (a[i]<0)
      {
         a[i]+=10;
         a[i+1]--;
      }
   }
   while (a[a[0]]==0)
      a[0]--;
}
