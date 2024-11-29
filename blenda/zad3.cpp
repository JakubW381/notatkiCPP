#include <iostream>

struct Chlop {
    int C, K, max_days;
};

long long workDays(int days, int C, int K,  int max_days) {
    
    if (max_days> days) {
        max_days = days;  
    }
    
    int lastC = C - (max_days - 1) * K;
    return (max_days * (C + lastC) / 2);
}

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t; 
    std::cin >> t;

    while(t--) {
        int n, d, m;
        std::cin >> n >> d >> m;

        Chlop* chlopi = new Chlop[n]; 

        for (int i = 0; i < n; i++) {
            std::cin >> chlopi[i].C >> chlopi[i].K;
            chlopi[i].max_days = (chlopi[i].C * 1.0/ chlopi[i].K + 1);
        }


        int counter = 0; 

        for (int i = 0; i < d; i++) {
            int day;
            std::cin >> day;
            long result = 0;

            for (int j = 0; j < n; j++) {
                result += workDays(day, chlopi[j].C, chlopi[j].K, chlopi[j].max_days);
            }

            std::cout << result << " ";

            if (result >= m) {
                counter++;
            }
        }

        std::cout << "\n"<< counter << "\n";

        delete[] chlopi;
    }

    return 0;
}
