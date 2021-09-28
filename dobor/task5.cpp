#include <iostream>
#include <vector>
#include <stack>
 
void solve(std::vector<std::stack<int>> &arr, int from, int to, int val) {
    if (arr[from].top() != val) {
        int tmp = 3 - from - to;
        solve(arr, from, tmp, val - 1);
        solve(arr, from, to, val);
        solve(arr, tmp, to, val - 1);
    }
    else {
        arr[from].pop();
        arr[to].push(val);
        std::cout << val << ' ' << from + 1 << ' ' << to + 1 << std::endl;
    }
}
 
int main() {
    const int count = 8;
    std::vector<std::stack<int>> arr(3);
 
    for (int i = count; i > 0; --i) {
        arr[0].push(i);
    }
 
    solve(arr, 0, 2, count);
}