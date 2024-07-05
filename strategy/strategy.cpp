#include <iostream>


class Strategy {
    public:
        virtual ~Strategy() = default;
        virtual void doAlgorithm(std::string_view data) const = 0;

};



class StrategyA: public Strategy {
    public:
        void doAlgorithm(std::string_view data) const {
            std::cout << "Strategy A: " << data << std::endl;
        }
};


class StrategyB: public Strategy {
    public:
        void doAlgorithm(std::string_view data) const {
            std::cout << "Strategy B: " << data << std::endl;
        }
};


class AlgorithmHandler {
    private:
        const Strategy* strategy;

    public:
        explicit AlgorithmHandler(const Strategy* strategy) : strategy(strategy) {}


    void setStrategy(const Strategy* newStrategy) {
        strategy = newStrategy;
    }

    void executeAlgorithm(std::string_view data) const {
        this->strategy->doAlgorithm(data);
    }
};


int main(){
    StrategyA strategy_a;
    StrategyB strategy_b;

    AlgorithmHandler algorithm_handler(&strategy_a);

    algorithm_handler.executeAlgorithm("aaaaaaaaaa");

    algorithm_handler.setStrategy(&strategy_b);

    algorithm_handler.executeAlgorithm("bbbbbbbbbb");


    return 0;
}

