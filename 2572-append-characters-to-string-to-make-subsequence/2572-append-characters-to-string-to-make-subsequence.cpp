class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int i=0,j=0;
        for(i=0,j=0;i<s.size() && j<t.size(); i++)
            if(s[i] == t[j]) ++j;
        return t.size()-j;
    }
};