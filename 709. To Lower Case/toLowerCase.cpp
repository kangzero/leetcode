class Solution {
public:
    string toLowerCase(string str) {
        for (auto &c : str) {
            if ((c >= 'A') && (c <= 'Z')) {
                c += ('a' - 'A');
            }
        }
        return str;
    }
};
