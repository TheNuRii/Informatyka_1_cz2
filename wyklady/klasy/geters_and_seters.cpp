#include <istream>

class Animal {
    public:
        Animal(std::string name) {
            setName(name);
        }
        std::string getName() {
            return name;
        }
        void setName(std::string name) {
            this->name = name;
        }
    private:
        std::string name;
};

int main()  {
return 0;
}