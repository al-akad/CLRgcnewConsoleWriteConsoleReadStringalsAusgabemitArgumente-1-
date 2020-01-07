/**

Thema ist C++/CLI (C++.NET, Managed C++, Verwaltete C++) oder C++ withn microsoft (.NET ) extension


			C++ vs Java
	Java:
		-OOP (fast vollständig)
		-Platform independent
		-JVM
		-source Code -> Byte Code, Byte Code wird von JRE (Java Runtime Environment) ausgeführt
		-JRE hat einen Garbage Collector (der Programmier kümmert sich nicht um heap), no delte, delte [] operations!
		-"Java ist langsam": Ursache ist u.a Garbage collector
	C++:
		-OOP (es gibt trotzdem noch Funktionen)
		-Platform dependent
		-no virtual Maschine! Betriebssystem ist verantwortlich
		-There is no byte code
		-no Garbage collector: Speicherverwaltung übernimmt der Programmierer (delte, delte[], Pointer, Pointer arithmetic...)
		-relative C++ ist schnell!
		
	Standard C++ (Stroustrup, B.) bzw native C++ vs. C++/CLI

	-CLI = Common Language Infrastructure unterstzüzt mehrere Sprachen (C#, C++, F#, Visual Basic) und die Platformunabhängigkeit
	-Zielplatform = .NET Framework
	-es gibt einen Garabge Collector

Was möchte ich einführen?
							-Syntax
							-Datentypen in C++ und C++/CLI
							-OOP in C++/CLI
							-Delegates
							-GUI

Grundlage:
		 -Klassen, Objekte, Datentypen
		 -Pointer (*) vs Handler(^)

Rules:
		-Native Objekte liegen auf dem native Heap (new, delete, *)
		-Managed Objekte (ref class) liegen auf dem managed Heap (gcnew, ^)
		-Bei der Erstelleung von native C++ Klassen: keine Attribute vom Typ Managed Klasse und umgekehrt genauso"

			-Managed Klassen nur mit Managed Attribute
			-Native Klassen nur mit native Attribute

*/
#include <iostream>
#include <string>
using namespace std;
using namespace System;

class Point {//Native C++
private:
	int x;
public:
	int y;
	//String^ color;

public:
	int getX() {
		return y;
		}
	void setX(int i) {
		x = i;
	}
	
};
//String ist eine managed Klasse
ref class Person {
private:
	
	String^ name;
public:
	int numberOfKids;
	String^ GetName()
	{
		return name;
	}
	void SetName(String^ str) {
		name = name->Copy(str);
	}
};

ref class Auto {
public:
	//std::string hersteller;
};
int main() {
	//C++ Style
	int i = int(3);//oder einfach 3
	int j(3);
	int n{ 3 };//C++11
	int *k = new int;
		k= new int(89);
		k = new int{ 78 };

	Point p = Point();//Standardkonstruktor und Kopierkonstruktor oder Zuweisungsoperator
	Point q();
	Point r{};//C++11

	Point *s = new Point();
		s = new Point{};
		s = new Point;

	//C++/CLI Style

	Person ^pers = gcnew Person;//Standardkonstruktor wird aufgerufen
		pers = gcnew Person();

		delete s;//Point war native Klasse
		//delete pers; not necessary!

		//Point^ p = gcnew Point();
		//Person* ptr = new Person();
		//Auto* aptr = new Auto();

		cout << "Punkt p " << s->y << " | " << s->getX() << ")" << endl;

		pers->numberOfKids = 3;
		pers->SetName("Martin");
		Console::WriteLine("Person  heisst {1} und hat {0} Kinder ", pers->numberOfKids, pers->GetName());
		Console::WriteLine("enter any Key to terminate!");
		Console::Read();

	return 0;
}