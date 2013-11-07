#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
struct card
{
   int point,kind;
   card(int n,char ch):point(n)
   {
      if (ch=='C')
         kind=1;
      if (ch=='D')
         kind=2;
      if (ch=='H')
         kind=3;
      if (ch=='S')
         kind=4;
   }
};
typedef vector <card>::iterator iter;
bool operator <(card a,card b)
{
   if (a.point!=b.point)
      return(a.point<b.point);
   return(a.kind<b.kind);
}
bool operator ==(card a,card b)
{
   return(a.point==b.point || a.kind==b.kind);
}
vector <card> all,a[20];
card discard(0,'S');
int opt;
bool clockwise;
int main()
{
   void display(card);
   bool out(int);
   while (1)
   {
      int P,m,n;
      scanf("%d%d%d",&P,&m,&n);
      if (!P && !m && !n)
         break;
      all.clear();
      for (int i=1;i<=n;i++)
      {
         int x;
         char ch;
         scanf("%d %c",&x,&ch);
         all.push_back(card(x,ch));
      }
      int top=0;
      for (int i=1;i<=P;i++)
      {
         a[i].clear();
         for (int j=1;j<=m;j++)
            a[i].push_back(all[top++]);
      }
      clockwise=true;
      opt=0;
      int now=1,winner=0;
      display(all[top++]);
      while (!winner)
      {
         if (!opt)
         {
            if (!out(now))
            {
               a[now].push_back(all[top++]);
               out(now);
            }
            if (a[now].empty())
               winner=now;
         }
         else if (opt==1)
         {
            a[now].push_back(all[top++]);
            a[now].push_back(all[top++]);
            opt=0;
         }
         else if (opt==2)
         {
            a[now].push_back(all[top++]);
            opt=0;
         }
         else
            opt=0;
         if (clockwise)
            now++;
         else
            now--;
         if (now>P)
            now=1;
         if (!now)
            now=P;
      }
      printf("%d\n",winner);
   }
   system("pause");
   return(0);
}
bool out(int x)
{
   void display(card);
   iter t=a[x].end();
   for (iter k=a[x].begin();k!=a[x].end();k++)
      if (*k==discard && (t==a[x].end() || *t<*k))
         t=k;
   if (t==a[x].end())
      return(false);
   display(*t);
   a[x].erase(t);
   return(true);
}
void display(card x)
{
   discard=x;
   if (x.point==12)
      clockwise=!clockwise;
   if (x.point==7)
      opt=1;
   if (x.point==1)
      opt=2;
   if (x.point==11)
      opt=3;
}
