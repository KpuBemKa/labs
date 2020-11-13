#include <iostream>
#include <queue>
#define n 3

// structura care descrie un oarecare nod
class Node {

public:
    // părintele nodului
    Node* parent;

    // nivelul nodului
    int nodeLevel;

    // coordinatele placei fără număr
    int x, y;

    // matricea pazlului
    int puzzleMatrix[n][n];

    // numărul de plăci, care nu sunt la locul potrivit
    int cost;

    Node(Node* parent, int puzzleMatrix[n][n], int x, int y, int newX, int newY, int nodeLevel) {

        // crearea pointerului spre părintele nodului 
        this->parent = parent;

        // copierea datelor din părintele nodului în nodul curent
        memcpy(this->puzzleMatrix, puzzleMatrix, sizeof(this->puzzleMatrix));

        // schimbarea a două plăci
        std::swap(this->puzzleMatrix[x][y], this->puzzleMatrix[newX][newY]);

        // set number of misplaced tiles
        this->cost = INT_MAX;

        // set number of moves so far 
        this->nodeLevel = nodeLevel;

        // update new blank tile cordinates 
        this->x = newX;
        this->y = newY;

    }

};

// funcția care afișează o matrice
void printMatrix(int mat[n][n]) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << mat[i][j] << " ";
        std::cout << "\n";
    }

}

// jos, stânga, sus, dreapta
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// funcția care calculează numărul de plăci, care nu sunt în poziția potrivită
int calculateCost(int initial[n][n], int final[n][n])
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                ++count;

    return count;
}

// funcția care verifică dacă punctul (x, y) este valid
int isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

// afișează drumul de la rădăcină spre nodul de destinație
void pathFromRootNode(Node* root)
{
    if (root == NULL)
        return;

    pathFromRootNode(root->parent);
    printMatrix(root->puzzleMatrix);

    std::cout << "\n";
}

// structura pentru compararea nodurilor
struct compare
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->nodeLevel) > (rhs->cost + rhs->nodeLevel);
    }
};

// funcția care rezolvă pazlul 
void solve(int initial[n][n], int x, int y, int final[n][n])
{
    // lista care va stoca nodurile
    // lista priority_queue stochează elementele cu valoarea mai mare la început,
    // folosing compararea declarată mai sus
    std::priority_queue<Node*, std::vector<Node*>, compare> pq;

    // crearea unui nod nou și calcularea costului lui 
    Node* root = new Node(NULL, initial, x, y, x, y, 0);
    root->cost = calculateCost(initial, final);

    // adăugarea nodului în listă 
    pq.push(root);

    //preia nodul cu valoarea costului cea mai mică, îl adaugă în arbore și îl șterge din listă
    while (!pq.empty())
    {
        //nodul cu valoarea minimă
        Node* min = pq.top();

        // ștergerea nodului găsit din listă
        pq.pop();

        // dacă nodul găsit este cel corect
        if (min->cost == 0)
        {
            // afișăm drumul de la rădăcină spre el 
            pathFromRootNode(min);
            return;
        }

        // crearea copiilor  
        for (int i = 0; i < 4; i++)
        {
            // verificarea dacă valorile sunt valide
            if (isValid(min->x + row[i], min->y + col[i]))
            {
                // crearea unui nod nou și calcularea costului lui
                Node* child = new Node(min, min->puzzleMatrix, min->x,
                    min->y, min->x + row[i],
                    min->y + col[i],
                    min->nodeLevel + 1);
                child->cost = calculateCost(child->puzzleMatrix, final);

                // adăugarea nodului în listă 
                pq.push(child);
            }
        }
    }
}