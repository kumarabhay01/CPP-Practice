#include<iostream>
#include<vector>
template<typename T>
class PrettyPrinter {
	T* m_pData;
public:
	PrettyPrinter(T* data) :m_pData(data) {

	}
	void Print() {
		std::cout << *m_pData << std::endl;
	}
	T* GetData() {
		return m_pData;
	}
};

template<>
void PrettyPrinter<std::vector<int>>::Print() {
	for (const auto& x : *m_pData)
		std::cout << x << std::endl;
}

template<>
class PrettyPrinter<const char *> {
	const char * m_pData;
public:
	PrettyPrinter(const char*  data) :m_pData(data) {

	}
	void Print() {
		std::cout << m_pData << std::endl;
	}
	const char* GetData() {
		return m_pData;
	}
};

//template<>
//class PrettyPrinter<std::vector<int>> {
//	std::vector<int> *m_pData;
//public:
//	PrettyPrinter(std::vector<int> *data) :m_pData(data) {
//
//	}
//	void Print() {
//		for (const auto& x : *m_pData)
//			std::cout << x << std::endl;
//	}
//	std::vector<int> *GetData() {
//		return m_pData;
//	}
//};

int main() {
	int data = 5;
	float f = 8.2f;

	PrettyPrinter<int> p1(&data);
	p1.Print();

	PrettyPrinter<float> p2(&f);
	p2.Print();

	const char* p{ "Hello World" };

	PrettyPrinter<const char*> p3(p);
	p3.Print();

	//char* pData = p3.GetData(); // This is giving isssue as T is becoming pointer to pointer
	//we need to do explicit specialization.

	const char* pData = p3.GetData();

	//With VEctor
	std::vector<int> v{ 1,2,3,4 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();
	return 0;
}