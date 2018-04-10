#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Person {
private:
	string name;
	unique_ptr<Person> pParent;
public:
	explicit Person(const string name) : name(name), pParent(nullptr){}
	explicit Person(const string name, unique_ptr<Person>&& parent) : name(name), pParent(std::move(parent)){}
	~Person() {
		cout << name << "‚Í‰ð‘Ì‚³‚ê‚½\n";
	}
	string getParentName() {

		if (pParent != nullptr) {
			return pParent->name;
		} else {
			return "";
		}
	}
};

int main() {

	unique_ptr<Person> a1 = make_unique<Person>("Taro");

	cout << a1->getParentName() << endl;

	unique_ptr<Person> child = make_unique<Person>("Shintaro", std::move(a1));

	cout << child->getParentName() << endl;

}