#include<iostream>

using namespace std;


class Student{

public:
	string name;

	Student(){

	}
	
	Student(string name){
		this->name = name;
		cout<<"I am a human and i am alive\n";
	}

	~Student(){
		cout<<"Ana entafeet\n";
	}

}; 																

class College{


	Student* studentsList;
	int index;
public:

	College(){
		cout<<"I am up, students come and learn things in me\n";
		studentsList = new Student[10];
		index = 0;
	}

	void enrollStudent(Student& student){
		this->studentsList[index] = student;
		cout<<"Student "<<studentsList[index++].name <<" is now enrolled\n";
	}
	void graduateStudent(){
		cout<<"Student "<<studentsList[index--].name<<" is graduated\n";
	}


	~College(){
		cout<<"I am closed.\n";
	}
};



int main(){


	Student menna("Menna");

	cout<<"Congrats, " <<menna.name<<"! You are accepted in the AUC\n";
	
	College* auc = new College;
	auc->enrollStudent(menna);

	auc->graduateStudent();
	cout<<"Congrats, "<< menna.name<<"! you finally graduated 3aaaaaaa\n";

	delete auc;
	cout<<"AUC is closed, but "<<menna.name<<" is alive\n";


	return 0;
}
