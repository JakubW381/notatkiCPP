#include <iostream>

struct Node{
    int frequency;
    int waveLength;
    int count;
    Node *left;
    Node* right;
    
    Node(int f, int w){
        count = 1;
        frequency = f;
        waveLength = w;
        left = nullptr;
        right = nullptr;
    }
};
struct YearNode{
    int year;
    Node* node;
    YearNode* left;
    YearNode* right;

    YearNode(int y){
        year = y;
        node = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(Node*& root,int f,int w){
    if (!root){
        root = new Node(f,w);
    }else if(f < root -> frequency || (f == root->frequency && w < root->waveLength)){
        insertNode(root->left, f,w);
    }else if(f == root -> frequency && w == root->waveLength){
        root->count++;
    }else{
        insertNode(root->right,f,w);
    } 
}

void insertYear(YearNode*& root, int y, int f, int w){
    if(!root){
        root = new YearNode(y);
        insertNode(root->node,f,w);
    }else if(y < root->year){
        insertYear(root->left,y,f,w);
    }else if (y > root->year)
    {
        insertYear(root->right,y,f,w);
    }else{
        insertNode(root->node,f,w);
    }
}

void printNodes(Node* root){
    if (root)
    {
        printNodes(root->left);
        for (int i = 0; i < root->count; i++)
        {
            std::cout << "(" << root->frequency << "," << root->waveLength << ") ";
        }
        printNodes(root->right); 
    }
}
void printYears(YearNode* root){
    if (root)
    {
        printYears(root->left);
        std::cout << root->year << ": ";
        printNodes(root->node);
        std::cout << std::endl;
        printYears(root->right);
    }
}
bool isValid(int f,int w){
    if (f >=20 && f <=20000)
    {
        if (31300 <= (f*w) && (f*w) <= 35000)
        {
            return true; 
        }  
    }
    return false;
}



int main(){

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    YearNode* root = nullptr;
    bool isDotarty = true;
    for (int  i = 0; i < n; i++)
    {
        int year, freq, wave;
        std::cin >> year >> freq >> wave;
        if ( !(freq>= 275 && freq <=325) )
            {
                isDotarty = false;
            }
        if (isValid(freq,wave))
        {
            
            
            insertYear(root,year,freq,wave);
        }
        
    }
    if (!root)
    {
        isDotarty = false;
    }
    
    printYears(root);
    std::cout << (isDotarty ? "TAK" : "NIE");
    

    return 0;
}

