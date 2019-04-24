class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        const string morse[] = {".-","-...","-.-.","-..",".","..-.","--.",
                                "....","..",".---","-.-",".-..","--","-.",
                                "---",".--.","--.-",".-.","...","-",
                                "..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for (auto word: words) {
            string t;
            for (auto c: word) {
                t += morse[c - 'a'];
            }
            s.insert(t);
        }
        return s.size();
    }
};
