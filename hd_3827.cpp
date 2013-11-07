#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef vector <char>::iterator iter;
typedef vector <char> &Vector;
char a[110];
vector <char> p,q;
int main()
{
   void snitch(Vector,Vector);
   bool kill(Vector,Vector);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=0;i<n;i++)
         cin>>a[i];
      p.clear(),q.clear();
      for (int i=0;i<4;i++)
         p.push_back(a[i]);
      for (int i=4;i<8;i++)
         q.push_back(a[i]);
      int now=8,x,y;
      x=y=3;
      for (int lq=1;lq<=120;lq++)
      {
         for (int i=1;i<=2;i++)
            if (now<n)
               p.push_back(a[now++]);
         while (1)
         {
            bool flag=true;
            for (int i=0;i<p.size();i++)
               if (p[i]=='S' && !q.empty())
               {
                  snitch(p,q);
                  flag=false;
                  break;
               }
            if (flag)
               break;
         }
         for (int i=0;i<p.size();i++)
            if (p[i]=='K')
            {
               if (kill(p,q))
                  y--;
               break;
            }
         if (!y)
            break;
         for (int i=1;i<=2;i++)
            if (now<n)
               q.push_back(a[now++]);
         while (1)
         {
            bool flag=true;
            for (int i=0;i<q.size();i++)
               if (q[i]=='S' && !p.empty())
               {
                  snitch(q,p);
                  flag=false;
                  break;
               }
            if (flag)
               break;
         }
         for (int i=0;i<q.size();i++)
            if (q[i]=='K')
            {
               if (kill(q,p))
                  x--;
               break;
            }
         if (!x)
            break;
      }
      static int id=0;
      printf("Case %d: ",++id);
      if (!x)
         printf("The winner is the second.\n");
      else if (!y)
         printf("The winner is the first.\n");
      else
         printf("Just a tie.\n");
   }
   system("pause");
   return(0);
}
void snitch(Vector a,Vector b)
{
   for (iter k=a.begin();k!=a.end();k++)
      if (*k=='S')
      {
         a.erase(k);
         break;
      }
   for (iter k=b.begin();k!=b.end();k++)
      if (*k=='D')
      {
         b.erase(k);
         return;
      }
   a.push_back(b[0]);
   b.erase(b.begin());
}
bool kill(Vector a,Vector b)
{
   for (iter k=a.begin();k!=a.end();k++)
      if (*k=='K')
      {
         a.erase(k);
         break;
      }
   for (iter k=b.begin();k!=b.end();k++)
      if (*k=='E')
      {
         b.erase(k);
         return(false);
      }
   return(true);
}
