#include <iostream>
#include <vector>

// Forward declaration das classes
class Observer;

// Subject (Sujeito)
class Subject {
private:
    int state;
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void setState(int newState);
    int getState() const;
    void notify();
};

// Observer (Observador)
class Observer {
protected:
    Subject* subject;

public:
    virtual void update() = 0;
};

// ConcreteObserver1
class ConcreteObserver1 : public Observer {
public:
    ConcreteObserver1(Subject* subj) {
        subject = subj;
        subject->attach(this);
    }

    void update() override {
        std::cout << "ConcreteObserver1: Estado atualizado: " << subject->getState() << std::endl;
    }
};

// ConcreteObserver2
class ConcreteObserver2 : public Observer {
public:
    ConcreteObserver2(Subject* subj) {
        subject = subj;
        subject->attach(this);
    }

    void update() override {
        std::cout << "ConcreteObserver2: Nova notificacao recebida" << std::endl;
    }
};

// Implementações dos métodos do Subject

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    // Implementação para remover observer da lista
}

void Subject::setState(int newState) {
    state = newState;
    notify();
}

int Subject::getState() const {
    return state;
}

void Subject::notify() {
    for (Observer* observer : observers) {
        observer->update();
    }
}

int main() {
    Subject subject;
    ConcreteObserver1 observer1(&subject);
    ConcreteObserver2 observer2(&subject);

    subject.setState(10);

    return 0;
}

