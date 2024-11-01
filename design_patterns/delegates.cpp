#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <typeinfo>

template<class ret = void, class... args>
class delegate {
public:
    std::vector<std::function<ret(args...)>> callables;

    delegate() = default;

    delegate(const delegate& other) : callables(other.callables) {}

    delegate& operator=(const delegate& other) {
        if (this != &other) {
            callables = other.callables; 
        }
        return *this;
    }

    delegate& operator+=(const std::function<ret(args...)>& fn) {
        addCallable(fn);
        return *this;
    }

    delegate operator+(const std::function<ret(args...)>& fn) const {
        delegate newDelegate = *this;
        newDelegate.addCallable(fn);
        return newDelegate;
    }

    void addCallable(const std::function<ret(args...)>& fn) {
        callables.push_back(fn);
    }

    void execute(args... a) {
        if constexpr (!std::is_void_v<ret>) {
            throw std::runtime_error("Use executeWithReturn for non-void return types");
        }
        for (auto& callable : callables) {
            callable(a...);
        }
    }

    std::vector<ret> executeWithReturn(args... a) {
        if constexpr (std::is_void_v<ret>) {
            throw std::runtime_error("Use execute for void return types");
        }
        std::vector<ret> res;
        for (auto& callable : callables) {
            res.push_back(callable(a...));
        }
        return res;
    }
};

// Sample functions
void melee() {
    std::cout << "Melee\n";
}

void ranged() {
    std::cout << "Ranged\n";
}

int damage(int amt) {
    std::cout << "Damage: " << amt << "\n";
    return amt;
}

int main() {
    delegate<> d;             
    delegate<int, int> d2;    

    std::function<void()> f1 = melee;
    std::function<void()> f2 = ranged;
    std::function<int(int)> f3 = damage;

    d.addCallable(f1);
    d += f2;
    d2.addCallable(f3);

    d.execute();

    auto results = d2.executeWithReturn(10);
    for (auto result : results) {
        std::cout << "Result: " << result << "\n";
    }

    return 0;
}
