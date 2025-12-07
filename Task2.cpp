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
        // Создадим файл для теста, чтобы студент не мучился
        std::ofstream testFile(filename);
        testFile << "apple banana orange elephant universe car house idea";
        testFile.close();
        std::cout << "Created test file '" << filename << "'. Try again.\n";
        return;
    }

    std::cout << "\n--- Original Text ---\n";
    // Читаем весь файл в буфер (упрощенно посимвольно или по словам)
    // По заданию нужно менять слова. Проще читать по словам.
    
    // Но! Если читать по словам (`>>`), мы потеряем пробелы и форматирование. 
    // Задание говорит "считывает текст... и выводит его на экран, заменив...".
    // Значит, лучше читать целиком и обрабатывать на лету.

    char buffer[1024]; 
    while (inFile.getline(buffer, 1024)) {
        // buffer содержит одну строку текста
        // Пройдемся по ней руками
        bool newWord = true; // Флаг начала слова
        
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isalpha(buffer[i])) {
                if (newWord) {
                    // Это первая буква слова. Проверяем, гласная ли она.
                    if (isVowel(buffer[i])) {
                        std::cout << (char)toupper(buffer[i]); // Выводим большую
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
