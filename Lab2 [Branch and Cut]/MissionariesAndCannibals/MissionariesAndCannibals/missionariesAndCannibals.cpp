#include <iostream>
#include <queue>

struct Node {

	Node* parent;
	int leftMissionaries, leftCannibals, rightMissionaries, rightCannibals;
	bool boatIsOnLeft;
	int cost;
	int level;

};

void printNode(Node* node) {

	for (int i = 0; i < node->leftMissionaries; i++)
		std::cout << "M ";
	
	for (int i = 0; i < node->leftCannibals; i++)
		std::cout << "C ";

	if (node->boatIsOnLeft)
		std::cout << "\\____/ ";

	std::cout << " ~~~~~~~~~~~~~~~~ ";

	if ( !(node->boatIsOnLeft) )
		std::cout << "\\____/ ";

	for (int i = 0; i < node->rightMissionaries; i++)
		std::cout << "M ";

	for (int i = 0; i < node->rightCannibals; i++)
		std::cout << "C ";

	std::cout << "\n\n";

}

Node* newNode(Node* parent, int leftMissionaries, int leftCannibals, int rightMissionaries, int rightCannibals, bool boatIsOnLeft, int level) {

	Node* node = new Node;

	node->parent = parent;

	node->leftCannibals = leftCannibals;
	node->leftMissionaries = leftMissionaries;
	node->rightCannibals = rightCannibals;
	node->rightMissionaries = rightMissionaries;
	
	node->boatIsOnLeft = boatIsOnLeft;

	node->level = level;

	return node;

}

bool isPossible(int moveMissionaries, int moveCannibals) {

	if (moveMissionaries + moveCannibals <= 2 && moveMissionaries + moveCannibals >= 1)
		return true;

	return false;

}

bool isSafe(int lm, int lc, int rm, int rc) {

	if ( lm >= lc && rm >= rc )
		return true;

	return false;
}

int calculateCost(Node* node) {

	return node->rightCannibals + node->rightMissionaries;

}

void printPath(Node* root) {

	if (root == NULL)
		return;

	printPath(root->parent);

	printNode(root);
	std::cout << "\n";

}

struct comp {

	bool operator()(const Node* lhs, const Node* rhs) const {

		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);

	}

};

int moveMissionaries[] = { 0, 1, 2 };
int moveCannibals[] = { 0, 1, 2 };

void solve(int numberOfMissionaries, int numberOfCannibals) {

	std::priority_queue<Node*, std::vector<Node*>, comp> pq;

	Node* root = newNode(NULL, numberOfMissionaries, numberOfCannibals, 0, 0, true, 0);

	root->cost = calculateCost(root);

	pq.push(root);

	while (!pq.empty()) {

		Node* min = pq.top();
		pq.pop();

		if (min->cost == 6) {
			printPath(min);
			return;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				if ( isPossible(moveMissionaries[i], moveCannibals[j]) ) {

					int lm = 0, lc = 0, rm = 0, rc = 0;

					if (min->boatIsOnLeft) {
						lm = min->leftMissionaries - moveMissionaries[i];
						lc = min->leftCannibals - moveCannibals[j];
						rm = min->rightMissionaries + moveMissionaries[i];
						rc = min->rightCannibals + moveCannibals[j];
					}
					else {
						lm = min->leftMissionaries + moveMissionaries[i];
						lc = min->leftCannibals + moveCannibals[j];
						rm = min->rightMissionaries - moveMissionaries[i];
						rc = min->rightCannibals - moveCannibals[j];
					}
					

					if ( isSafe(lm, lc, rm, rc) ) {

						Node* child = newNode(min, lm, lc, rm, rc, !min->boatIsOnLeft, min->level + 1);
						child->cost = calculateCost(child);
						printNode(min);
						pq.push(child);

					}

				}

			}
		}

	}

}

int main() {

	int lc = 3, lm = 3;

	std::cout << "Soluția:\n";
	solve(lc, lm);

	}