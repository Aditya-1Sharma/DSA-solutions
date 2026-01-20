bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> s1;
        unordered_map<char, int> t1;

        for(int i = 0; i<s.size(); i++){
            s1[s[i]]++;
            t1[t[i]]++;
        }

        for(auto const& [key,value] : s1) {
            if(value != t1[key]) return false;
        }
        return true;
    }