#include <cstdio>
#include <cstdlib>
int n,m,ans,now,a[10],b[10];
int main()
{
   void search(int,int);
   while (scanf("%d%d",&n,&m)==2)
   {
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=m;i++)
         scanf("%d",&b[i]);
      ans=1<<30,now=0;
      search(1,1);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void search(int dep,int first)
{
   if (now>=ans)
      return;
   if (dep==m+1)
   {
      ans=now;
      return;
   }
   for (int i=first;i<=n;i++)
   {
      if (!a[i])
         continue;
      if (a[i]<b[dep])
      {
         int t=a[i];
         a[i]=0,b[dep]-=t;
         search(dep,i+1);
         a[i]=t,b[dep]+=t;
      }
      else if (a[i]==b[dep])
      {
         int t=a[i];
         a[i]=b[dep]=0;
         search(dep+1,1);
         a[i]=b[dep]=t;
      }
      else
      {
         int t=b[dep];
         b[dep]=0,a[i]-=t;
         now++;
         search(dep+1,1);
         b[dep]=t,a[i]+=t;
         now--;
      }
   }
}
