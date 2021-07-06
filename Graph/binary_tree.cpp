 /* 
This code implements following things
(1) Inorder, postorder, perorder and levelorder traversal 
(2) Hight of the tree 
(3) Number of internal nodes and leaf nodes 
*/
 


#include <iostream> 
#include <queue>
#include <vector>
using namespace std;


struct Node{
  
  int val;
  struct Node* left;
  struct Node* right;
  
  Node(): val(0), left(nullptr), right(nullptr) {}
  Node(int x): val(x), left(nullptr), right(nullptr) {}
  Node(int x, struct Node* left, struct Node* right): val(x), left(left), right(right) {}
  
};


int numberOfInternalNodes(struct Node* root){
    if((root!=nullptr)&&(root->left!=nullptr || root->right!=nullptr)){
        return 1+numberOfInternalNodes(root->left)+numberOfInternalNodes(root->right);
    }else
        return 0;
}

int numberOfExternalNodes(struct Node* root){
    if(root == nullptr)
        return 0;
    else if((root!=nullptr) && (root->left == nullptr && root->right == nullptr)){
        return 1;
    }else
        return numberOfExternalNodes(root->left)+numberOfExternalNodes(root->right);
}

vector<vector<int>> levelOrder2(struct Node* root) {
        
        
        queue<struct Node*> q;
        vector<vector<int>> v;
        struct Node* curr;
        
        if(root!=nullptr){
            q.push(root);
            
            while(!q.empty()){    
                v.push_back({});
                int size = q.size();

                while(size--){
                    curr = q.front();
                    q.pop();
                    v.back().push_back(curr->val); 
                    cout << curr-> val << " ";
                    
                    if(curr->left != nullptr)
                        q.push(curr->left);
                    if(curr->right != nullptr)
                        q.push(curr->right);    
                }
                cout << endl;
            }  
        }
        
        return v;   
    }

vector<vector<int>> levelOrder1(struct Node* root) {
        
        queue<struct Node*> q;
        vector<vector<int>> v;
        vector<int> tmp;
        
        struct Node* curr;
        
        if(root!=nullptr){
            q.push(root);
            q.push(nullptr);
        
            while(!q.empty()){
                curr = q.front();
                q.pop();
                if(curr == nullptr){
                    v.push_back(tmp);
                    tmp.clear();
                    cout << endl;
                    if(q.empty()==false)
                        q.push(nullptr);    
                }
                else{
                    tmp.push_back(curr->val);
                    cout << curr->val << " ";
                    if(curr->left != nullptr){
                        q.push(curr->left);

                    }
                    if(curr->right != nullptr){
                        q.push(curr->right);
                    }    
                }
            }
        }    
        return v;
    }


// hight start with 1
int height(struct Node* root){
    
    if(root == nullptr){
        return 0;
    }
    else{
        return 1+max(height(root->left),(height(root->right)));
    }
    
    
    
}

void preorder(struct Node* root){
    if(root!=nullptr){
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}


int main() {
    
    struct Node* root = new Node(2);
    
    struct Node* n1 = new Node(3);
    struct Node* n2 = new Node(4);
    struct Node* n3 = new Node(5);
    struct Node* n4 = new Node(6);
    struct Node* n5 = new Node(7);
    struct Node* n6 = new Node(8);
    
    
    root->left = n1;
    root->right = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;
    
    
    cout << "Pre order : "; preorder(root); cout << endl;
    cout << "Post order : "; preorder(root); cout << endl;
    cout << "In order : "; preorder(root); cout << endl;
    cout << "Level rrder : \n"; levelOrder2(root);
    cout << "Height : " << height(root) << endl;
    cout << "#Internal Nodes : " <<  numberOfInternalNodes(root) << endl; 
    cout << "#External Nodes : " << numberOfExternalNodes(root) << endl; 
		
	return 0;
}
