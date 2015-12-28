//uri:	https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/*
 *	将一棵树按照自己的方式拆分成一个字符串，然后再按照自己的方式构建这棵树。
 *	以下代码采用前序遍历的方式来存储、构建一棵树。当然你也可以采用中序、后序以及
 *	宽度优先遍历的方式均可。
 *	空间复杂度：O(n).
 *	时间复杂度：O(n).
 * */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        value = "";
        flg = 0;
        dfs(root);
        return value;
    }
    
    void dfs(TreeNode* root) {
        if(flg) value += " ";
        flg = 1;
        if(root == NULL) {
            value += "#";
            return;
        }
        value += to_string(root -> val);
        dfs(root -> left);
        dfs(root -> right);
    }
    
    TreeNode* create() {
        if(pos >= value.size()) return NULL;
        if(value[pos] == '#') {
            pos += 2;
            return NULL;
        }
        int i = pos;
        while(value[i] && value[i] != ' ') ++ i;
        TreeNode* root = new TreeNode(stoi(value.substr(pos, i - pos)));
        pos = i + 1;
        
        root -> left = create();
        root -> right = create();
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() < 1) return NULL;
        value = data;
        pos = 0;
        return create();
    }
    
private:
    string value;
    bool flg;
    int pos;
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
