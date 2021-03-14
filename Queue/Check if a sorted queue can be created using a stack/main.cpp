#include <bits/stdc++.h>
using namespace std;

bool checkSorted(int n, queue<int>& q)
{
    int expected_value = 1;
    stack<int> sample_stack;

    while(q.size()>0) {

        int front = q.front();
        q.pop();

        if(front == expected_value) {
          expected_value++;
        }

        else {

            if(sample_stack.empty()) {
                sample_stack.push(front);
            }

            else if(!sample_stack.empty() && front > sample_stack.top()) {
                return false;
            }

            else {
                sample_stack.push(front);
            }
        }

         while(sample_stack.size()!=0 && sample_stack.top()==expected_value) {
                sample_stack.pop();
                expected_value++;
        }
    }

    if(expected_value-1 == n && sample_stack.empty()) {
            return true;
    }

    return false;

}

// Driven Program
int main()
{
    queue<int> q;
    q.push(6);
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(3);

    int n = q.size();

    if(checkSorted(n, q)) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }

    return 0;
}
