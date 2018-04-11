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
		cout << name << "は解体された\n";
	}

	inline string getParentName() {

		if (pParent != nullptr) {
			return pParent->name;
		} else {
			return "";
		}
	}
};

int main() {

	const string TARO = "TARO";

	unique_ptr<Person> a1 = make_unique<Person>(TARO);

	cout << a1->getParentName() << endl;

	unique_ptr<Person> child = make_unique<Person>("Shintaro", std::move(a1));

	cout << child->getParentName() << endl;

}