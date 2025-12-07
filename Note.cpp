#include "Note.h"
#include <limits>

Note::Note() {
    name = new char[1]; name[0] = '\0';
    phoneNumber = new char[1]; phoneNumber[0] = '\0';
    birthday[0] = 1; birthday[1] = 1; birthday[2] = 2000;
}

Note::Note(const char* n, const char* p, int d, int m, int y) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    phoneNumber = new char[strlen(p) + 1];
    strcpy(phoneNumber, p);
    birthday[0] = d; birthday[1] = m; birthday[2] = y;
}

Note::Note(const Note& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);
    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];
}

Note::~Note() {
    delete[] name;
    delete[] phoneNumber;
}

void Note::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Note::setPhone(const char* p) {
    delete[] phoneNumber;
    phoneNumber = new char[strlen(p) + 1];
    strcpy(phoneNumber, p);
}

void Note::setDate(int d, int m, int y) {
    if (m < 1 || m > 12) throw std::invalid_argument("Month must be 1-12");
    if (d < 1 || d > 31) throw std::invalid_argument("Day must be 1-31");
    birthday[0] = d; birthday[1] = m; birthday[2] = y;
}

// Оператор присваивания (обязателен при работе с динамической памятью)
Note& Note::operator=(const Note& other) {
    if (this == &other) return *this;
    delete[] name;
    delete[] phoneNumber;
    
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);
    
    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];
    return *this;
}

// Сравнение по алфавиту (strcmp)
bool Note::operator>(const Note& other) const {
    return strcmp(this->name, other.name) > 0;
}

// Ввод из потока
std::istream& operator>>(std::istream& in, Note& note) {
    char buffer[256];
    std::cout << "Enter Name (Last First): ";
    // Очистка буфера перед вводом строки, если нужно
    // in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    in.getline(buffer, 255);
    if (strlen(buffer) == 0) in.getline(buffer, 255); // Костыль для гетлайна
    note.setName(buffer);

    std::cout << "Enter Phone: ";
    in >> buffer;
    note.setPhone(buffer);

    std::cout << "Enter Birthday (Day Month Year): ";
    int d, m, y;
    in >> d >> m >> y;
    try {
        note.setDate(d, m, y);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << ". Set to default.\n";
    }
    return in;
}

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Note& note) {
    out << "Name: " << std::setw(20) << std::left << note.name 
        << "| Phone: " << std::setw(12) << note.phoneNumber 
        << "| Date: " << note.birthday[0] << "." << note.birthday[1] << "." << note.birthday[2];
    return out;
}
