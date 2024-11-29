#include <iostream>

struct Stack
{
    int sp;
    int* stack;
    Stack(int size){
        sp = -1;
        stack = new int[size];
    }
    ~Stack(){
        delete[] stack;
    }
    bool isEmpty(){
        return sp < 0;
    }
    void Push(int val){
        stack[sp++] = val;
    }
    int Pop(){
        int temp = stack[sp--];
        return temp;
        
    }
    int Top(){
        return stack[sp];
    }
    int Sp(){
        return sp;
    }



};



class Queue //LIFO
{
private:
    int *queue;
    int head, tail, size;
public:
    Queue(int size){
        head = tail = 0;
        this->size = size;
        queue = new int[size];
    };
    ~Queue(){
        delete[] queue;
    }
    bool isEmpty(){
        return head == tail;
    }

    void push(int value){
        queue[tail] = value;
        tail = (tail + 1) % size;
        if (tail == head)
        {
            int *tempQ = new int[size*2];
            unsigned int i = 0;
            do
            {
                tempQ[i] = queue[head];
                head = (head + 1) % size;
                i++;
            } while (tail != head);
            delete[] queue;
            queue = tempQ;
            head = 0;
            tail = size;
            size *=2;
        }
    }
    int pop(){
        int temp = queue[head];
        head = (head+1) % size;
        return temp;
    }
};




class LinkedList
{
private:
    struct ListNode
    {
        ListNode* next;
        int value;

        ListNode(int val){
            value = val;
            next = nullptr;
        }
    };
    
    ListNode* head;
public:
    LinkedList(){
        head = nullptr;
    }
    ~LinkedList()
    {
        ListNode* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head -> next;
            delete head;
        }
    }
    bool isEmpty(){
        return !head;
    }
    void push_front(int value){
        ListNode* temp = new ListNode(value);
        temp -> next = head;
        head = temp;
    }
    void push_back(int value){
        if (isEmpty())
        {
            push_front(value);
        }else{
            ListNode* temp = head;
            while (temp -> next != nullptr)
            {
                temp = temp ->next;
            }
            temp -> next = new ListNode(value);
        }
    }
    int pop_front(){
        if (!isEmpty())
        {
            ListNode* temp = head;
            head = head->next;
            int t = temp ->value;
            delete temp;
            return t;
        }else{
            return NULL;
        }
    }
    int pop_back(){
        if (isEmpty()) return NULL;
        if (head -> next == nullptr)
        {
            pop_front();
        }
        ListNode *iter = head;
        while (iter ->next ->next!= nullptr)
        {
            iter = iter ->next;
        }
        int temp = iter ->next->value;
        delete iter ->next;
        return temp;
    }
};
struct BTreeNode
{
    int value;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
    void insertBTreeNode(BTreeNode*& root,int value){
        if (!root)
        {
            root = new BTreeNode(value);
        }else if(root ->value <= value){
            insertBTreeNode(root->right, value);
        }else{
            insertBTreeNode(root -> left, value);
        }
    }
    void PreOrderBTreePrint(BTreeNode* root){
        if(root){
            std::cout << root ->value << ", ";
            PreOrderBTreePrint(root -> left);
            PreOrderBTreePrint(root -> right);
        }
    }
    void InOrderBTreePrint(BTreeNode* root){
        if(root){
            InOrderBTreePrint(root -> left);
            std::cout << root ->value << ", ";
            InOrderBTreePrint(root -> right);
        }
    }
    void PostOrderBTreePrint(BTreeNode* root){
        if(root){
            PostOrderBTreePrint(root -> left);
            PostOrderBTreePrint(root -> right);
            std::cout << root ->value << ", ";
        }
    }
    int GetHeight(BTreeNode* root){
            if (!root)
            {
                return -1;
            }else{
                int leftHeight = GetHeight(root->left);
                int rightHeight = GetHeight(root->right);
                return ((leftHeight >= rightHeight) ? leftHeight:rightHeight);
            }
    }




int main(){




    return 0;
}