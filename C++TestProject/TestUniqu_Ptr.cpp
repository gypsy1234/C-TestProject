
#pragma region "　■  include"

#include <iostream>
#include <string>
#include <memory>
#pragma endregion

#pragma region "　■　Personクラス"

class Person {
private:
	std:: string name_;
	int age_;
	std::unique_ptr<Person> pParent_;
public:
	
	//コンストラクタ
	explicit Person(const std::string name, int age) : name_(name), age_(age), pParent_(nullptr){}
	explicit Person(const std::string name, int age, std::unique_ptr<Person>&& parent) : name_(name), age_(age), pParent_(std::move(parent)){}
	
	//デストラクタ
	~Person() {
		std::cout << name_ << ":" << age_ <<  "は解体された\n";
	}

	//コピー・コンストラクタ
	Person(const Person&) = delete;

	//コピー代入演算子
	Person& operator=(const Person&) = delete;

	//ムーブ・コンストラクタ
	Person(Person&&) = default;

	//ムーブ代入演算子
	Person& operator=(Person&&) = delete;
	
	//親の名前Getter
	inline std::string getParentName() {

		if (pParent_ != nullptr) {
			return pParent_->name_;
		} else {
			return "";
		}
	}
};

#pragma endregion

//Person生成メソッド(ムーブ・コンストラクタ、ムーブ代入演算子delete)
//Person CreatePerson() {
//	return Person("movePerson", 0);
//}

int main() {

	const std::string TARO = "TARO";
	constexpr int TARO_AGE = 33;
	constexpr int SHINTARO_AGE = 6;

	std::unique_ptr<Person> pTaro = std::make_unique<Person>(TARO,TARO_AGE);

	std::cout << pTaro->getParentName() << std::endl;

	std::unique_ptr<Person> pShintaro = std::make_unique<Person>("Shintaro", SHINTARO_AGE, std::move(pTaro));

	std::cout << pShintaro->getParentName() << std::endl;

	Person original("始祖", 0);
	//Person clone = original; コピー代入演算delete
	//Person clone(original); コピーコンストラクタdelete

}


