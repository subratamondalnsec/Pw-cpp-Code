#include <iostream>
#include <vector>
using namespace std;
    int peakIndexInMountainArray(vector<int>& arr) {
 int n=arr.size();
        int lo=1;
        int hi=n-2;
        while(lo<=hi){
           int mid=lo+(hi-lo)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid+1])hi=mid -1;
            else lo =mid+1;
        }
        return -1;
};

int main() {
    vector<int> testArray = {0, 2, 3, 4, 5, 3, 1}; // Example of a mountain array
    int result = peakIndexInMountainArray(testArray);
    cout << "The peak index in the mountain array index is " << result << endl;
    return 0;
}
