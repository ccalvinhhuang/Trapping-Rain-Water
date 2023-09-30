#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
int trap(vector<int>& height) {
    int max_left[height.size()];
    int max_right[height.size()];
    int m = -1;
    for(int i = 0; i < height.size(); i++){
        m = max(m, height[i]);
        max_right[i] = m;
    }
    int t  = -1;
    for(int i = height.size() - 1; i >= 0; i--){
        t = max(t, height[i]);
        max_left[i] = t;
    }
    int l = 0, l_max = 0;
    int r = height.size() - 1, r_max  = height.size() - 1;
    int ans = 0;
    while(r >= l){
        if(l == 0){
            l_max = height[l];
            l++;
            continue;
        }
        if(r == height.size() - 1){
            r_max = height[r];
            r--;
            continue;
        }
        bool skip = false;
        if(r == l){
            skip = true;
        }
        if(l_max > height[l]){
            if(max_left[l + 1] > height[l]){
                ans += min(l_max, max_left[l + 1]) - height[l];
            }
        }
        l_max = max(l_max, height[l]);
        l++;
        if(skip){
            break;
        }
        if(r_max > height[r]){
            if(max_right[r - 1] > height[r]){
                ans += min(r_max, max_right[r - 1]) - height[r];
            }
        }
        r_max = max(r_max, height[r]);
        r--;
    }
    return ans;
}
