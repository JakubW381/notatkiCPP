#include <iostream>


//----------------------------------------------------
//-----------------------Linked List------------------
//----------------------------------------------------
class LinkedList
{
private:
    struct ListNode
    {
        int value;
        ListNode* next;

        ListNode(int value){
            this->value = value;
            this->next = nullptr;
        }
    };
    ListNode* head;
public:
    LinkedList(){
        head = nullptr;
    }
    ~LinkedList(){
        ListNode* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head ->next;
            delete temp;
        }
    }
    bool is_Empty(){
        return (!head);
    }

    int front(){
        if (is_Empty()) return -1;
        return head ->value;
    }
    int back(){
        if (is_Empty()) return -1;
            ListNode* last = head;
            while (last->next) last = last ->next;
            return last -> value;
    }
    ListNode* first(){
        if (is_Empty()) return nullptr;
        return head;
    }
    ListNode* last(){
        if (!is_Empty())
        {
            ListNode* temp = head;
            while (temp -> next != nullptr)
            {
                temp = temp -> next;
            }
            return temp;
        }else{
            return nullptr;
        }
    }
    ListNode* next(ListNode* node){
        if (node != nullptr && node -> next != nullptr)
        {
            return (node ->next);
        }else{
            return nullptr;
        }
    }
    void push_front(int value){
        ListNode* temp = new ListNode(value);
        temp ->next = head;
        head = temp;
    }
    void push_back(int value){
        if (is_Empty()) {
            push_front(value);
        } else {
            ListNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = new ListNode(value);
        }
    }
    int pop_front(){
        if (is_Empty()) return -1;
        int temp = head->value;
        ListNode* to_delete = head;
        head = head->next;
        delete to_delete;
        return temp;
    }

    int pop_back(){
        if (is_Empty()) return -1;
        if (head ->next == nullptr)
        {
            pop_front();
        }
        else{
            ListNode* temp = head;
            while ((temp -> next) -> next != nullptr)
            {
                temp = temp -> next;
            }
            int temp_val = (temp -> next) ->value;
            delete (temp -> next);
            return temp_val;
        }
    }
    void insert(ListNode* node, int new_element){
        if(node != nullptr){
            ListNode* temp = node -> next;
            node -> next = new ListNode(new_element);
            (node ->next) -> next = temp;
        }else{
            push_front(new_element);
        }
    }
    void erase(ListNode* node){
        if (node == nullptr || node->next == nullptr) return;
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }

};

//----------------------------------------------------
//-----------------Kolejka Tablicowa------------------
//----------------------------------------------------

class Queue
{
private:
    int *queue;
    unsigned int head, tail, size;
public:
    Queue(int size = 100){
        head = tail = 0;
        this->size = size;
        queue = new int[size];
    }
    ~Queue(){
        delete[] queue;
    }
    bool is_Empty(){
        return head == tail;
    }
    void push(int value){
        queue[tail] = value;
        tail = (tail+1) % size;
        if (head == tail)
        {
            int* temp_q = new int[size*2];
            unsigned int i = 0;
            do
            {
                temp_q[i] = queue[head];
                head =(head+1)% size;
                i++;
            } while (head != tail);
            delete[] queue;
            queue = temp_q;
            head = 0;
            tail = size;
            size *= 2;
        }
    }
    int pop(){
        int temp = queue[head];
        head = (head+1) % size;
        return temp;
    }
};

//----------------------------------------------------
//------------------Stos tablicowy--------------------
//----------------------------------------------------

struct Stack
{
    int sp = (-1);
    int stack[100];


    void push(int val){
        
        if (sp < 99)
        {
            stack[sp++] = val;
        }else{
            std::cout << "stack overflow\n";
        }
    }
    int pop(){
        if (sp < 0)
        {
            std::cout << "wrong stack pointer"; 
            return stack[sp--];
        }else{
            return stack[sp--];
        }
    }
    int top(){
        return stack[sp];
    }
    bool is_Empty(){
        return (sp < 0);
    }


};

//----------------------------------------------------
//-------------------Drzewo Binarne-------------------
//----------------------------------------------------
struct BTreeNode
{
    int value;
    BTreeNode* left;   
    BTreeNode* right;  

    BTreeNode(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    } 
};
void InsertNode(BTreeNode*& root, int value){

    if (!root)
    {
        root = new BTreeNode(value);
    }else if (root -> value >= value)
    {
        InsertNode(root ->left,value);
    }else{
        InsertNode(root ->right, value);
    }
}
void PrintINORDER(BTreeNode*& root){
    if (root)
    {
        PrintINORDER(root ->left);
        std::cout << root -> value << ", ";
        PrintINORDER(root ->right);
    }
}
void PrintPREORDER(BTreeNode*& root){
    if (root)
    {
        std::cout << root -> value << ", ";
        PrintPREORDER(root->left);
        PrintPREORDER(root -> right);
    }
}
void PrintPOSTORDER(BTreeNode*& root){
    if (root)
    {
            PrintPOSTORDER(root ->left);
        PrintPOSTORDER(root -> right);
    std::cout << root->value << ", ";
    }
}

int GetHeight(BTreeNode* root) {
    if (!root) {
        return -1; 
    }
    int leftHeight = GetHeight(root->left);  
    int rightHeight = GetHeight(root->right); 
    
    return 1 + ((leftHeight >= rightHeight) ? leftHeight:rightHeight); 
}

//----------------------------------------------------
//-------------------Drzewo K-arne--------------------
//----------------------------------------------------

struct KaryTreeNode{
    int value;
    KaryTreeNode* parent;
    KaryTreeNode* leftChild;
    KaryTreeNode* rightBrother;

    KaryTreeNode(int val){
        value = val;
        parent = nullptr;
        leftChild = nullptr;
        rightBrother = nullptr;
    }
};
    void addChild(KaryTreeNode*& parent, int value){
        KaryTreeNode *node = new KaryTreeNode(value);
        node -> parent = parent;

        if (!parent ->leftChild)
        {
            parent ->leftChild = node;
        }else{
            KaryTreeNode* temp = parent ->leftChild;
            while (temp ->rightBrother)
            {
                temp = temp ->rightBrother;
            }
            temp ->rightBrother = node;
        }
    }
    void printINORDER(KaryTreeNode* root){
        if (root)
        {
         printINORDER(root->leftChild);
         std::cout << root ->value << ",";
         printINORDER(root ->rightBrother);   
        }
    }




//----------------------------------------------------
//-------------------Algorytmy Sortowania-------------
//----------------------------------------------------
void BubbleSort(int* arr , int size){ //O(n^2) stabilne
    for (int i = 0; i < size-1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swapped = true;
                std::swap(arr[j], arr[j+1]);
            }
            
        }
        if (!swapped) break;  
    } 
}
void InsertSort(int *arr,int size){ //O(n^2) stabilne
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    
}




int main(){
    
    
    int arr[] = {10,15,6,1,8,7,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    BTreeNode *root = nullptr;
    std::cout<< "Test Array:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout<< arr[i] << ", ";
        InsertNode(root,arr[i]);
    }
    
    std::cout<< "\ninorder\n";
    PrintINORDER(root);
    std::cout<< "\npreorder\n";
    PrintPREORDER(root);
    std::cout<< "\npostorder\n";
    PrintPOSTORDER(root);
    std::cout<< "\nheight\n";
    std::cout << GetHeight(root);

    std::cout << "\n Bubble sort\n";
    InsertSort(arr,size);
    for (int i = 0; i < size; i++)
    {
        std::cout<< arr[i] << ", ";
    }

    return 0;
}