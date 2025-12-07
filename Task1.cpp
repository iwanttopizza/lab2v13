#include "Note.h"

// Сортировка пузырьком по алфавиту
void sortNotes(Note* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) { // Используем перегруженный оператор >
                Note temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void runTask1() {
    int size = 0;
    std::cout << "How many people do you want to add? ";
    std::cin >> size;

    if (size <= 0) return;

    // Динамический массив объектов
    Note* notes = new Note[size];

    // Ввод
    for (int i = 0; i < size; ++i) {
        std::cout << "\n--- Person #" << i + 1 << " ---\n";
        std::cin >> notes[i]; // Используем перегруженный >>
    }

    // Сортировка
    sortNotes(notes, size);
    std::cout << "\n[Sorted by Alphabet]\n";
    for (int i = 0; i < size; ++i) {
        std::cout << notes[i] << "\n";
    }

    // Поиск по месяцу
    while (true) {
        int month;
        std::cout << "\nEnter month to search (1-12) or 0 to exit: ";
        std::cin >> month;
        if (month == 0) break;

        bool found = false;
        std::cout << "--- Results ---\n";
        for (int i = 0; i < size; ++i) {
            if (notes[i].getMonth() == month) {
                std::cout << notes[i] << "\n";
                found = true;
            }
        }
        if (!found) {
            std::cout << "No people found born in month " << month << ".\n";
        }
    }

    delete[] notes; // Чистим память
}
