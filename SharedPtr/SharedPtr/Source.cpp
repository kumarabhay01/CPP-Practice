#include <string>
#include <iostream>

class Project {
	std::string m_Name;
public:
	void SetName(const std::string& name) {
		m_Name = name;
	}
	void ShowProjectDetails() const {
		std::cout << "[Project Name]" << m_Name << "\n";
	}
};

class Employee {
	//Project* m_pProject{}; //Raw pointer
	//std::unique_ptr<Project> m_pProject{};
	std::shared_ptr<Project> m_pProject{};

public:
	//Raw Pointer
	//void SetProject(Project* prj) {
	//	m_pProject = prj;
	//}
	void SetProject(const std::shared_ptr<Project> &prj) {
		m_pProject = prj;
	}

	//const Project* GetProject() const {
	//	return m_pProject;
	//}
	const std::shared_ptr<Project>& GetProject() const {
		return m_pProject;
	}
};

//void ShowInfo(Employee* emp) {
//	std::cout << "Employee project details: ";
//	emp->GetProject()->ShowProjectDetails();
//}

void ShowInfo(const std::shared_ptr<Employee>& emp) {
	std::cout << "Employee project details: ";
	emp->GetProject()->ShowProjectDetails();
}

int main() {
	std::shared_ptr <Project> prj{ new Project{} };
	prj->SetName("Video Decoder");
	std::shared_ptr<Employee> e1{ new Employee{} };
	e1->SetProject(prj);
	std::shared_ptr<Employee> e2{ new Employee{} };
	e2->SetProject(prj);
	std::shared_ptr<Employee> e3{ new Employee{} };
	e3->SetProject(prj);

	std::cout << "Reference count : " << prj.use_count() << '\n';

	ShowInfo(e1);
	ShowInfo(e2);
	ShowInfo(e3);

	prj->ShowProjectDetails();

	//delete prj;
	//delete e1;
	//delete e2;
	//delete e3;


}