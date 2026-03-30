/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        q.push(node);
        mp[node] = new Node(node->val);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* nd : cur->neighbors) {
                if (!mp.count(nd)) {
                    mp[nd] = new Node(nd->val);
                    q.push(nd);
                }

                mp[cur]->neighbors.push_back(mp[nd]);
            }
        }

        return mp[node];
    }
};