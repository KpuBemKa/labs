#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#define n 4 

namespace atp {

    // matricea care conține prețurile
    int costMatrix[n][n];
 
    class Node {

    public:
        // părintele nodului 
        Node* parent;

        // conține costul tuturor nodurilor, inclusiv acest
        int pathCost = 0;

        // conține cel mai mic cost
        int cost = 0;

        // numărul lucrătorului
        int workerID = 0;

        // numărului jobului
        int jobID = 0;
 
        // conține informația despre joburile avalabile
        bool assigned[n];

        //constructorul clasei
        Node(int workerID, int jobID, bool assigned[], Node* parent) {

            for (int j = 0; j < n; j++)
                this->assigned[j] = assigned[j];

            this->assigned[jobID] = true;
            this->parent = parent;
            this->workerID;
            this->jobID;

        }

    };

    // citirea datelor din fișier
    void readData() {

        std::ifstream file;
        file.open("in.txt");

        if (file.is_open()) {

            for (int i = 0; i < n; i++) {
                file >> costMatrix[i][0] >> costMatrix[i][1] >> costMatrix[i][2] >> costMatrix[i][3];
            }

        }

        file.close();

    }

    // afișarea datelor pe ecran și în fișier
    void printAssignments(Node* node)
    {
        // dacă se ajunge până la sfârșit
        if (node->parent == NULL)
            // se iese din funcție
            return;

        // apelarea recursivității
        printAssignments(node->parent);

        // deschiderea fișierului
        std::ofstream file("out.txt", std::ios_base::app);

        // afișarea pe ecran un rând
        std::cout << "Lucrătorul " << char(node->workerID + 'A') << " va avea jobul " << node->jobID << "\n";
        // înscrierea în fișier un rând
        file << "Lucrătorul " << char(node->workerID + 'A') << " va avea jobul " << node->jobID << "\n";

    }

    int calculateCost(int costtMatrix[n][n], int x,
        int y, bool assigned[])
    {
        int cost = 0;

        // to store unavailable jobs 
        bool available[n] = { true };

        // start from next worker 
        for (int i = x + 1; i < n; i++)
        {
            int min = INT_MAX, minIndex = -1;

            // do for each job 
            for (int j = 0; j < n; j++)
            {
                // if job is unassigned 
                if (!assigned[j] && available[j] &&
                    costtMatrix[i][j] < min)
                {
                    std::cout << "\nentered\n";
                    // store job number 
                    minIndex = j;

                    // store cost 
                    min = costMatrix[i][j];
                }
            }

            // add cost of next worker 
            cost += min;
            
            if(minIndex >= 0)
                // job becomes unavailable 
                available[minIndex] = false;
        }

        return cost;
    }

    // structură pentru comparare, care se va folosi mai apoi
    struct compare {
        bool operator()(const Node* lhs, const Node* rhs) const
        {
            return lhs->cost > rhs->cost;
        }
    };

    // găsirea costului minimal
    int findMinCost()
    {
        // crearea listei priority_queue, unde elementul cu valoarea cea mai mare este stocat la încep 
        std::priority_queue<Node*, std::vector<Node*>, compare> pq;

        // inițializarea cu un nod fals
        bool assigned[n] = { false };
        Node* root = new Node(-1, -1, assigned, NULL);
        root->pathCost = root->cost = 0;
        root->workerID = -1;

        // adăugarea nodului în listă 
        pq.push(root);

        // găsește nodul cu cel mai mic cost,
        // adăugă copii lui în listă
        // și îl șterge din listă
        while (!pq.empty())
        {
            // găsirea nodului cu cel mai mic cost estimat
            Node* min = pq.top();

            // nodul găsit este șters din listă
            pq.pop();

            // variabila ”i” stochează următorul lucrător
            int i = min->workerID + 1;

            // dacă toți lucrătorii au primit jobul
            if (i == n)
            {
                // afișează toți lucrătorii
                printAssignments(min);
                return min->cost;
            }

            // efectuarea pentru fiecare job
            for (int j = 0; j < n; j++)
            {
                // dacă este neangajat
                if (!min->assigned[j])
                {
                    // crează un nou nod 
                    Node* child = new Node(i, j, min->assigned, min);

                    // costul predecesorilor, inclusiv acest nod
                    child->pathCost = min->pathCost + costMatrix[i][j];

                    // calcularea costului cel mai mic
                    child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);

                    // adăugarea nodului în listă
                    pq.push(child);
                }
            }
        }
    }

}