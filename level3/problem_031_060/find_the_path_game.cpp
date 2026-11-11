#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// void make_tree(
//     const int idx, const int x, const int y, 
//     int parentIdx, int curIdx, int dir,
//     vector<vector<int>>& nodeinfo, vector<vector<int>>& nodes
// )
// {
//     if(curIdx == -1)
//     {
//         nodes[parentIdx][dir] = idx;
//         return;
//     }
    
//     if(y < nodeinfo[curIdx][1])
//     {
//         if(x < nodeinfo[curIdx][0])
//             make_tree(idx, x, y, curIdx, nodes[curIdx][0], 0, nodeinfo, nodes);
//         else
//             make_tree(idx, x, y, curIdx, nodes[curIdx][1], 1, nodeinfo, nodes);
//     }
//     else
//     {
//         nodes[parentIdx][dir] = idx;
        
//         if(x < nodeinfo[curIdx][0]) 
//             nodes[idx][1] = curIdx;
//         else 
//             nodes[idx][0] = curIdx;
//     }
// }

// void preorder(vector<vector<int>>& nodes, vector<vector<int>>& answer, int idx)
// {
//     answer[0].push_back(idx + 1);

//     if(nodes[idx][0] != -1)
//         preorder(nodes, answer, nodes[idx][0]);
    
//     if(nodes[idx][1] != -1)
//         preorder(nodes, answer, nodes[idx][1]);
    
//     return;
// }

// void postorder(vector<vector<int>>& nodes, vector<vector<int>>& answer, int idx)
// {
//     if(nodes[idx][0] != -1)
//         postorder(nodes, answer, nodes[idx][0]);
    
//     if(nodes[idx][1] != -1)
//         postorder(nodes, answer, nodes[idx][1]);

//     answer[1].push_back(idx + 1);
    
//     return;
// }

// struct Node
// {
//     int x;
//     int y;
//     int idx;
// };

class Node
{
public:
    int x;
    int y;
    int idx;
    Node* left;
    Node* right;
    
    Node(int x, int y, int idx)
        : x(x), y(y), idx(idx), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    Node* root;
    
    void insert(Node* newNode, Node* curNode)
    {
        if(newNode->x < curNode->x)
        {
            if(curNode->left == nullptr)
                curNode->left = newNode;
            else 
                insert(newNode, curNode->left);
        }
        else
        {
            if(curNode->right == nullptr)
                curNode->right = newNode;
            else 
                insert(newNode, curNode->right);
        }
    }
    
    void preorder(vector<int>& order, Node* cur)
    {
        if(cur == nullptr) return;
        
        order.push_back(cur->idx);
        
        preorder(order, cur->left);
        preorder(order, cur->right);
    }
    
    void postorder(vector<int>& answer, Node* cur)
    {
        if(cur == nullptr) return;
        
        postorder(answer, cur->left);
        postorder(answer, cur->right);
        
        answer.push_back(cur->idx);
    }

public:
    Tree(): root(nullptr) {}

    void insert(Node* newNode)
    {
        if(root == nullptr) 
        {
            root = newNode;
            return;
        }
        insert(newNode, root);
    }
    
    vector<int> preorder()
    {
        vector<int> answer;
        preorder(answer, root);
        return answer;
    }
    
    vector<int> postorder()
    {
        vector<int> answer;
        postorder(answer, root);
        return answer;
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
//     int n = nodeinfo.size();
    
//     vector<Node> node_idx_info;
//     for(int i = 0; i < n; ++i)
//         node_idx_info.push_back({nodeinfo[i][0], nodeinfo[i][1], i});
//     sort(node_idx_info.begin(), node_idx_info.end(), [](
//         const auto& a, const auto& b)
//          {
//              if(a.y != b.y) return a.y > b.y;
//              return a.x < b.x;
//          });
    
//     int root = node_idx_info[0].idx;

//     vector<vector<int>> nodes(n, vector<int>(2, -1));
    
//     for(int i = 0; i < n; ++i)
//     {
//         int x = node_idx_info[i].x;
//         int y = node_idx_info[i].y;
//         int idx = node_idx_info[i].idx;
        
//         if(root == idx) continue;

//         make_tree(idx, x, y, -1, root, -1, nodeinfo, nodes);
//     }
    
//     vector<vector<int>> answer(2);
    
//     preorder(nodes, answer, root);
//     postorder(nodes, answer, root);
    
//     return answer;
    
    int n = nodeinfo.size();
    vector<Node> nodes;
    nodes.reserve(n);
    
    for(int i = 0; i < n; ++i)
        nodes.emplace_back(nodeinfo[i][0], nodeinfo[i][1], i + 1);

    sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b)
         {
             if(a.y != b.y) return a.y > b.y;
             return a.x < b.x;
         });
    
    Tree tree;
    for(int i = 0; i < n; ++i)
        tree.insert(&nodes[i]);
    
    vector<vector<int>> answer(2);
    answer[0] = tree.preorder();
    answer[1] = tree.postorder();
    
    return answer;
}
