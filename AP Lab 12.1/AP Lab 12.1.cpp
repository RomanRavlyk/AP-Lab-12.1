#include <iostream>

using namespace std;

int main() {
	struct Elem {
		Elem *link1, *link2;
		int info;
	};

	Elem *p;

	p = new Elem; //1
	p->info = 1; //2
	p->link2 = NULL; //3
	p->link1 = new Elem; //4 
	p->link1->info = 2; //5
	p->link1->link2 = NULL; //6 
	p->link1->link2 = new Elem; //7
	p->link1->link1 = NULL; //8
	p->link1->link2->info = 3; //9
	p->link1->link2->link2 = new Elem; //10
	p->link1->link2->info = 4; //11
	p->link1->link2->link1 = p->link1->link2; //12
	p->link1->link2->link2 = p->link2; //13

	delete p->link2; // 14
	delete p->link1->link1; // 15
	delete p->link1; // 16
	delete p; // 17
}