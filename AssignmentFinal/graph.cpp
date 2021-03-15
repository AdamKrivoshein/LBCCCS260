#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Graph {
    private:
        //https://stackoverflow.com/questions/16001803/pointer-to-pointer-dynamic-two-dimensional-array
        int **matrix;
        int matrixSize = 4;
        int graphSize = 0;

    public:
        Graph() {
            //Setting up the 2d array matrix
            matrix = new int*[matrixSize];

            for (int row = 0; row < matrixSize; row++) {
                matrix[row] = new int[matrixSize];
                //Initializing matrix values
                for (int col = 0; col < matrixSize; col++)
                    matrix[row][col] = 0;
            }
        }

        void addVertex() {
            if (graphSize < matrixSize)
                graphSize++;
            else {
                expandMatrix();
                graphSize++;
            }
        }

        void addEdge(int source, int destination, int length) {
            matrix[source][destination] = length;
        }

        void expandMatrix() {
            //Initializing new matrix
            int **newMatrix = new int*[matrixSize * 2];

            for (int row = 0; row < (matrixSize * 2); row++) {
                newMatrix[row] = new int[matrixSize * 2];
                //Initializing matrix values
                for (int col = 0; col < (matrixSize * 2); col++)
                    newMatrix[row][col] = 0;
            }

            //Transfering matrix data
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++)
                    newMatrix[row][col] = matrix[row][col];
            }

            //Freeing old matrix memory
            for (int row = 0; row < matrixSize; row++)
                free(matrix[row]);
            free(matrix);

            //Transfering data
            matrix = newMatrix;
            matrixSize = matrixSize * 2;
        }

        //For debug purposes
        void displayMatrix() {
            cout << endl;
            for (int row = 0; row < matrixSize; row++) {
                for (int col = 0; col < matrixSize; col++)
                    cout << " " << matrix[row][col];
                //Line break for each row
                cout << endl;
            }
            cout << endl;
        }

        void deleteGraph() {
            for (int row = 0; row < matrixSize; row++)
                free(matrix[row]);
            free(matrix);
        }
};