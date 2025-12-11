#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

void runTask2() {
    char filename[100] = "text.txt";
    std::cout << "Enter filename (default: text.txt): ";
    // std::cin >> filename; // Можно раскомментировать, если хочется вводить имя

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Error: Could not open file " << filename << ". Make sure it exists!\n";
        std::ofstream testFile(filename);
        testFile << "Apple banana Orange Elephant Universe car house Idea";
        testFile.close();
        std::cout << "Created test file '" << filename << "'. Try again.\n";
        return;
    }

    char buffer[1024]; 

    std::cout << "\n--- Original Text ---\n";

    while (inFile.getline(buffer, 1024)) {
        std::cout << buffer << "\n";
    }
    inFile.close();

    std::cout << "\n--- Modified Text ---\n";
    inFile.open(filename);
    while (inFile.getline(buffer, 1024)) {
        // buffer содержит одну строку текста
        // Пройдемся по ней руками
        bool newWord = true; // Флаг начала слова
        
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isalpha(buffer[i])) {
                if (newWord) {
                    // Это первая буква слова. Проверяем, гласная ли она.
                    if (isVowel(buffer[i])) {
                        std::cout << (char)toupper(buffer[i]); // Выводим прописную
                    } else {
                        std::cout << buffer[i]; // Выводим как есть
                    }
                    newWord = false;
                } else {
                    std::cout << buffer[i]; // Середина слова
                }
            } else {
                std::cout << buffer[i]; // Знаки препинания, пробелы
                newWord = true; // Следующий символ будет началом слова
            }
        }
        std::cout << "\n";
    }
    
    inFile.close();
    std::cout << "\n--- Done ---\n";
}
