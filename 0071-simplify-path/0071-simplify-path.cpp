class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string current;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                
                if (current == "" || current == ".") {
                }
                else if (current == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                }
                else {
                    st.push_back(current);
                }

                current = "";
            }
            else {
                current += path[i];
            }
        }

        string result = "/";

        for (int i = 0; i < st.size(); i++) {
            result += st[i];

            if (i != st.size() - 1) {
                result += "/";
            }
        }

        return result;
    }
};
