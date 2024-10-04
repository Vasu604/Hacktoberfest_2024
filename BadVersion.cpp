#include <iostream>
using namespace std;
#include<bits/stdc++.h>

bool isBadVersion(int version) {
    int badVersion = 4;  // Set the first bad version to 4 for this example
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
            {
                right = mid; // first bad version is at mid or before mid
            }
            else
            {
                left = mid + 1; // first bad version is after mid
            }
        }
        return right;   // it can be either left or right
    }
};

int main() {
    Solution solution;
    
    int n = 5;  // Total number of versions
    cout << "First Bad Version: " << solution.firstBadVersion(n) << endl;

    return 0;
}
