#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;


void delete_data(Node * root, Node * pre, char dir,int d){
    if (root==NULL){
        return ;
    }

    if (root->data==d){
        if (pre==NULL){
            return;
        }
        else if (root->left==NULL && root->right==NULL){
            if(dir=='l'){
                pre->left=NULL;
                
            } else {
                pre->right=NULL;
                
            }
        } else if (root->left==NULL){
            if(dir=='l'){
                pre->left=root->right;
                
            } else {
                pre->right=root->right;
                
            }
        } else if (root->right==NULL){
            if(dir=='l'){
                pre->left=root->left;
                ;
            } else {
                pre->right=root->left;
                
            }
        } else {
            Node* succParent = root;
            Node* succ = root->right;

            while (succ->left != NULL){
                succParent = succ;
                succ = succ->left;
            }

            
            root->data = succ->data;

            
            if (succParent->left == succ)
                delete_data(succ, succParent, 'l', succ->data);
            else
                delete_data(succ, succParent, 'r', succ->data);
            
        }
    } else if(root->data>d){
        delete_data(root->left,root,'l',d);
        return ;
    } else if (root->data<d){
        delete_data(root->right,root,'r',d);
        return ;
    }

    return;


}

int main(void){
    Node N7={70,NULL,NULL};
    Node N6={50,NULL,NULL};
    Node N5={30,NULL,NULL};
    Node N4={10,NULL,NULL};
    Node N3={60,&N6,&N7};
    Node N2={20,&N4,&N5};
    Node N1={40,&N2,&N3};

    delete_data(&N1,NULL,NULL,70);











    return 0;
}