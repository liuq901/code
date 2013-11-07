#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   char ch;
   int son,next,father,danger,suffix;
};
struct tree a[1000010];
int c,d,m,q[1000010],l[1010],ans[1010][3];
char s[1010][201],b[1010][1010];
int main()
{
   void insert(char *,int,int,int,int),build(),count(int);
   int i,j,n;
   scanf("%d%d%d%*c",&c,&d,&n);
   for (i=1;i<=c;i++)
   {
      for (j=1;j<=d;j++)
         scanf("%c",&b[i][j]);
      scanf("%*c");
   }
   memset(a,0,sizeof(a));
   m=1;
   for (i=1;i<=n;i++)
   {
      scanf("%s",s[i]);
      l[i]=strlen(s[i]);
      insert(s[i],l[i],0,1,i);
   }
   if (n)
   {
      build();
      for (i=0;i<8;i++)
         count(i);
   }
   for (i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
         if (strstr(s[i],s[j]) && s[i][l[i]-1]==s[j][l[j]-1])
         {
            ans[j][2]=ans[i][2];
            ans[j][0]=ans[i][0]+l[i]-l[j];
            ans[j][1]=ans[i][1]+l[i]-l[j];
         }
   for (i=1;i<=n;i++)
      printf("%d %d %c\n",ans[i][0],ans[i][1],ans[i][2]);
   system("pause");
   return(0);
}
void insert(char *s,int l,int t,int x,int order)
{
   int i;
   if (a[x].son==0)
   {
      m++;
      a[x].son=m;
      a[m].father=x;
      a[m].ch=s[t];
      if (t+1==l)
         a[m].danger=order;
      else
         insert(s,l,t+1,m,order);
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
         a[i].danger=order;
      else if (a[i].ch==s[t])
         insert(s,l,t+1,i,order);
      else
      {
         m++;
         a[i].next=m;
         a[m].father=x;
         a[m].ch=s[t];
         if (t+1==l)
            a[m].danger=order;
         else
            insert(s,l,t+1,m,order);
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
      if (a[a[q[i]].suffix].danger)
         a[q[i]].danger=a[a[q[i]].suffix].danger;
   }
}
void count(int x)
{
   int child(int,char);
   int i,j,k,t;
   if (x==4)
   {
      for (i=1;i<=d;i++)
      {
         t=1;
         for (j=c;j>=1;j--)
         {
            k=child(t,b[j][i]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=j+l[a[k].danger]-1;
               ans[a[k].danger][1]=i;
               ans[a[k].danger][2]='A';
            }
            t=k;
         }
      }
      return;
   }
   if (x==5)
   {
      for (i=2;i<=c+d;i++)
      {
         t=1;
         for (j=1;j<=d;j++)
         {
            if (i-j<=0 || i-j>c)
               continue;
            k=child(t,b[i-j][j]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=i-j+l[a[k].danger]-1;
               ans[a[k].danger][1]=j-l[a[k].danger]+1;
               ans[a[k].danger][2]='B';
            }
            t=k;
         }
      }
      return;
   }
   if (x==6)
   {
      for (i=1;i<=c;i++)
      {
         t=1;
         for (j=1;j<=d;j++)
         {
            k=child(t,b[i][j]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=i;
               ans[a[k].danger][1]=j-l[a[k].danger]+1;
               ans[a[k].danger][2]='C';
            }
            t=k;
         }
      }
      return;
   }
   if (x==7)
   {
      for (i=1-c;i<=d-1;i++)
      {
         t=1;
         for (j=1;j<=d;j++)
         {
            if (i+j>c || i+j<=0)
               continue;
            k=child(t,b[i+j][j]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=i+j-l[a[k].danger]+1;
               ans[a[k].danger][1]=j-l[a[k].danger]+1;
               ans[a[k].danger][2]='D';
            }
            t=k;
         }
      }
      return;
   }
   if (x==0)
   {
      for (i=1;i<=d;i++)
      {
         t=1;
         for (j=1;j<=c;j++)
         {
            k=child(t,b[j][i]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=j-l[a[k].danger]+1;
               ans[a[k].danger][1]=i;
               ans[a[k].danger][2]='E';
            }
            t=k;
         }
      }
      return;
   }
   if (x==1)
   {
      for (i=2;i<=c+d;i++)
      {
         t=1;
         for (j=d;j>=1;j--)
         {
            if (i-j<=0 || i-j>c)
               continue;
            k=child(t,b[i-j][j]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=i-j-l[a[k].danger]+1;
               ans[a[k].danger][1]=j+l[a[k].danger]-1;
               ans[a[k].danger][2]='F';
            }
            t=k;
         }
      }
      return;
   }
   if (x==2)
   {
      for (i=1;i<=c;i++)
      {
         t=1;
         for (j=d;j>=1;j--)
         {
            k=child(t,b[i][j]);
            if (a[k].danger)
            {
               ans[a[k].danger][0]=i;
               ans[a[k].danger][1]=j+l[a[k].danger]-1;
               ans[a[k].danger][2]='G';
            }
            t=k;
         }
      }
      return;
   }
   for (i=1-c;i<=d-1;i++)
   {
      t=1;
      for (j=d;j>=1;j--)
      {
         if (i+j<=0 || i+j>c)
            continue;
         k=child(t,b[i+j][j]);
         if (a[k].danger)
         {
            ans[a[k].danger][0]=i+j+l[a[k].danger]-1;
            ans[a[k].danger][1]=j+l[a[k].danger]-1;
            ans[a[k].danger][2]='H';
         }
         t=k;
      }
   }
}
int child(int x,char ch)
{
   int i;
   while (1)
   {
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
      x=a[x].suffix;
   }
}
