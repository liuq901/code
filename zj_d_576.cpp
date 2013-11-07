#include <cstdio>
#include <cstdlib>
int n,suma,sumb,ansa,ansb,ans,a[10][10];
bool f[10][10];
int main()
{
   void search(int,bool);
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      suma=sumb=ansa=ansb=ans=0;
      search(1,true);
      printf("%d %d %d\n",ansa,ansb,ans);
   }
   system("pause");
   return(0);
}
void search(int pos,bool isA)
{
   bool flag=false;
   if (isA)
      for (int i=1;i<=n;i++)
      {
         if (f[pos][i])
            continue;
         flag=true;
         f[pos][i]=true;
         suma+=a[pos][i];
         search(i,false);
         f[pos][i]=false;
         suma-=a[pos][i];
      }
   else
      for (int i=1;i<=n;i++)
      {
         if (f[i][pos])
            continue;
         flag=true;
         f[i][pos]=true;
         sumb+=a[i][pos];
         search(i,true);
         f[i][pos]=false;
         sumb-=a[i][pos];
      }
   if (!flag)
      if (suma>sumb)
         ansa++;
      else if (suma<sumb)
         ansb++;
      else
         ans++;
}
