#include<iostream>

using namespace std;

class Moustache{

public:
	Moustache(){
		cout<<"Now you have a Moustache\n";
	}

	~Moustache(){
		cout<<"You shaved MEEE :( \n";
	}
};

class Human{

public:
	Moustache* moustache;

	Human(){
		cout<<"I am alive\n";
		moustache = nullptr;
	}

	~Human(){
		cout<<"I am dead\n";
		if(this->moustache != nullptr){
			delete this->moustache;
		}
	}
};

int main(){


	int age;
	Human person;
	char answer;
	while(true){
	cout<<"what is your age now?";
	cin>>age;	
	if(age>12){
		person.moustache =  new Moustache();

	}
	if(person.moustache != nullptr){
		cout<<"WOW! you have a moustache!";
		cout<<"Would you like to shave? [y/n]";
		cin>>answer;
		if(answer == 'y'){
			delete person.moustache;
			person.moustache = nullptr;
		}
	}else{
		cout<<"You are still young!\n";
	}

	if(age == -1){
		break;
	}
	
}

		return 0;
}
