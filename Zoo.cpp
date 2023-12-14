#include <iostream>
#include <vector>
using namespace std;

class Animal { // ��������� ����� Animal, ������� �������� ��� �������� (public) ����������:
public:
    string name; //������
    int age; // �����
    string species; //������

public: 
    Animal(string _name, int _age, string _species) : name(_name), age(_age), species(_species) {} // ��������� ����������� ������ `Animal`, 
    //������� ��������� ��� ���������: `_name` (���), `_age` (�������) � `_species` (���). 
    //��� �������� ������� ������ `Animal` ��� ��������� ������������ ��� ������������� ����������-������ `name`, `age` � `species`.
    
    // ������ ������ Animal
    void eat() { // ����� eat ������� ��������� "Animal is eating"
        cout << "Animal is eating" << endl;
    }

    void sleep() { // ����� sleep ������� ��������� "Animal is sleeping"
        cout << "Animal is sleeping" << endl;
    }

    void move() { // ����� move ������� ��������� "Animal is moving"
        cout << "Animal is moving" << endl;
    }
};

class Kangaroo : public Animal {    // ��������� ����� �������, ����������� �� �������� ������ Animal
private: // ���������� ���������� (����-��) ������ �������
    int jumpHeight; // ���������� ����������
    string pouchContents;   // ���������� ����������

public:
    // � ������������ Kangaroo ���������������� ���������� � ����������� ���������� �� ������ Animal 
    Kangaroo(string _name, int _age, int _jumpHeight, string _pouchContents)
        : Animal(_name, _age, "Kangaroo"), jumpHeight(_jumpHeight), pouchContents(_pouchContents) {}
    // ������ ������ Kangaroo
    void jump() {
        cout << "Kangaroo is jumping" << endl;  // ����� jump ������� ��������� "Kangaroo is jumping"
    }

    void carryInPouch(string item) {    // ����� carryInPouch ������� ��������� "Kangaroo is carrying"
        cout << "Kangaroo is carrying " << item << " in its pouch" << endl;
    }

    void eat() {    // ����� eat ������� ��������� "Kangaroo is eating leaves"
        cout << "Kangaroo is eating leaves" << endl;
    }
};

class Owl : public Animal {     // ��������� ����� ����, ����������� �� �������� ������ Animal
private:    // ���������� ���������� (����-��) ������ ����
    int wingSpan;   // ���������� ����������
    string favoriteTime;    // ���������� ����������

public:
    // � ������������ Owl ���������������� ���������� � ����������� ���������� �� ������ Animal
    Owl(string _name, int _age, int _wingSpan, string _favoriteTime)
        : Animal(_name, _age, "Owl"), wingSpan(_wingSpan), favoriteTime(_favoriteTime) {}
    // ������ ������ Owl
    void fly() {    // ����� fly ������� ��������� "Owl is flying"
        cout << "Owl is flying" << endl;
    }

    void hoot() {   // ����� hoot ������� ��������� "Owl is hooting"
        cout << "Owl is hooting" << endl;
    }

    void sleep() {  // ����� sleep ������� ��������� "Owl is sleeping during the day"
        cout << "Owl is sleeping during the day" << endl;
    }
};

class Crocodile : public Animal {   // ��������� ����� ��������, ����������� �� �������� ������ Animal
private:    // ���������� ���������� (����-��) ������ ��������
    int toothCount; // ���������� ����������
    string habitat; // ���������� ����������

public:
    // � ������������ Crocodile ���������������� ���������� � ����������� ���������� �� ������ Animal
    Crocodile(string _name, int _age, int _toothCount, string _habitat)
        : Animal(_name, _age, "Crocodile"), toothCount(_toothCount), habitat(_habitat) {}

    void swim() {   // ����� swim ������� ��������� "Crocodile is swimming"
        cout << "Crocodile is swimming" << endl;
    }

    void snapJaws() {   // ����� snapJaws ������� ��������� "Crocodile is snapping its jaws"
        cout << "Crocodile is snapping its jaws" << endl;
    }

    void move() {   // ����� move ������� ��������� "Crocodile is moving slowly on land or in water"
        cout << "Crocodile is moving slowly on land or in water" << endl;
    }
};

void addAnimalToZoo(vector<Animal*>& zoo, Animal* newAnimal) {  // ����������� ������� `addAnimalToZoo`, ������� ��������� ��� ���������: `zoo` (������ (���������) ���������� �� ������� `Animal`) 
    // � `newAnimal` (��������� �� ����� ��������, ������� ����� �������� � �������)
    zoo.push_back(newAnimal);   // � ������� ������ `push_back` ������ `zoo` ����������� ��������� �� ����� ��������
    cout << "Animal added to the zoo" << endl;  // ��������� ��������� � ���, ��� �������� ��������� � �������
}
void printZoo(vector<Animal*>& zoo) {   // ����������� ������� `printZoo`, ������� ��������� ������ ���������� �� ������� ���� `Animal` � �������� ���������
    cout << "Zoo contains the following animals:" << endl; // ��������� ��������� � ���������� ��������
    for (auto& animal : zoo) {  // ���� for ���������� ������ ������� ������� `zoo`
        cout << animal->name << " - " << animal->species << " - " << animal->age << " years old" << endl;   // ��� ������� ��������� ��������� ���������� � ��� �����, ���� � ��������
    }
}

int main() {
    vector<Animal*> zoo; // ���������� ���������� zoo
    string name;    // ���������� ����������
    int age;    // ���������� ����������
    int choice; // ���������� ����������

    do { // ����������� ���� do while, ����� ���� != 4
        cout << "Choose the type of animal to add: \n1. Kangaroo\n2. Owl\n3. Crocodile\n4. Finish adding\n\n"; // ������������� ������� ����� ���������, �������� ���������� �������� � �������
        cin >> choice; // ��������� ����� ����� ��������� � ���������� choice

        if (choice == 4) { // ����������� ���� if
            break; // ��������� �����
        }

        cout << "Enter the animal's name: "; // ������ �� ���� ����� ���������
        cin >> name; // ��������� ��� ����� ��������� � ���������� name
        cout << "Enter the animal's age: "; // ������ �� ���� ������� ���������
        cin >> age; // ��������� ������� ����� �������� � ���������� age

        switch (choice) { // ����������� switch-case
            case 1: { // ���� ������������ ���� ����� 1
                int jumpHeight; // ���������� ����������
                string pouchContents; // ���������� ����������
                cout << "Enter the jump height: "; // ������ �� ���� ������ ������
                cin >> jumpHeight;  // ��������� �������� ����� �������� � ���������� jumpHeight
                cout << "Enter the pouch contents: ";   // ������ �� ������� ����, ��� ��������� � ����� � �������
                cin >> pouchContents;   // ��������� �������� ����� �������� � ���������� pouchContents
                Kangaroo* kangaroo = new Kangaroo(name, age, jumpHeight, pouchContents); // ��������� ��������� `kangaroo` �� ������ ���� `Kangaroo`, ��������� ��������� �������� ������ ������ � ����������� �����.
                addAnimalToZoo(zoo, kangaroo);  // ���������� ������� ��� ���������� ������� � �������.
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
            default: // �����������, ����� ������� ����� �� ��������� �� � ����� �� ��������� ��������� (case)
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4);

    printZoo(zoo); // ���������� ������� printZoo, ������� �������� ���� ����������� �������� ����� ���� for

    for (auto animal : zoo) {
        delete animal;
    }

    return 0; // ��������� ���������� ���������
}