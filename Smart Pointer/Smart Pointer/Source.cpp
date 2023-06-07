#include "Integer.h"
#include <memory>

void Display(Integer* p) {
	if (!p) {
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

Integer* GetPointer(int value) {
	Integer* p = new Integer{value};
	return p;
}

//void Store(std::unique_ptr<Integer> p) {
//	std::cout << "Storing data into file: " << p->GetValue() << std::endl;
//}

void Store(std::unique_ptr<Integer> &p) {
	std::cout << "Storing data into file: " << p->GetValue() << std::endl;
}

void Operate(int value) {
	//Integer* p = GetPointer(value); //Raw Pointer Example
	std::unique_ptr<Integer> p{ GetPointer(value) };
	if (p == nullptr) {
		//p = new Integer{};
		p.reset(new Integer{ value });
	}
	p->SetValue(100);
	//Display(p);
	Display(p.get());
	//delete p; // can not be deleted as p is not a pointer it is an object
	p = nullptr; 
	//p = new Integer{};
	p.reset(new Integer{});
	*p = __LINE__;
	//Display(p);
	Display(p.get());
	//Store(p); in case of unique pointer the copy constructor is deleted.
	//So this particular line is going to give error
	//Store(std::move(p)); // Move is used as we are not using the p after this line
	Store(p);
	*p = 200;
	//delete p;
}

int main() {
	Operate(5);
}