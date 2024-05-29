#ifndef MYINT_HPP
#define MYINT_HPP

#include <iostream>
#include <string>

class MyInt
{
private:
	int value;
	int control;
public:
	static inline int numComparisons = 0;
	static inline int numAssignments = 0;

	MyInt(): value(0), control(0) {}
	MyInt(int value, int control=0): value(value), control(control) {}
	MyInt(const MyInt& other) {this->value=other.value; this->control=other.control;}
	~MyInt() {}

	static int getNumAssignments() {return numAssignments;}
	static int getNumComparisons() {return numComparisons;}
	int getValue() const {return this->value;}
	int getControl() const {return this->control;}
	
	MyInt operator=(const MyInt& other) {
		this->numAssignments++;
		this->value = other.value;
		this->control = other.control;
		return *this;
	}
	
	MyInt operator++() {
		MyInt tmp;
		tmp.value = ++this->value;
		return tmp;
	}
	MyInt operator++(int) {
		MyInt tmp;
		tmp.value = this->value++;
		return tmp;
	}
	MyInt operator--() {
		MyInt tmp;
		tmp.value = --this->value;
		return tmp;
	}
	MyInt operator--(int) {
		MyInt tmp;
		tmp.value = this->value--;
		return tmp;
	}
	
	MyInt operator+(const MyInt& other) {return MyInt(this->value + other.value);}
	MyInt operator+=(const MyInt& other) {this->value += other.value;return *this;}
	MyInt operator-(const MyInt& other) {return MyInt(this->value - other.value);}
	MyInt operator-=(const MyInt& other) {this->value -= other.value;return *this;}
	MyInt operator*(const MyInt& other) {return MyInt(this->value * other.value);}
	MyInt operator*=(const MyInt& other) {this->value *= other.value;return *this;}
	MyInt operator/(const MyInt& other) {return MyInt(this->value / other.value);}
	MyInt operator/=(const MyInt& other) {this->value /= other.value;return *this;}
	MyInt operator%(const MyInt& other) {return MyInt(this->value % other.value);}
	MyInt operator%=(const MyInt& other) {this->value %= other.value;return *this;}
	bool operator==(const MyInt& other) const {this->numComparisons++;return this->value == other.value;}
	bool operator<(const MyInt& other) const {this->numComparisons++;return this->value < other.value;}
	bool operator<=(const MyInt& other) const {this->numComparisons++;return this->value <= other.value;}
	bool operator>(const MyInt& other) const {this->numComparisons++;return this->value > other.value;}
	bool operator>=(const MyInt& other) const {this->numComparisons++;return this->value >= other.value;}
	bool operator!=(const MyInt& other) const {this->numComparisons++;return this->value != other.value;}
	
	// Might need to define outside of class to allow an int return.
	operator int() const {return this->value;}

	//friend std::ostream& operator<<(std::ostream& os, const MyInt& myint);
	friend std::ostream& operator<<(std::ostream& os, const MyInt& myint) {
		os << myint.value;
		return os;
	}
};



#endif
