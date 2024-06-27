class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0, right = 0;
    int maxans = 0;
    int maxCount = 0; // Count of the most frequent character in the current window
    unordered_map<char, int> mp;

    while (right < s.length()) {
        mp[s[right]]++;
        maxCount = max(maxCount, mp[s[right]]);

        // Check if the window is valid
        if (right - left + 1 - maxCount > k) {
            mp[s[left]]--;
            left++;
        }

        // Update the maximum length of the window
        maxans = max(maxans, right - left + 1);
        right++;
    }

    return maxans;
}

};