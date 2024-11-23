#ifndef CS25_A30_H
#define CS25_A30_H

#include <iostream>
using std::string;

class TextBox {
private:
	string type;
public:
	// Constructors
	TextBox() = default;
	explicit TextBox(string type);

	// Getter and setter functions
	string getType() const;
	void setType(const string& type);
};

#endif