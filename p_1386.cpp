#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[30],a[30][30];
int main()
{
   void work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   void floodfill(int);
   int check();
   int i,n,l,flag;
   char s[1026];
   scanf("%d",&n);
   memset(a,0,sizeof(a));
   memset(f,0,sizeof(f));
   for (i=1;i<=n;i++)
   {
      scanf("%s",s);
      l=strlen(s);
      f[s[0]-'a']=1;
      f[s[l-1]-'a']=1;
      a[s[0]-'a'][s[l-1]-'a']++;
   }
   for (i=0;i<26;i++)
   {
      if (!f[i])
         continue;
      f[i]=0;
      floodfill(i);
      break;
   }
   flag=1;
   for (i=0;i<26;i++)
      if (f[i])
      {
         flag=0;
         break;
      }
   if (!flag)
   {
      printf("The door cannot be opened.\n");
      return;
   }
   if (check())
      printf("Ordering is possible.\n");
   else
      printf("The door cannot be opened.\n");
}
void floodfill(int x)
{
   int i;
   for (i=0;i<26;i++)
      if (f[i] && (a[x][i] || a[i][x]))
      {
         f[i]=0;
         floodfill(i);
      }
}
int check()
{
   int i,j,s,t;
   int b[30],c[30];
   memset(b,0,sizeof(b));
   memset(c,0,sizeof(c));
   for (i=0;i<26;i++)
      for (j=0;j<26;j++)
      {
         b[i]+=a[i][j];
         c[j]+=a[i][j];
      }
   s=t=0;
   for (i=0;i<26;i++)
   {
      if (b[i]-c[i]>1 || c[i]-b[i]>1)
         return(0);
      if (b[i]-c[i]==1)
         s++;
      if (c[i]-b[i]==1)
         t++;
   }
   if (s==0 && t==0 || s==1 && t==1)
      return(1);
   else
      return(0);
}
