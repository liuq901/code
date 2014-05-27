#include <cstdio>
#include <deque>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        static int id=0;
        printf("Case %d:\n",++id);
        deque <int> a;
        while (Q--)
        {
            char op[10];
            scanf("%s",op);
            if (op[1]=='u')
            {
                int x;
                scanf("%d",&x);
                if (a.size()==n)
                    printf("The queue is full\n");
                else if (op[4]=='L')
                {
                    a.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
                else
                {
                    a.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }
            }
            else if (a.empty())
                printf("The queue is empty\n");
            else if (op[3]=='L')
            {
                printf("Popped from left: %d\n",a.front());
                a.pop_front();
            }
            else
            {
                printf("Popped from right: %d\n",a.back());
                a.pop_back();
            }
        }
    }
    return(0);
}

