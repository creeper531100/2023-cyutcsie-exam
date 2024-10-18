#include <iostream>
#include <vector>
#include <typeinfo>
#include <unordered_map>

class IComponent {
public:
    using MessageHandler = void(*)(void* sender);
    virtual void on_listener() = 0;
    MessageHandler callback;
    virtual ~IComponent() = default;
};

class Engine : public IComponent {
public:
    void on_listener() override {
        std::cout << "引擎啟動。\n";
        callback((void*)"Hello, World!");
    }
};

class Wheels : public IComponent {
public:
    void on_listener() override {
        std::cout << "輪子啟動。\n";
        callback((int*)0xB16B00B5);
    }
};

class EventManager {
public:
    std::vector<IComponent*> components; // 使用裸指针

    template <typename T>
    class ComponentRegistration {
    public:
        ComponentRegistration(EventManager& self, T* t)
            : self(self), t(t) {
        }

        EventManager& register_callback(IComponent::MessageHandler callback) {
            t->callback = callback;
            self.components.push_back(t);
            return self;
        }

    private:
        EventManager& self;
        T* t;
    };

    template <typename T>
    ComponentRegistration<T> add_component() {
        return ComponentRegistration<T>(*this, new T());
    }

    EventManager& run() {
        for (auto& element : components) {
            element->on_listener();
        }

        return *this;
    }
};

void echo_sender(void* sender) {
    printf("來自發送者的問候: %p\n", sender);
}

void echo_Hi(void* sender) {
    printf("幹你娘= %s\n", (const char*)sender);
}

int main() {
    EventManager eventManager;

    eventManager.add_component<Wheels>().register_callback(echo_sender);
    eventManager.add_component<Engine>().register_callback(echo_Hi);

    eventManager.run();


    return 0;
}
