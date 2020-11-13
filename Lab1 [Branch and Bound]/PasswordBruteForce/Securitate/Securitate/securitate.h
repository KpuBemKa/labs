#include <inttypes.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <sstream>
using namespace std::chrono;

namespace pswd {

	//clasa care stochează datele despre parole
	class Data {

private:
		// parola
		std::string code;
		// timpul necesar pentru a o găsi
		double seconds;

	public:
		// constructorul
		Data(std::string code) {
			this->code = code;
		}

		// get-eri și set-eri
		std::string getCode() {
			return code;
		}

		void setCode(int code) {
			this->code = code;
		}

		double getSeconds() {
			return this->seconds;
		}

		void setSeconds(double seconds) {
			this->seconds = seconds;
		}

	};

	// citirea datelor din fișier
	std::vector<Data> readData() {

		std::ifstream file("in.txt");
		std::string line;

		std::vector<Data> data;

		if (file.is_open()) {
			while (getline(file, line)) {
				data.insert(data.begin(), Data(line));
			}
		}

		file.close();

		reverse(data.begin(), data.end());

		return data;

	}

	void writeData(std::string string, double time) {

		std::ofstream file("out.txt", std::ios_base::app);
		
		file << string << " gasit in " << time << " ms.\n";
		std::cout << string << " gasit in " << time << " ms.\n";

		file.close();

	}

	// ceasul
	static auto start = high_resolution_clock::now();

	// caracterele care se vor folosi pentru a găsi parola
	std::vector<char> characters = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	// setarea unui vector pe 0
	std::vector<char> setVectorToZero(std::vector<char> vector, int position) {
		for (int i = vector.size()-1; i >= position; --i)
			vector[i] = '0';

		return vector;
	}

	// convertirea unui vector de char într-un string
	std::string charToString(std::vector<char> vector) {
		std::string s(vector.begin(), vector.end());
		return s;

	}

	// funcția care incrementează un vector cu char-uri
	std::vector<char> increment(std::vector<char> vector, int positionToIncrement) {
		
		int characterPosition = 0;

		for (int i = 0; i < characters.size(); i++) {
			if (characters[i] == vector[positionToIncrement])
				characterPosition = i;
		}

		if (vector[positionToIncrement] == 'Z' && positionToIncrement == 0) {
			vector.push_back('0');
			vector = setVectorToZero(vector, 0);
		}
		else if (vector[positionToIncrement] == 'Z') {
			vector = increment(vector, positionToIncrement - 1);
			vector = setVectorToZero(vector, positionToIncrement);
		}
		else {
			vector[positionToIncrement] = characters[characterPosition + 1];
		}
			
		return vector;
		
	}

	// funcția care caută parola
	void semiIntPasswordCracker(std::string password, std::vector<char> vector) {

		// string-ul care se va folosi pentru comparare
		std::string comparator = charToString(vector);

		while (comparator != password) {
			std::string comparator = charToString(vector);

			if (comparator == password) {
				auto stop = high_resolution_clock::now();
				auto duration1 = duration_cast<microseconds>(stop - start);
				double duration2 = (double)duration1.count() / 1000;

				writeData(comparator, duration2);

				return;
			}

			vector = increment(vector, vector.size() - 1);
			for (char c : vector) {
				std::cout << c;
			}
			std::cout << "\n";

		}

	}
	
	void intPasswordCrack(int iterator, int password) {

		if (password == iterator) {
			auto stop = high_resolution_clock::now();
			auto duration1 = duration_cast<microseconds>(stop - start);
			double duration2 = (double)duration1.count() / 1000;
			writeData(std::to_string(password), duration2);
		}
		else {
			intPasswordCrack(++iterator, password);
		}
	}

}