#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Person {
private:
	string name_;
	int age_;
	unique_ptr<Person> pParent_;
public:
	explicit Person(const string name, int age) : name_(name), age_(age), pParent_(nullptr){}
	explicit Person(const string name, int age, unique_ptr<Person>&& parent) : name_(name), age_(age), pParent_(std::move(parent)){}
	~Person() {
		cout << name_ << ":" << age_ <<  "‚Í‰ð‘Ì‚³‚ê‚½\n";
	}

	inline string getParentName() {

		if (pParent_ != nullptr) {
			return pParent_->name_;
		} else {
			return "";
		}
	}
};

int main() {

	const string TARO = "TARO";
	constexpr int TARO_AGE = 33;
	constexpr int SHINTARO_AGE = 6;

	unique_ptr<Person> a1 = make_unique<Person>(TARO,TARO_AGE);

	cout << a1->getParentName() << endl;

	unique_ptr<Person> child = make_unique<Person>("Shintaro", SHINTARO_AGE, std::move(a1));

	cout << child->getParentName() << endl;

}