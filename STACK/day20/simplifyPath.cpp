class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while (i < path.length()) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            int j = i;
            while (j < path.length() && path[j] != '/') {
                j++;
            }
            string dir = path.substr(i, j - i);
            if (dir == ".") {
                // Ignore current directory
            } else if (dir == "..") {
                // Move up one directory if possible
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                // Push directory name onto stack
                st.push(dir);
            }
            i = j + 1;
        }
        
        // Construct simplified path from stack
        string simplifiedPath;
        while (!st.empty()) {
            simplifiedPath = "/" + st.top() + simplifiedPath;
            st.pop();
        }
        
        // Handle case when path is empty
        if (simplifiedPath.empty()) {
            simplifiedPath = "/";
        }
        
        return simplifiedPath;
    }
};
