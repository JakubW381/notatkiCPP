#include <iostream>
#include <string>

struct Item {
    std::string name;
    long mass;
};

void sort_items(Item* sejf, long len) {
    for (long i = 0; i < len - 1; i++) {
        bool swapped = false;
        for (long j = 0; j < len - i - 1; j++) {
            if (sejf[j].mass > sejf[j + 1].mass) {
                std::swap(sejf[j], sejf[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long t = 0;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long n = 0;
        std::cin >> n;

        Item* sejf = new Item[n];

        for (int j = 0; j < n; j++) {
            std::cin >> sejf[j].name >> sejf[j].mass;
        }

        sort_items(sejf, n);

        long total_mass = 0;
        for (int i = 0; i < n; i++) {
            total_mass += sejf[i].mass * (n - i);
        }
        std::cout << total_mass << "\n";

        for (int i = 0; i < n; i++) {
            std::cout << sejf[i].name << " ";
        }
        std::cout << "\n";

        delete[] sejf;
    }
    return 0;
}
