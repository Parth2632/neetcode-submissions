class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if(node == NULL) {
            return NULL;
        }
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }
        else {
            Node* copy = new Node(node->val);
            mp[node] = copy;
            for(auto neighbour : node->neighbors) {
                copy->neighbors.push_back(cloneGraph(neighbour));
            }
            return copy;
        }
    }
};
