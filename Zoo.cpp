#include <iostream>
#include <vector>
using namespace std;

class Animal { // Объявляем класс Animal, который содержит три открытых (public) переменных:
public:
    string name; //Строка
    int age; // Число
    string species; //Строка

public: 
    Animal(string _name, int _age, string _species) : name(_name), age(_age), species(_species) {} // Объявляем конструктор класса `Animal`, 
    //который принимает три параметра: `_name` (имя), `_age` (возраст) и `_species` (вид). 
    //При создании объекта класса `Animal` эти параметры используются для инициализации переменных-членов `name`, `age` и `species`.
    
    // Методы класса Animal
    void eat() { // Метод eat выводит сообщение "Animal is eating"
        cout << "Animal is eating" << endl;
    }

    void sleep() { // Метод sleep выводит сообщение "Animal is sleeping"
        cout << "Animal is sleeping" << endl;
    }

    void move() { // Метод move выводит сообщение "Animal is moving"
        cout << "Animal is moving" << endl;
    }
};

class Kangaroo : public Animal {    // Создается класс Кенгуру, наследуемый от базового класса Animal
private: // Уникальные переменные (свой-ва) класса Кенгуру
    int jumpHeight; // Объявление переменной
    string pouchContents;   // Объявление переменной

public:
    // В конструкторе Kangaroo инициализируются переменные и наследуемые переменные из класса Animal 
    Kangaroo(string _name, int _age, int _jumpHeight, string _pouchContents)
        : Animal(_name, _age, "Kangaroo"), jumpHeight(_jumpHeight), pouchContents(_pouchContents) {}
    // Методы класса Kangaroo
    void jump() {
        cout << "Kangaroo is jumping" << endl;  // Метод jump выводит сообщение "Kangaroo is jumping"
    }

    void carryInPouch(string item) {    // Метод carryInPouch выводит сообщение "Kangaroo is carrying"
        cout << "Kangaroo is carrying " << item << " in its pouch" << endl;
    }

    void eat() {    // Метод eat выводит сообщение "Kangaroo is eating leaves"
        cout << "Kangaroo is eating leaves" << endl;
    }
};

class Owl : public Animal {     // Создается класс Сова, наследуемый от базового класса Animal
private:    // Уникальные переменные (свой-ва) класса Сова
    int wingSpan;   // Объявление переменной
    string favoriteTime;    // Объявление переменной

public:
    // В конструкторе Owl инициализируются переменные и наследуемые переменные из класса Animal
    Owl(string _name, int _age, int _wingSpan, string _favoriteTime)
        : Animal(_name, _age, "Owl"), wingSpan(_wingSpan), favoriteTime(_favoriteTime) {}
    // Методы класса Owl
    void fly() {    // Метод fly выводит сообщение "Owl is flying"
        cout << "Owl is flying" << endl;
    }

    void hoot() {   // Метод hoot выводит сообщение "Owl is hooting"
        cout << "Owl is hooting" << endl;
    }

    void sleep() {  // Метод sleep выводит сообщение "Owl is sleeping during the day"
        cout << "Owl is sleeping during the day" << endl;
    }
};

class Crocodile : public Animal {   // Создается класс Крокодил, наследуемый от базового класса Animal
private:    // Уникальные переменные (свой-ва) класса Крокодил
    int toothCount; // Объявление переменной
    string habitat; // Объявление переменной

public:
    // В конструкторе Crocodile инициализируются переменные и наследуемые переменные из класса Animal
    Crocodile(string _name, int _age, int _toothCount, string _habitat)
        : Animal(_name, _age, "Crocodile"), toothCount(_toothCount), habitat(_habitat) {}

    void swim() {   // Метод swim выводит сообщение "Crocodile is swimming"
        cout << "Crocodile is swimming" << endl;
    }

    void snapJaws() {   // Метод snapJaws выводит сообщение "Crocodile is snapping its jaws"
        cout << "Crocodile is snapping its jaws" << endl;
    }

    void move() {   // Метод move выводит сообщение "Crocodile is moving slowly on land or in water"
        cout << "Crocodile is moving slowly on land or in water" << endl;
    }
};

