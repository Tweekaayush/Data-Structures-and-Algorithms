int maxArea(vector<int>& height) {
//     int n = height.size();
//     int res = 0
//     int left[n];
//     int right[n];
//     left[0] = height[0];
//     right[n-1] = height[n-1];
//     loop(i, 1, n){
//         left[i] = max(height[i], left[i-1]);
//     }
//     looprev(i, n-2, 0){
//         right[i] = max(height[i], right[i+1]);
//     }
//     loop(i, 0, n){
//         res += min(left[i], right[i]);
//     }
//     return res;
// }