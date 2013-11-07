#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   char ch;
   int son,next,father,danger,suffix;
};
struct tree a[100010];
int m,q[100010];
char s[10010];
int main()
{
   void insert(char *,int,int,int),build();
   int child(int,char);
   int n,i,l,k,x,ans;
   char ch;
   scanf("%d%*c",&n);
   memset(a,0,sizeof(a));
   m=1;
   for (i=1;i<=n;i++)
   {
      gets(s);
      l=strlen(s);
      if (s[l-1]=='\n')
      {
         s[l-1]='\0';
         l--;
      }
      insert(s,l,0,1);
   }
   build();
   scanf("%d%*c",&n);
   i=x=1;
   l=0;
   ans=20000000;
   while (1)
   {
      ch=getchar();
      if (ch==0 || ch==10 || ch==13)
      {
         if (ans!=20000000)
         {
            printf("%d %d\n",i,ans);
            break;
         }
         i++;
         l=0;
         x=1;
         ans=20000000;
      }
      else
      {
         l++;
         k=child(x,ch);
         if (a[k].danger && l-a[k].danger+1<ans)
            ans=l-a[k].danger+1;
         x=k;
      }
      if (i==n+1)
      {
         printf("Passed\n");
         break;
      }
   }
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
         a[m].danger=l;
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
         a[i].danger=l;
      else if (a[i].ch==s[t])
         insert(s,l,t+1,i);
      else
      {
         m++;
         a[i].next=m;
         a[m].father=x;
         a[m].ch=s[t];
         if (t+1==l)
            a[m].danger=l;
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
   a[1].suffix=1;
   for (i=2;i<=r;i++)
   {
      if (a[q[i]].father==1)
      {
         a[q[i]].suffix=1;
         continue;
      }
      a[q[i]].suffix=child(a[a[q[i]].father].suffix,a[q[i]].ch);
      if (a[a[q[i]].suffix].danger>a[q[i]].danger)
         a[q[i]].danger=a[a[q[i]].suffix].danger;
   }
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
