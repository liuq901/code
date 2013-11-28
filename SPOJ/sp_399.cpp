#include <cstdio>
#include <cstdlib>
#include <cstring>
int p[121][6];
int main()
{
   void init();
   int count(int *,int *);
   init();
   while (1)
   {
      int n;
      scanf("%d%*c",&n);
      if (!n)
         break;
      int a[101][5];
      for (int i=1;i<=n;i++)
      {
         for (int j=1;j<=5;j++)
         {
            char ch;
            scanf("%c",&ch);
            a[i][ch-'A']=j;
         }
         scanf("%*c");
      }
      int ans=1<<30,k;
      for (int i=1;i<=120;i++)
      {
         int sum=0;
         for (int j=1;j<=n;j++)
            sum+=count(p[i],a[j]);
         if (sum<ans)
         {
            ans=sum;
            k=i;
         }
      }
      char s[10];
      for (int i=0;i<5;i++)
         s[p[k][i]-1]=i+'A';
      s[5]='\0';
      printf("%s is the median ranking with value %d.\n",s,ans);
   }
   system("pause");
   return(0);
}
void init()
{
   bool f[5];
   int n=0;
   for (int i=0;i<5;i++)
      for (int j=0;j<5;j++)
         for (int k=0;k<5;k++)
            for (int x=0;x<5;x++)
               for (int y=0;y<5;y++)
               {
                  memset(f,0,sizeof(f));
                  f[i]=f[j]=f[k]=f[x]=f[y]=true;
                  if (!f[0] || !f[1] || !f[2] || !f[3] || !f[4])
                     continue;
                  p[++n][i]=1,p[n][j]=2,p[n][k]=3,p[n][x]=4,p[n][y]=5;
               }
}
int count(int *a,int *b)
{
   int s=0;
   for (int i=0;i<5;i++)
      for (int j=i+1;j<5;j++)
      {
         if (i==j)
            continue;
         if ((a[i]-a[j])*(b[i]-b[j])<0)
            s++;
      }
   return(s);
}
