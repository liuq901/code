#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;
queue <int> q;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      string s;
      char S[110];
      scanf("%s",S);
      s=S;
      if (s=="enqueue")
      {
         int x;
         scanf("%d",&x);
         q.push(x);
      }
      else if (q.empty())
         printf("-1\n");
      else
      {
         printf("%d\n",q.front());
         q.pop();
      }
   }
   system("pause");
   return(0);
}
