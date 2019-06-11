class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.empty()) return false;
        if (flowerbed[0] == 0) flowerbed.insert(flowerbed.begin(), 0);
        if (flowerbed.back() == 0) flowerbed.push_back(0);

        int cnt = 0;
        int sum =0;
        for (int i = 0; i <= flowerbed.size(); i++) {
            if ((i < flowerbed.size()) && (flowerbed[i] == 0)) {
                cnt++;
            } else {
                sum += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        
        return sum >= n;
    }
};
