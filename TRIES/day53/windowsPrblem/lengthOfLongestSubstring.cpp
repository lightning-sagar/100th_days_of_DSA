int lengthOfLongestSubstring(string s) {
    // using heap
    unordered_map<char, int> mp;
    int ans = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        mp[s[right]]++;
        while (mp[s[right]] > 1) {
            mp[s[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
}