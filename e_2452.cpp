#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
string name[510];
map <string,int> hash;
int m,power[510],a[30][30],pos[510][2];
int main()
{
   void find(int,int,int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d%d",&n,&m);
      hash.clear();
      for (int i=1;i<=n;i++)
      {
         cin>>name[i];
         hash[name[i]]=i;
      }
      for (int i=1;i<=n;i++)
         scanf("%d",&power[i]);
      memset(a,0,sizeof(a));
      memset(pos,-1,sizeof(pos));
      while (1)
      {
         string op;
         cin>>op;
         if (op=="OVER")
            break;
         if (op=="Dispatch")
         {
            string s;
            cin>>s;
            int num=hash[s];
            cin>>s;
            int x,y;
            scanf("%d%d",&x,&y);
            if (pos[num][0]!=-1)
               a[pos[num][0]][pos[num][1]]=0,pos[num][0]=pos[num][1]=-1;
            if (!a[x][y])
               a[x][y]=num,pos[num][0]=x,pos[num][1]=y;
            else
            {
               int p=a[x][y];
               if (power[num]>power[p])
               {
                  a[x][y]=num,pos[num][0]=x,pos[num][1]=y;
                  pos[p][0]=pos[p][1]=-1;
                  find(p,x,y);
               }
               else
                  find(num,x,y);
            }
            printf("%s\n",pos[num][0]==-1?"Fail!":"Success!");
         }
         else if (op=="Who")
         {
            int x,y;
            scanf("%d%d",&x,&y);
            if (a[x][y])
               printf("The place is occupied by %s!\n",name[a[x][y]].c_str());
            else
               printf("There is empty!\n");
         }
         else
         {
            string name;
            cin>>name;
            int s=hash[name];
            if (pos[s][0]==-1)
               printf("%s is free!\n",name.c_str());
            else
               printf("%s is in the place(%d,%d)!\n",name.c_str(),pos[s][0],pos[s][1]);
         }
      }
   }
   system("pause");
   return(0);
}
void find(int id,int x0,int y0)
{
   int len=1<<30;
   for (int i=0;i<m;i++)
      for (int j=0;j<m;j++)
      {
         if (a[i][j])
            continue;
         len=min(len,max(abs(i-x0),abs(j-y0)));
      }
   if (len==1<<30)
   {
      power[id]++;
      return;
   }
   int x=x0-len,y=y0-len;
   for (int i=0;i<4;i++)
      for (int j=1;j<=len<<1;j++)
      {
         if (x>=0 && x<m && y>=0 && y<m && !a[x][y])
         {
            a[x][y]=id,pos[id][0]=x,pos[id][1]=y;
            return;
         }
         x+=c[i][0],y+=c[i][1];
      }
}
