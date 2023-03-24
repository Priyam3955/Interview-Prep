//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/ /*  Brute Force => Similar to Two Sum Prblm  (Time -> O(n+m) => traverse in both bsts & Space -> O(m) => map)
    1. using unordered_map -> Store the values of BST2 in mp
    2. Inorder Traversal in BST1. For every value in BST1 Calculate (root->data-x)
    3. Search this value in map. if founds then c++ At last return c.
    
    Optimized Approach => 
    1. For each node in inorder traversal in BST1 check a[i]-x in BST2 
    2. If founds then c++;     TC -> O(n*h) => n = no. of nodes , SC -> O(1)
                               h = log(m) => Searching will take logm time for each node, it goes till height
                               
*/

class Solution
{
public:
    int c;
    bool fetch(Node* root2, int k){
        if(!root2) return false;
        if(k == root2->data) return true;
        bool x,y;
        x=false;
        y=false;
        if(k<root2->data) x = fetch(root2->left, k);
        else if(k>root2->data) y = fetch(root2->right, k);
        else return x or y ;    // Either true or false if anyone gots there.
    }
    void solve(Node* root1, Node* root2, int k){
        if(!root1) return ;
        solve(root1->left, root2, k);           // Left Subtree
        if(fetch(root2, k-root1->data)) c++;    // Searching in BST2
        solve(root1->right, root2, k);          // Right Subtree
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        c=0;
        solve(root1, root2, x);
        return c;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string tree1, tree2;
        getline(cin, tree1);
        getline(cin, tree2);
        Node* root1 = buildTree(tree1);
        Node* root2 = buildTree(tree2);
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        cout << ob.countPairs(root1, root2, x) << "\n";
    }
    return 0;
}

// } Driver Code Ends