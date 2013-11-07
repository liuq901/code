#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int no,next;
};
int n,now,last,ans,head[301],cut[301],fa[301],stack[302][301];
struct data mem[1001];
int main()
{
   void in(),work(),out();
   last=0;
   ans=200000000;
   memset(head,0,sizeof(head));
   in();
   work();
   out();
   system("pause");
   return(0);
}
void in()
{  
   void insert(int,int);
   int i,j,k,a,b;
   scanf("%d%d",&n,&k);
   for (i=1;i<=k;i++)
   {
      scanf("%d%d",&a,&b);		
      insert(a,b);
      insert(b,a);
   }
}
void insert(int a,int b)
{
   last++;
   mem[last].no=b;
   mem[last].next=head[a];
   head[a]=last;
}
void work()
{
   void findfa(int,int),search(int,int);
   int i,j,k;
   findfa(1,0);
   stack[1][0]=0;
   cut[1]=0; 
   for (i=head[1];i!=0;i=mem[i].next)
   {
      stack[1][0]++;
      stack[1][stack[1][0]]=mem[i].no;
   }
   search(1,1);
}
void findfa(int x,int f)
{     
   int i;
   fa[x]=f;   
   for (i=head[x];i;i=mem[i].next)
      if (mem[i].no!=f)
         findfa(mem[i].no,x);
}
void search(int h,int now)
{    
   int i,j,k;
   if (now>=ans)
      return;   
   k=0;
   for (i=1;i<=stack[h][0];i++)
      if (!cut[fa[stack[h][i]]])
         k++;
   if (k==0)
   {     
      ans=now;
      return;                   
   }
   now+=k-1;    
   stack[h+1][0]=0;  
   for (i=1;i<=stack[h][0];i++)
   {   
      if (cut[fa[stack[h][i]]])
         continue;    
      for (j=head[stack[h][i]];j;j=mem[j].next)
      {
         if (fa[stack[h][i]]==mem[j].no)
            continue;
         stack[h+1][++stack[h+1][0]]=mem[j].no;  
      }
   }
   for (i=1;i<=stack[h][0];i++)
   {    
      if (cut[fa[stack[h][i]]])
         continue;
      cut[stack[h][i]]=1;
      search(h+1,now);
      cut[stack[h][i]]=0;    
   }  
}
void out()
{  
   printf("%d\n",ans);
}
