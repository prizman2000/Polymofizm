#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pizza {
public:
    virtual string get_name() const = 0;

    virtual unsigned int get_size(unsigned int value) const = 0;

    virtual unsigned int get_price(unsigned int size) const = 0;

    virtual unsigned int add_cheese(unsigned int value, unsigned int size) const = 0;

    virtual unsigned int add_salt(unsigned int value, unsigned int size) const = 0;
};

class Margorishka : public Pizza {
public:
    string get_name() const override {
        return "Маргоришка";
    }

    unsigned int get_size(unsigned int value) const override {
        return value;
    }

    unsigned int get_price(unsigned int size) const override {
        return 300 * size / 20;
    };

    unsigned int add_cheese(unsigned int value, unsigned int size) const override {
        return value * size / 2;
    }

    unsigned int add_salt(unsigned int value, unsigned int size) const override {
        return value * size / 4;
    }

};

class Tropic : public Pizza {
public:
    string get_name() const override {
        return "Тропическая";
    }

    unsigned int get_size(unsigned int value) const override {
        return value;
    }

    unsigned int get_price(unsigned int size) const override {
        return 250 * size / 20;
    }

    unsigned int add_cheese(unsigned int value, unsigned int size) const override {
        return value * size / 2;
    }

    unsigned int add_salt(unsigned int value, unsigned int size) const override {
        return value * size / 4;
    }
};

class Defolt : public Pizza {
public:
    string get_name() const override {
        return "Дефолтная";
    }

    unsigned int get_size(unsigned int value) const override {
        return value;
    }

    unsigned int get_price(unsigned int size) const override {
        return 150 * size / 20;
    }

    unsigned int add_cheese(unsigned int value, unsigned int size) const override {
        return value * size / 2;
    }

    unsigned int add_salt(unsigned int value, unsigned int size) const override {
        return value * size / 4;
    }
};

class Sea : public Pizza {
public:
    string get_name() const override {
        return "Морская";
    }

    unsigned int get_size(unsigned int value) const override {
        return value;
    }

    unsigned int get_price(unsigned int size) const override {
        return 500 * size / 20;
    }

    unsigned int add_cheese(unsigned int value, unsigned int size) const override {
        return value * size / 2;
    }

    unsigned int add_salt(unsigned int value, unsigned int size) const override {
        return value * size / 4;
    }
};

class Order {
    vector<const Pizza *> your_order;
    unsigned int *sum;
    unsigned int itog = 0;
public:
    void add(const Pizza *pizza) {
        your_order.push_back(pizza);
    }

    void print() {
        size_t size = your_order.size();
        unsigned int value_cheese = 0;
        unsigned int value_salt = 0;
        unsigned int value_size = 20;

        if (size == 0) {
            cout << "Ваша корзина пуста";
        } else {
            sum = new unsigned int[size];
            for (size_t i = 0, size = your_order.size(); i < size; i++) {
                cout << i + 1 << ". " << your_order[i]->get_name() << "." << endl;
                cout << "Сколько делаем пиццу в см?\n";
                cin >> value_size;
                cout << "\nВаша пицца размера: "<< value_size;
                cout << " - " << your_order[i]->get_price(value_size) << " руб." << endl;
                cout << "Сколько добавим сырку? ";
                cin >> value_cheese;
                cout << "\nКоличество добавленного сыра: "<< value_cheese<< " = ";
                cout << your_order[i]->add_cheese(value_cheese, value_size) << " руб." << endl;
                cout << "Сколько раз будем подсаливать? ";
                cin >> value_salt;
                cout << "\nКоличество добавленной соли: "<< value_salt<< " = ";
                cout << your_order[i]->add_salt(value_salt, value_size) << " руб." << endl;
                sum[i] = your_order[i]->get_price(value_size) + your_order[i]->add_cheese(value_cheese, value_size) +
                         your_order[i]->add_salt(value_salt, value_size);
                cout << "Стоимость: " << sum[i] << " руб." << endl << endl;
            }
        }
        cout<<endl<<endl<<"ПОдведем итоги.";
        for (int i = 0, size = your_order.size(); i < size; i++) {
            itog += sum[i];
        }
        cout << "\nИтог: " << itog << " руб.";
    }
};


int main() {

    Order order;

    int choise = -1;

    cout << "Меню.\n";
    cout << "1. Маргоришка.\n";
    cout << "2. Тропическая.\n";
    cout << "3. Дефолтная.\n";
    cout << "4. Морская.\n";
    cout << "---------------------------------\n";
    cout << "Размеры пиццы:\n";
    cout << "20см\n";
    cout << "30см\n";
    cout << "35см\n";
    cout << "40см\n";
    cout << "---------------------------------\n";
    cout << "Введите 0 для завершения заказа\n";
    cout << "---------------------------------\n";
    cout << "Введите номера выбранных позиций.\n";

    do {
        cin >> choise;

        switch (choise) {
            case 1:
                order.add(new Margorishka());
                break;
            case 2:
                order.add(new Tropic());
                break;
            case 3:
                order.add(new Defolt());
                break;
            case 4:
                order.add(new Sea());
                break;
        }
    } while (choise > 0);

    order.print();

    return 0;
}