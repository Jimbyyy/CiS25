#include "Header1.h"

// constructor
TextBox::TextBox(string type) {
	this->type = type;
}

// getters and setters
string TextBox::getType() const{
	return this->type;
}

void TextBox::setType(const string& type) {
	this->type = type;
}