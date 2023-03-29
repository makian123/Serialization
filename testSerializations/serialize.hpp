#pragma once

class Base1Class {
	public:
	int varBase = 1;
};
class Base2Class {
	public:
	int varBase2 = 2;
};

class DerivedClass: public Base1Class, public Base2Class {
	private:
	int privVar = 3;
	public:
	int varDerived = 4;
};