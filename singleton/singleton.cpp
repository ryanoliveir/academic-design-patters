#include <iostream>

class Singleton {
    private:
        static Singleton* instance;
        int counter;


        Singleton(): counter(0) {}

    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }

            return instance;
        }

        void incrementCounter() { 
            counter++; 
        }

        int getCounter() { 
            return counter; 
        }
};


Singleton* Singleton::instance = nullptr;

int main(){

    Singleton* instance_1 = Singleton::getInstance();

    instance_1->incrementCounter();
    instance_1->incrementCounter();
    instance_1->incrementCounter();
    instance_1->incrementCounter();
    instance_1->incrementCounter();
    instance_1->incrementCounter();


    std::cout << instance_1->getCounter() << std::endl;


    Singleton* instance_2 = Singleton::getInstance();

    instance_2->incrementCounter();
    instance_2->incrementCounter();


    std::cout << instance_1->getCounter() << std::endl;

    return 0;
}