void addAnimalToZoo(vector<Animal*>& zoo, Animal* newAnimal) {  // Объявляется функция `addAnimalToZoo`, которая принимает два аргумента: `zoo` (вектор (контейнер) указателей на объекты `Animal`) 
    // и `newAnimal` (указатель на новое животное, которое нужно добавить в зоопарк)
    zoo.push_back(newAnimal);   // С помощью метода `push_back` вектор `zoo` добавляется указатель на новое животное
    cout << "Animal added to the zoo" << endl;  // Выводится сообщение о том, что животное добавлено в зоопарк
}
void printZoo(vector<Animal*>& zoo) {   // Объявляется функция `printZoo`, которая принимает вектор указателей на объекты типа `Animal` в качестве аргумента
    cout << "Zoo contains the following animals:" << endl; // Выводится сообщение о содержимом зоопарка
    for (auto& animal : zoo) {  // Цикл for перебирает каждый элемент вектора `zoo`
        cout << animal->name << " - " << animal->species << " - " << animal->age << " years old" << endl;   // Для каждого животного выводится информация о его имени, виде и возрасте
    }
}

int main() {
    vector<Animal*> zoo; // Объявление переменной zoo
    string name;    // Объявление переменной
    int age;    // Объявление переменной
    int choice; // Объявление переменной

    do { // Запускается цикл do while, делай пока != 4
        cout << "Choose the type of animal to add: \n1. Kangaroo\n2. Owl\n3. Crocodile\n4. Finish adding\n\n"; // Запрашивается указать цифру животного, которого необходимо добавить в зоопарк
        cin >> choice; // Введенная цифра будет сохранена в переменную choice

        if (choice == 4) { // Запускается цикл if
            break; // Остановка цикла
        }

        cout << "Enter the animal's name: "; // Запрос на ввод имени животного
        cin >> name; // Введенное имя будет сохранено в переменную name
        cout << "Enter the animal's age: "; // Запрос на ввод возраст животного
        cin >> age; // Введенное возраст будет сохранен в переменную age

        switch (choice) { // Конструкция switch-case
            case 1: { // Если пользователь ввел цифру 1
                int jumpHeight; // Объявление переменной
                string pouchContents; // Объявление переменной
                cout << "Enter the jump height: "; // Запрос на ввод высоты прыжка
                cin >> jumpHeight;  // Введенное значение будет сохранен в переменную jumpHeight
                cout << "Enter the pouch contents: ";   // Запрос на предмет того, что находится в сумке у Кенгуру
                cin >> pouchContents;   // Введенное значение будет сохранен в переменную pouchContents
                Kangaroo* kangaroo = new Kangaroo(name, age, jumpHeight, pouchContents); // Создается указатель `kangaroo` на объект типа `Kangaroo`, используя введенные значения высоты прыжка и содержимого сумки.
                addAnimalToZoo(zoo, kangaroo);  // вызывается функция для добавления кенгуру в зоопарк.
                break;
            }
            case 2: {
                int wingSpan;
                string favoriteTime;
                cout << "Enter the wingspan: ";
                cin >> wingSpan;
                cout << "Enter the favorite time: ";
                cin >> favoriteTime;
                Owl* owl = new Owl(name, age, wingSpan, favoriteTime);
                addAnimalToZoo(zoo, owl);
                break;
            }
            case 3: {
                int toothCount;
                string habitat;
                cout << "Enter the tooth count: ";
                cin >> toothCount;
                cout << "Enter the habitat: ";
                cin >> habitat;
                Crocodile* crocodile = new Crocodile(name, age, toothCount, habitat);
                addAnimalToZoo(zoo, crocodile);
                break;
            }
            default: // Выполняется, когда введная цифра не совпадает ни с одним из указанных вариантов (case)
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4);

    printZoo(zoo); // Вызывается функция printZoo, которая вывводит всех добавленных животных через цикл for

    for (auto animal : zoo) {
        delete animal;
    }

    return 0; // Остановка исполнения программы
}