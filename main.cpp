#include "headers.h"
#include <iostream>

void testForwardList() {
    ForwardList list;

    if (!list.empty()) {
        std::cerr << "Ошибка: список должен быть пустым после создания\n";
    }

    list.push_front(1.0);
    list.push_front(2.0);
    list.push_front(3.0);

    if (list.size() != 3) {
        std::cerr << "Ошибка: неверный размер списка после добавления элементов\n";
    }

    if (list.front() != 3.0) {
        std::cerr << "Ошибка: неверное значение первого элемента\n";
    }

    list.pop_front();
    if (list.front() != 2.0) {
        std::cerr << "Ошибка: неверное значение первого элемента после удаления\n";
    }

    list.clear();
    if (!list.empty()) {
        std::cerr << "Ошибка: список должен быть пустым после очистки\n";
    }

    list.push_front(1.0);
    list.push_front(2.0);
    list.push_front(3.0);
    list.push_front(2.0);
    list.erase(2.0);

    if (list.size() != 2) {
        std::cerr << "Ошибка: неверный размер списка после удаления элементов по значению\n";
    }

    std::cout << "Список после всех операций: ";
    list.display();

    std::cout << "Все тесты завершены.\n";
}

int main() 
{
    testForwardList();
    {
        ForwardList a;
        a.push_front(3);
        a.push_front(2);
        a.push_front(1);
        ForwardList b(std:: move(a));
        b.display();
        a.display();
    }

    {
        ForwardList a;
        a.push_front(3);
        a.push_front(2);
        a.push_front(1);
        ForwardList b;
        b = std:: move(a);
        b.display();
        a.display();
    }
    return 0;
}