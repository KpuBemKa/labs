#include "securitate.h";

int main() {

	std::vector<pswd::Data> data = pswd::readData();

	for (pswd::Data d : data) {

		std::string password = d.getCode();

		std::vector<char> pswd = { '0' };

		pswd::semiIntPasswordCracker(password, pswd);
	}

	return 0;
}