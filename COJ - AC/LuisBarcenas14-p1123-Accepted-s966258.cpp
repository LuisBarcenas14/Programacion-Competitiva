#include <iostream>
#define MAX 1510
using namespace std;
#define endl '\n'
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
// Find Minimum among three numbers
long int min(long int x, long int y, long int z) {
    if(x<=y) {
        if(x<=z) {
            return x;
        } else {
            return z;
        }
    } else {
        if(y<=z) {
            return y;
        } else {
            return z;
        }
    }
}

    long int arr[MAX], val;

// Actual Method that computes all Ugly Numbers till the required range
long int uglyNumber(int count) {
    // index of last multiple of 2 --> i2
    // index of last multiple of 3 --> i3
    // index of last multiple of 5 --> i5
    int i2, i3, i5, lastIndex;
    arr[0] = 1;
    i2 = i3 = i5 = 0;
    lastIndex = 1;
    while(lastIndex<=count-1) {
        val = min(2*arr[i2], 3*arr[i3], 5*arr[i5]);
        arr[lastIndex] = val;
        lastIndex++;
        if(val == 2*arr[i2]) {
            i2++;
        }
        if(val == 3*arr[i3]) {
            i3++;
        }
        if(val == 5*arr[i5]) {
            i5++;
        }
    }
    return arr[lastIndex-1];
}

// Starting point of program
int main() {
    ios;
    long int num;
    int count;
    num = uglyNumber(MAX);
    while(cin>>count && count){
        //num = uglyNumber(count);
        cout<<arr[count-1]<<endl;
    }
    return 0;
}
