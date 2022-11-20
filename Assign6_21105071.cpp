#include <iostream>                 //MUKUL GOYAL
#include <queue>                     //SID:21105071 
                                      // ECE
using namespace std;

//Creating structure of Node of a tree
class Node{
    public:
        int data;
        Node*left;
        Node*right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }   
};

Node * insert_in_BST(Node*root,int data){

    if(root==NULL){
        Node*new_node=new Node(data);
        root=new_node;
        return root;
    }

    if(data>root->data){root->right=insert_in_BST(root->right,data);}

    else if(data<root->data){root->left=insert_in_BST(root->left,data);}

    else{return root;}

    return root;
}

// Level order print
void level_order_traversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){q.push(NULL);
                          };
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);
                          }
            if(temp->right){q.push(temp->right);
                           }
        }
    }
}

// get min value node in a Binary Search Tree
Node* min_value_node(Node* node)
{
    Node* temp = node;

    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}

// delete a node 
Node* delete_node(Node* root, int key)
{
    if (root == NULL)
        return root;
  
    if (key < root->data)
        root->left = delete_node(root->left, key);
  
    else if (key > root->data)
        root->right = delete_node(root->right, key);

    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        
        else if (root->left == NULL) {
             Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
             Node* temp = root->left;
            free(root);
            return temp;
        }
 
        Node* temp = min_value_node(root->right);
        root->data= temp->data;
        root->right = delete_node(root->right, temp->data);

    }
    return root;
}

//Function to print an array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
}

int main()
{
    //Taking number of element in array as input
    int n;
    cout<<"\nEnter number elements in the array to form BST:";
    cin>>n;
    int arr[n];
    cout<<"\nEnter elements of the array to form BST:";
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<"\nArray:[";pfun(arr,n);cout<<"]";
    cout<<endl;
  
    //Creating node
    Node*root=NULL;
    //Inserting element in Binary Search Tree
    for(int i=0;i<n;i++){
        root=insert_in_BST(root,arr[i]);
    }
  //Level order display
  cout<<"\nBinary Search Tree using Level Order Traversal\n"<<endl;
    level_order_traversal(root);

    //key is the data to be deleted from Binary Search Tree
    int key;
    cout<<"\nEnter data to be deleted from BST:";cin>>key;
    //deleting key from Binary Search Tree
    root=delete_node(root,key);
    //Displaying Binary Search Tree after deletion of key
    cout<<"\nBinary Search Tree after deleting:"<<key<<endl;
    cout<<endl;
    level_order_traversal(root);
}

/*
If an array has n elements and all elements are inserted in binary
search tree than the tree has space complexity of O(n) and the array
has also the space complexity of O(n)
*/
