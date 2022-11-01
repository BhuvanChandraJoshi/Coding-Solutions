//Link: https://leetcode.com/problems/longest-repeating-character-replacement/

//Implementation A
int characterReplacement(string s, int k) {
    int res = 0, maxf = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < s.length(); ++i) {
        maxf = max(maxf, ++count[s[i]]);
        if (res - maxf < k)
            res++;
        else
            count[s[i - res]]--;
    }
    return res;
}

//Implmentation B                       (both the approacges are same only implementation is different)
 int characterReplacement(string s, int k) {
    int size = s.size(); int ret = 0;
    vector<int> count(26, 0);
    int start = 0; int end = 0; int globalMaxFreq = 0; 
    for(; end<size; end++){
        count[s[end]-'A'] += 1;
        globalMaxFreq = max(globalMaxFreq, count[s[end]-'A']);
        if((end-start+1)-globalMaxFreq > k) {
            ret = max(ret, (end-start));
            count[s[start]-'A'] -= 1;
            start += 1;
        }
    }
    return max(ret, end-start);
}
