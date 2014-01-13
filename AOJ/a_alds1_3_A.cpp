#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <stack>
using namespace std;
int main()
{
    char buf[10];
    stack <int> s;
    while (scanf("%s",buf)==1)
    {
        if (isdigit(buf[0]))
            s.push(atoi(buf));
        else
        {
            int x=s.top();
            s.pop();
            switch (buf[0])
            {
            case '+':
                s.top()+=x;
                break;
            case '-':
                s.top()-=x;
                break;
            case '*':
                s.top()*=x;
                break;
            }
        }
    }
    printf("%d\n",s.top());
    return(0);
}

