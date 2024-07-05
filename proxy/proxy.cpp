#include <iostream>
#include <string>


class Messenger {
    public:
        virtual ~Messenger() = default;
        virtual void sendMessage(const std::string& message) const = 0;
};

class RealMessager: public Messenger{
    public:
        void sendMessage(const std::string& message) const override {
            std::cout << "Sending message: " << message << std::endl;
        }
};  



class LogginMessagerProxy: public Messenger {
    private:
        RealMessager* realMessager;

        void logMessage(const std::string& message) const {
        std::cout << "[PROXY]Logging message: " << message << std::endl;
    }

    public:

        LogginMessagerProxy(): realMessager(new RealMessager()){}

        ~LogginMessagerProxy(){
            delete realMessager;
        }

        void sendMessage(const std::string& message) const override {
            logMessage(message);
            realMessager->sendMessage(message);
        }



};


int main(){
    LogginMessagerProxy messager;

    messager.sendMessage("Hello");
    messager.sendMessage("Ryan");

    return 0;
}

