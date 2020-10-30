/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {

        if (root == NULL)return {};

        stack<Node*> st;
        stack<int> res;
        st.push(root);

        while (!st.empty()) {

            auto top = st.top();
            st.pop();

            res.push(top->val);
            int sz = top->children.size();

            for (int i = 0; i < sz; i++) {
                st.push(top->children[i]);
            }
        }

        vector<int> ans;
        while (!res.empty()) {
            ans.push_back(res.top());
            res.pop();
        }

        return ans;
    }
};