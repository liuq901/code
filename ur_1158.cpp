#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   char ch;
   int son,next,father,danger,suffix;
};
struct tree a[2501];
int m,ans[100],q[2501],f[2][2501][100];
char b[100],s[100];
int main()
{
   void insert(char *,int,int,int),build(),work(int,int);
   int i,n,sum,p,l;
   scanf("%d%d%d",&n,&sum,&p);
   scanf("%s",&b[1]);
   m=1;
   memset(a,0,sizeof(a));
   for (i=1;i<=p;i++)
   {
      scanf("%s",s);
      l=strlen(s);
      insert(s,l,0,1);
   }
   build();
   memset(f,0,sizeof(f));
   work(n,sum);
   system("pause");
   return(0);
}
void insert(char *s,int l,int t,int x)
{
   int i;
   if (a[x].danger)
      return;
   if (a[x].son==0)
   {
      m++;
      a[x].son=m;
      a[m].father=x;
      a[m].ch=s[t];
      if (t+1==l)
         a[m].danger=1;
      else
         insert(s,l,t+1,m);
   }
   else
   {
      i=a[x].son;
      while (1)
      {
         if (a[i].next==0 || a[i].ch==s[t])
            break;
         i=a[i].next;
      }
      if (a[i].ch==s[t] && t+1==l)
         a[i].danger=1;
      else if (a[i].ch==s[t])
         insert(s,l,t+1,i);
      else
      {
         m++;
         a[i].next=m;
         a[m].father=x;
         a[m].ch=s[t];
         if (t+1==l)
            a[m].danger=1;
         else
            insert(s,l,t+1,m);
      }
   }
}
void build()
{
   int child(int,char);
   int i,l,r;
   l=r=1;
   q[1]=1;
   a[1].suffix=1;
   if (a[1].son==0)
      return;
   while (l<=r)
   {
      if (!a[q[l]].danger)
      {
         i=a[q[l]].son;
         while (1)
         {
            r++;
            q[r]=i;
            i=a[i].next;
            if (i==0)
               break;
         }
      }
      l++;
   }
   for (i=2;i<=r;i++)
   {
      if (a[q[i]].father==1)
      {
         a[q[i]].suffix=1;
         continue;
      }
      a[q[i]].suffix=child(a[a[q[i]].father].suffix,a[q[i]].ch);
      if (a[a[q[i]].suffix].danger)
         a[q[i]].danger=1;
   }
}
void work(int n,int sum)
{
   int child(int,char);
   void plus(int *,int *);
   int i,j,k,x;
   memset(f,0,sizeof(f));
   f[0][1][0]=f[0][1][1]=1;
   for (i=1;i<=sum;i++)
   {
      for (j=1;j<=m;j++)
      {
         if (a[j].danger)
            continue;
         for (k=1;k<=n;k++)
         {
            x=child(j,b[k]);
            if (a[x].danger)
               continue;
            plus(f[i&1][x],f[1-(i&1)][j]);
         }
      }
      memset(f[1-(i&1)],0,sizeof(f[1-(i&1)]));
   }
   memset(ans,0,sizeof(ans));
   ans[1]=0;
   ans[0]=1;
   for (i=1;i<=m;i++)
   {
      if (a[i].danger)
         continue;
      plus(ans,f[sum&1][i]);
   }
   for (i=ans[0];i>=1;i--)
      printf("%d",ans[i]);
   printf("\n");
}
int child(int x,char ch)
{
   int i;
   i=a[x].son;
   while (i!=0)
   {
      if (a[i].ch==ch)
         break;
      i=a[i].next;
   }
   if (i!=0)
      return(i);
   else if (x==1)
      return(1);
   else
      return(child(a[x].suffix,ch));
}
void plus(int *a,int *b)
{
   int x,i,t;
   if (a[0]>b[0])
      t=a[0];
   else
      t=b[0];
   x=0;
   for (i=1;i<=t;i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      t++;
      a[t]=x%10;
      x/=10;
   }
   a[0]=t;
}
