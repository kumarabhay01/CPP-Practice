#include <vector>
using namespace std;

int min(vector<int> list) {
    int min = list[0];
    for (vector<int>::iterator it = list.begin(); it <= list.end(); it++) {
        if (min > *it)
            min = *it;
    }
    return min;
}

int max(vector<int> list) {
    int max = list[0];
    for (vector<int>::iterator it = list.begin(); it <= list.end(); it++) {
        if (max < *it)
            max = *it;
    }
    return max;
}

int main() {

}