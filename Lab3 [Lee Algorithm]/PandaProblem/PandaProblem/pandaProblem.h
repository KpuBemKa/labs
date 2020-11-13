#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include "pos.h"
#define DMAX 20

namespace pnd {

	std::vector<Pos> cords;
	std::queue<Pos> q;

	int originalMat[DMAX][DMAX];
	int mat[DMAX][DMAX];
	int m, n, cagesWent = 0;

	const int addLin[] = { -1, 0, 1, 0 };
	const int addCol[] = { 0, 1, 0, -1 };

	void countAccesibleCages() {

		std::ofstream file("out.txt");
		int count = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (originalMat[i][j] == 0)
					++count;
			}
		}

		file << "Numarul de custi accesibile: " << count << "\n";

	}

	void showSecondsNeeded() {

		std::ofstream file("out.txt", std::ios_base::app);

		file << "Timpul necesar pentru parcurgerea custelor: " << cagesWent << " de secunde.";

	}

	void readFile() {

		std::ifstream file("in.txt");

		int a, b, code;

		while (file.is_open()) {

			file >> m >> n;

			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {

					file >> code;

					if (code == 11)
						originalMat[i][j] = 0;
					else
						originalMat[i][j] = -1;

				}
			}

			m += 1;
			n += 1;

			for (int i = 0; i <= m; i++) {
				originalMat[0][i] = -1;
				originalMat[n][i] = -1;
			}
			for (int i = 1; i < n; i++) {
				originalMat[i][0] = -1;
				originalMat[i][m] = -1;
			}

			file >> a >> b;
			Pos pos = Pos(a + 1, b + 1);
			cords.push_back(pos);

			int numberOfCagesWithFood;
			file >> numberOfCagesWithFood;
			for (int i = 0; i < numberOfCagesWithFood; i++) {

				file >> a >> b;
				Pos pos = Pos(a + 1, b + 1);
				cords.push_back(pos);

			}

			file.close();
			
		}
		
	}

	void updateMat() {

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				mat[i][j] = originalMat[i][j];
			}
		}

	}

	void showPath(Pos pos1, Pos pos2) {

		std::ofstream file("out.txt", std::ios_base::app);

		if (pos2.line == pos1.line && pos2.column == pos1.column) {
			file << pos2.column << " " << pos2.line << "\n";
			return;
		}
		
		for (int k = 0; k < 4; k++) {

			Pos ngh = Pos(pos2.line + addLin[k], pos2.column + addCol[k]);

			if (mat[ngh.line][ngh.column] == mat[pos2.line][pos2.column] - 1) {
				showPath(pos2, ngh);
				file << pos2.line << " " << pos2.column << "\n";
				cagesWent++;
				return;
			}

		}

	}

	void lee() {

		countAccesibleCages();

		for (size_t i = 0; i < cords.size()-1; i++) {

			updateMat();

			Pos a = cords[i];
			Pos b = cords[i + 1];

			q.push(a);
			mat[a.line][a.column] = 1;

			while (!q.empty() && !mat[b.line][b.column]) {

				Pos pos = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {

					Pos ngh = Pos(pos.line + addLin[k], pos.column + addCol[k]);

					if (!mat[ngh.line][ngh.column]) {

						mat[ngh.line][ngh.column] = mat[pos.line][pos.column] + 1;
						q.push(ngh);

					}

					if (ngh.line == b.line && ngh.column == b.column) {

						showPath(a, b);

					}
					
				}

			}

		}

		showSecondsNeeded();

	}

}