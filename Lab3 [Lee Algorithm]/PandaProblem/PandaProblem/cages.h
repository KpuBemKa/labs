class Cage {

private:
	bool containsPanda = false;
	bool containsFood = false;
	bool isAccessible = false;
	bool isVisited = false;
	int value = 0;

public:
	Cage(bool isAccessible) {
		this->isAccessible = isAccessible;
	}

	Cage() {

	}

	bool doesContainPanda() {
		return containsPanda;
	}

	bool doesContainFood() {
		return containsFood;
	}

	bool isCageAccessible() {
		return isAccessible;
	}

	bool isCageVisited() {
		return isVisited;
	}

	int getValue() {
		return value;
	}

	void setContainsPanda(bool containsPanda) {
		this->containsPanda = containsPanda;
	}

	void setContainsFood(bool containsFood) {
		this->containsFood = containsFood;
	}

	void setIsAccessible(bool isAccessible) {
		this->isAccessible = isAccessible;
	}

	void setIsVisited(bool isVisited) {
		this->isVisited = isVisited;
	}

	void setValue(int value) {
		this->value = value;
	}

};