#include <iostream>

// Объявления функций из других файлов
void runTask1();
void runTask2();

int main() {
    while (true) {
        std::cout << "\n=== LABORATORY WORK 2 (Variant 13) ===\n";
        std::cout << "1. Task 1: Notes (Student DB)\n";
        std::cout << "2. Task 2: File Text Processing\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            runTask1();
        } else if (choice == 2) {
            runTask2();
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
