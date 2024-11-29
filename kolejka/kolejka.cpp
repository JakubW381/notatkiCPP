#include <iostream>
#include <limits.h>

class Queue{
    public:
    unsigned long long head,tail,size;
    long long* clients;
    bool is_open = false;
    unsigned long long sum, realSize;

    
    Queue(){
        size = 10000;
        clients = new long long[size];
        head = 0;
        tail = 0;
        sum = 0;
        realSize = 0;
    }
    ~Queue(){
        delete[] clients;
    }
    bool Is_Empty(){
        return head == tail; 
    }
    unsigned long long Pop(){
        if (Is_Empty()) return 0;

        long long temp = clients[head];
        head = (head+1) % size;
        sum -= temp;
        realSize--;
        return temp;
    }
    void Push(long long client){
        clients[tail] = client;
        tail = (tail+1) % size;
        if (head == tail)
        {
            unsigned long long newSize = 2 * size;
            long long* temp_clients = new long long[newSize];
            unsigned long long i = 0;

            do
            {
                temp_clients[i] = clients[head];
                head = (head + 1) % size;
                i++;
            } while (head != tail);
            

            delete[] clients;
            clients = temp_clients;
            tail = i;
            head = 0;
            size = newSize; 
        } 
        sum += client;
        realSize++;
    }

    void Next_Flag(int p) {
        while (!Is_Empty() && p >= clients[head]) {
            p -= clients[head];
            Pop();
        }
        if (!Is_Empty() && clients[head] > 0) {
            clients[head] -= p;
            sum -= p;
        }
    }
};
unsigned long long Shortest_Queue(int count,Queue *shop){
    unsigned long long result = 0;
    unsigned long long temp_sum = ULLONG_MAX;
        for (unsigned long long index = 0; index < count; index++)
        {
            if (shop[index].is_open)
            {
                if (shop[index].Is_Empty())
                {
                    return index;
                }
                if (temp_sum > shop[index].sum)
                {
                    temp_sum = shop[index].sum;
                    result = index;
                }
            }
        }
    return result;
}



int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t,l,s,z;
    std::cin >> t >> l >> s >> z;
    Queue* shop = new Queue[l+1];

    while(t){

        char flag;
        std::cin >> flag;
        if (flag == 'o')
        {
            int a = 0;
            std::cin >> a;
            shop[a].is_open = true;
        }
        if(flag == 'k')
        {   
            long p,r;
            std::cin >> p >> r;
            if (p > t)
            {
                for (long i = 0; i < l; i++)
                {
                    if (shop[i].is_open)
                        {
                            if (!shop[i].Is_Empty())
                                {
                                    shop[i].Next_Flag(t);
                                }
                        }
                }
                break;
            }
            t -= p;
            for (long i = 0; i < l; i++)
            {
                if (shop[i].is_open)
                {
                    if (!shop[i].Is_Empty())
                    {
                        shop[i].Next_Flag(p);
                    }
                }
            }
            shop[Shortest_Queue(l,shop)].Push((r*s)+z);
        }
        if (flag == 'z')
        {
            int a = 0;
            std::cin >> a;
            shop[a].Pop();
            shop[a].is_open = false;
            while (!shop[a].Is_Empty())
            {
                shop[Shortest_Queue(l,shop)].Push(shop[a].Pop());
            }
        }   
    }
    for (long i = 0; i < l; i++) {
        if (!shop[i].is_open) {
            std::cout << "K" << i << ": z";
        } else {
            std::cout << "K" << i << ": " << shop[i].realSize << "o " << shop[i].sum << "s"; 
        }
        if (i < l - 1) {
            std::cout << ", ";
        }
    }

    delete[] shop;
    
    return 0;
}