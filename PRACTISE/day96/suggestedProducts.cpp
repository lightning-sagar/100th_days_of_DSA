class Solution {
public:
    vector<string> suggest(string prefix, vector<string>& products) {
        vector<string> ans;
        for (int i = 0; i < products.size(); i++) {
            if (products[i].find(prefix) == 0) {
                ans.push_back(products[i]);
                if (ans.size() == 3) return ans;
            }
        }
        return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string prefix = "";
        for (int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            ans.push_back(suggest(prefix, products));
        }
        return ans;      
    }
};