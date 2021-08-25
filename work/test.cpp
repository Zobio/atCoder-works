#include <iostream>
#include <vector>
using namespace std;

vector<int> buf;

void dfs(int i, const int size, const int range_start, const int range_end)
{
    if (i == size) {
        // ここで所望の作業を行う
        for(int i = 0; i < buf.size(); ++i){
            cout << buf[i] << " ";
        }
        cout << endl;
    }else{
        for(int j = range_start; j <= range_end; ++j){
            buf[i] = j;
            dfs(i + 1, size, range_start, range_end);
        }
    }
}

int main(void)
{
    int size = 10;
    int range_start = 1;
    int range_end = 5;
    
    buf.resize(size);
    dfs(0, size, range_start, range_end);

    return 0;
}