#include <iostream>
#include "CircularList/CircularListFull.h"
#include "ChainIterator/ChainIterator.h"
using namespace std;

class student{
	public:
		int age,id;
		student(int age,int id){
			this->age = age;
			this->id = id;
		}
		student(){
			
		}
};

bool comp(student A,student B){
	if (A.age == B.age){
		return A.id > B.id;
	}else return A.age > B.age;
}

int main(){
	CircularList<student> studentList;
	studentList.InsertSort(new ChainNode<student>(student(5,10)),&comp);
	studentList.InsertSort(new ChainNode<student>(student(5,17)),&comp);
	studentList.InsertSort(new ChainNode<student>(student(5,12)),&comp);
	studentList.InsertSort(new ChainNode<student>(student(5,9)),&comp);
	studentList.InsertSort(new ChainNode<student>(student(5,11)),&comp);
	studentList.InsertSort(new ChainNode<student>(student(2,11)),&comp);
	for(CircularList<student>::ChainIterator it = studentList.begin(); it != studentList.end();it++){
		cout << it->age << " " << it->id << endl;
	}
}    
