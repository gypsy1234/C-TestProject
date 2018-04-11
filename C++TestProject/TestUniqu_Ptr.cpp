
#pragma region "�@��  include"

#include <iostream>
#include <string>
#include <memory>
#pragma endregion

#pragma region "�@���@Person�N���X"

class Person {
private:
	std:: string name_;
	int age_;
	std::unique_ptr<Person> pParent_;
public:
	
	//�R���X�g���N�^
	explicit Person(const std::string name, int age) : name_(name), age_(age), pParent_(nullptr){}
	explicit Person(const std::string name, int age, std::unique_ptr<Person>&& parent) : name_(name), age_(age), pParent_(std::move(parent)){}
	
	//�f�X�g���N�^
	~Person() {
		std::cout << name_ << ":" << age_ <<  "�͉�̂��ꂽ\n";
	}

	//�R�s�[�E�R���X�g���N�^
	Person(const Person&) = delete;

	//�R�s�[������Z�q
	Person& operator=(const Person&) = delete;

	//���[�u�E�R���X�g���N�^
	Person(Person&&) = default;

	//���[�u������Z�q
	Person& operator=(Person&&) = delete;
	
	//�e�̖��OGetter
	inline std::string getParentName() {

		if (pParent_ != nullptr) {
			return pParent_->name_;
		} else {
			return "";
		}
	}
};

#pragma endregion

//Person�������\�b�h(���[�u�E�R���X�g���N�^�A���[�u������Z�qdelete)
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

	Person original("�n�c", 0);
	//Person clone = original; �R�s�[������Zdelete
	//Person clone(original); �R�s�[�R���X�g���N�^delete

}


