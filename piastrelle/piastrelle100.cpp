#include <iostream>
#include <fstream>
#define PIASTRELLA1x1 "[O]"
#define PIASTRELLA1x2 "[OOOO]"

using namespace std;


struct tree {
    int value;
    tree* left;
    tree* right;
};

ofstream output;



void _dfs(tree* tree,string string){
    if(tree->left == nullptr && tree->right == nullptr){
        //add string to string buffer
        string+="\n";
        output << string;
        return;
    }else if(tree->left == nullptr){
        _dfs(tree->right,string+PIASTRELLA1x2);
        return;
    }
    else if(tree->right == nullptr){
        _dfs(tree->left,string+PIASTRELLA1x1);
        return;
    }
    else{
        _dfs(tree->left,string+PIASTRELLA1x1);
        _dfs(tree->right,string+PIASTRELLA1x2);
        return;
    }
}

void dfs(tree* tree){
    string string="";

    _dfs(tree,string);

}


tree* create_tree(int n, tree* node){
    switch(n){
        case 0:
            node->value = n;
            node->left= nullptr;
            node->right= nullptr;
            return node;
        case 1:
            node->value = n;

            node->left=(tree*)malloc(sizeof(tree));
            node->left= create_tree(n-1,node->left);

            node->right= nullptr;
            return node;
        default:
            node->value=n;

            node->left=(tree*)malloc(sizeof(tree));
            node->right=(tree*)malloc(sizeof(tree));

            node->left=create_tree(n-1,node->left);
            node->right=create_tree(n-2,node->right);
            return node;
    }
}

int main() {
    // lettura file input
    ifstream in("input.txt");
    string input;
    getline(in,input);

    //apertura file output
    output.open("output.txt", ios::out);

    //albero
    tree* tree1=create_tree(stoi(input),(tree*)malloc(sizeof(tree)));
    dfs(tree1);

    output.close();
}