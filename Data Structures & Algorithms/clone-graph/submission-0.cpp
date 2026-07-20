class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* cloneNode) {

        for (Node* n : node->neighbors) {

            if (mp.find(n) == mp.end()) {

                Node* clone = new Node(n->val);
                mp[n] = clone;

                cloneNode->neighbors.push_back(clone);

                DFS(n, clone);
            }
            else {
                cloneNode->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {

        if (node == NULL)
            return NULL;

        Node* clone = new Node(node->val);
        mp[node] = clone;

        DFS(node, clone);

        return clone;
    }
};