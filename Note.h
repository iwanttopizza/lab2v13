#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

class Note {
private:
    char* name;          // Фамилия Имя
    char* phoneNumber;   // Номер телефона
    int birthday[3];     // [0]-день, [1]-месяц, [2]-год

public:
    Note();
    Note(const char* n, const char* p, int d, int m, int y);
    Note(const Note& other); // Конструктор копирования
    ~Note();

    // Геттеры
    const char* getName() const { return name; }
    int getMonth() const { return birthday[1]; }

    // Сеттеры
    void setName(const char* n);
    void setPhone(const char* p);
    void setDate(int d, int m, int y);

    // Операторы сравнения для сортировки
    bool operator>(const Note& other) const; // Сравнение по алфавиту
    Note& operator=(const Note& other);      // Присваивание

    // Перегрузка ввода/вывода (Требование задания)
    friend std::istream& operator>>(std::istream& in, Note& note);
    friend std::ostream& operator<<(std::ostream& out, const Note& note);
};

#endif // NOTE_H
