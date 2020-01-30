#include "MyParallelServer.h"
#include "Matrix.h"
#include "State.h"
#include "ObjectAdapter.h"
#include <vector>
#include "BFS.h"
#include "Searchable.h"
#include "AStar.h"
#include "DFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"

int main(int size, char *args[]) {
  boot::Main::main(size, args);
  /*

  int myMat[37][37] =
      {8, 2, 8, 6, 8, 2, 12, 2, 4, 1, 9, 9, 5, 12, 1, 1, 1, 2, 7, 3, 1, 6, 9, 3, 9, 7, 7, 9, 5, 6, 4, 5, 1, 6, -1, 1, 7,
       {4, 12, 2, 3, 2, 5, 2, 1, 12, 2, 4, 5, 4, 3, 3, 4, 12, 2, 3, 9, 6, 9, 1, 6, 7, 7, 5, 8, 7, 2, -1, 3, 2, 5, -1, 9,
        2},
       {1, 5, 8, 9, 2, 1, 2, 4, 7, 8, 2, 9, 8, 4, 2, 2, 12, 8, 8, 2, 3, 3, 1, 5, 12, -1, 2, 7, 1, 4, -1, -1, -1, 2, -1,
        5, 6},
       {8, 6, 2, 4, 12, 8, 9, 9, 7, 1, 2, 8, 8, 2, 4, 2, 1, 7, 6, 8, 3, -1, 8, 1, 8, 6, 1, 3, 3, 2, 7, 3, 4, 2, 9, 12,
        2},
       {7, 6, 2, 12, 7, 8, 1, -1, 5, 8, 8, 1, 1, 5, 8, 9, 9, 1, 8, 5, 1, 8, 4, 5, 4, 5, 8, 7, 6, 6, 8, 2, 2, 8, 8, 8,
        8},
       {9, 3, 2, 3, 5, 12, -1, 9, 2, 8, 3, 8, 2, 12, 12, 7, 1, 8, 4, 2, 12, 5, 4, 7, 4, 4, 6, 12, 9, 2, 3, 5, 12, 2, 2,
        3, 5},
       {12, 5, 1, 7, 5, 12, 6, 6, 6, 5, 8, 9, 4, 3, 9, 2, 12, 4, 9, 5, 3, 12, 3, 9, 3, 4, -1, 8, 5, 2, 12, 5, 2, 3, 7,
        6, -1},
       {1, 12, 2, 9, 9, 1, 2, 2, -1, 2, 6, 12, 1, 12, 12, 2, 7, 5, 2, 7, 7, 6, 9, 2, 3, 2, 4, 9, -1, 5, 7, -1, 9, 8, 6,
        3, 4},
       {12, 2, 1, 2, 6, 12, 2, 6, -1, -1, 3, 9, 9, 8, 3, 7, 4, 3, 4, 5, -1, 9, 3, 5, 12, 2, 3, -1, 12, 2, 2, 2, 7, 8,
        -1, 12, 2},
       {7, 4, 8, 2, 8, 7, -1, 3, -1, 2, -1, 7, 9, 6, 7, 6, 1, 12, 6, 2, 5, 8, 1, 2, 8, 3, 2, 12, 7, 12, 1, 2, 6, 9, 7,
        3, 8},
       {6, 2, 4, 7, 7, 12, 8, 2, 1, 6, 2, 6, 4, 6, 6, 7, 5, 5, 8, 2, 12, 2, 6, 8, 12, 8, 12, 9, 9, 2, 2, 2, 9, 6, 5, 4,
        2},
       {7, 2, 9, 4, 7, 4, 5, 8, 2, 2, 4, 3, 6, 1, 4, 7, 4, 9, -1, 5, 12, 3, 4, 9, 7, 12, 3, 5, 2, 9, 7, 2, -1, 5, 12, 7,
        1},
       {6, 6, 8, 2, 12, 4, -1, 4, -1, 2, 9, 6, 5, 7, 2, 4, 9, 12, 4, 9, 2, 9, 2, 6, 7, 1, 12, 5, 6, 6, 5, 12, 4, 5, 7,
        6, 8},
       {3, 9, 1, 4, 8, 2, -1, 2, -1, 7, 8, 3, 6, 6, 9, 4, 6, -1, 4, -1, 1, 4, 5, 9, 2, 2, 1, 9, 3, 7, 2, 1, 12, 5, 6,
        -1, 9},
       {12, 8, 9, 1, 12, 7, 2, 12, 9, 12, 12, 1, 9, 3, 7, 5, 9, 3, 8, 6, 6, 7, 1, 1, 5, 6, 2, 7, 2, 3, 4, 9, 9, 9, 12,
        2, 8},
       {12, 2, 8, 5, -1, 2, 5, 8, 7, 2, 5, 1, 3, 2, 4, 3, 9, 5, 9, 7, 7, 2, -1, 2, 8, 4, 1, 5, 9, 6, 2, 4, 2, 9, 1, -1,
        2},
       {4, 4, 5, 12, 2, 5, 2, 3, 2, 2, 2, 4, 5, 3, 12, 9, 3, 6, 2, 9, 9, 1, 4, 3, 2, 12, 3, 1, 8, 6, 7, 4, 6, 7, 5, 1,
        8},
       {4, -1, 9, 7, 5, 5, 3, 12, 8, 3, 3, 9, 5, 6, 1, 12, 7, 4, 9, 9, 5, 9, 8, 9, 9, 1, 6, 9, 7, 5, 3, 5, 4, 6, 3, 2,
        1},
       {9, 2, 1, 5, 1, 3, 8, 2, 1, 2, 5, 2, 9, 9, 3, 4, 2, 2, 2, 12, 7, 2, 12, 3, 7, 2, 8, 9, 2, 1, 2, 2, 2, 3, 4, 12,
        3},
       {6, 6, 1, -1, 12, 7, 1, 5, 2, 3, 5, 8, 12, 7, 3, 2, 6, 8, 5, 1, 12, 2, 6, 6, 8, 2, 7, -1, 2, 7, 9, 5, 5, 7, 1, 5,
        4},
       {3, 6, 4, 12, 7, 8, 2, 9, 8, 3, 4, 3, 8, 7, 6, 6, 2, 7, 9, 6, 6, 2, 2, 6, 5, 9, 2, 3, 3, 3, 12, 7, 12, 6, 7, 2,
        9},
       {12, 1, 2, -1, 7, 2, 5, 12, 2, 8, 4, 7, 8, 7, 7, 5, 2, 5, 7, 4, 2, 4, 3, 12, 6, 8, 5, 2, 1, 4, 9, 2, 1, 4, 2, 2,
        2},
       {12, 4, 9, 12, 9, 12, 9, 12, 7, 9, 2, 1, 6, 5, 3, 2, 6, 4, 7, 9, 12, 4, 4, 9, 8, 1, 7, 8, 2, 2, 9, 3, 8, 5, 3, 7,
        6},
       {7, 4, 6, 2, 7, 7, 8, 6, 8, 9, 1, 2, 9, 3, 4, 9, 2, 8, 12, 1, 2, 5, 9, 8, 7, 9, 3, 3, 12, 7, 9, 8, 3, 2, 12, 3,
        6},
       {9, 2, 1, 8, 4, 8, 1, 8, 6, 2, 3, 9, 1, 7, 3, 8, 5, 8, 5, 4, 4, 12, 5, 2, 9, 2, 1, 9, 2, 6, 8, 4, 4, -1, -1, -1,
        12},
       {7, 7, 2, 8, 4, 4, 1, 9, 8, 2, 9, 8, 12, 5, 5, 2, 8, 1, 5, 9, 9, 12, 6, 5, 9, 8, 1, 4, 4, 7, 6, 12, 4, 9, 1, 8,
        2},
       {1, 6, 7, 2, 8, 7, 6, 12, 1, 2, 9, 5, 12, 7, 6, 4, 9, 2, 2, 5, 1, 9, 2, 1, 6, 8, 3, 2, 8, 1, 2, 6, 9, 8, 3, -1,
        2},
       {5, 5, 7, 12, 1, 8, 4, 4, 2, 12, 12, 1, 1, 2, 8, 4, 8, 2, 6, 8, 3, 8, 5, 5, 3, 8, 12, 8, 5, 12, 1, 12, 2, 5, 2,
        -1, 6},
       {9, 2, 8, 1, 3, 5, 6, 2, 7, 9, 2, 1, 6, 8, 1, 2, 1, 5, 2, 2, 12, 2, 4, 9, 2, 2, 4, 7, 4, 3, 6, 9, 6, 5, 12, 2,
        3},
       {1, 7, 2, 2, 5, 6, 12, 6, 6, 12, 12, 2, 1, 2, 2, 7, 1, 1, 8, 3, 5, 2, 12, 1, 8, 2, 6, 3, 2, 9, 3, 2, 4, 9, 8, 5,
        3},
       {1, 3, 2, 1, 1, 6, 3, -1, 2, 4, 8, 7, 3, 4, 7, 6, 1, 9, 7, 2, 12, 4, 6, 5, 7, 8, 2, 12, 1, 2, 6, 7, 8, 2, 3, 12,
        9},
       {3, 6, 4, 9, 2, 12, 9, 8, 2, 7, 6, 6, 8, 3, 7, 9, 3, 7, 2, 2, 3, 2, 4, 5, 8, 7, 2, 12, 12, 4, 12, 2, 12, -1, 6,
        -1, 2},
       {6, 4, 4, 12, 8, 3, 2, 7, 3, 8, 4, 7, 3, 1, 5, 6, 2, 2, 2, 6, 2, 1, 4, 3, 1, 4, 2, 5, 7, 1, 6, 5, 12, 7, 5, -1,
        3},
       {4, 8, 2, 2, 12, 9, 3, 3, 8, 7, 7, 8, 12, 6, 12, 2, 4, 12, 2, 12, 7, 8, 7, 1, 9, 5, 12, 4, 2, 2, 9, 7, 1, 8, 3,
        8, 9},
       {2, 2, 5, 1, 7, 1, 8, 2, 12, 3, 12, 5, 7, 9, 12, 12, 12, 2, 4, 4, 2, 12, 2, 2, 1, 6, 9, 12, 7, 4, 6, 12, 8, 4, 8,
        2, 12},
       {3, 1, 2, 8, 1, 4, 7, 9, 3, 7, 3, 6, 6, 6, 3, 9, 9, 3, 9, 3, 3, 7, 5, 12, 2, 8, 2, 2, 5, 4, 9, 8, 5, 3, 2, 6, 4},
       {12, 1, 9, 5, 9, 2, 6, 12, 3, 4, 12, -1, 12, 7, 9, 2, 1, 2, 2, 4, 6, 12, 2, 2, 2, 3, 4, 1, 4, 4, 2, 4, 12, 6, 2,
        5, 6}};
  std::vector<int> cell1{0, 0};
  std::vector<int> cell2{36, 36};
  auto *initialState = new State<std::vector<int>>(&cell1, 8);
  auto *goalState = new State<std::vector<int>>(&cell2, 6);
  auto matrix = new Matrix(37, initialState, goalState);
  int rows = 37, columns = 37;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      auto *cell = new std::vector<int>{i, j};
      matrix->addCell(new State<std::vector<int>>(cell, myMat[i][j]));
    }
  }

  auto a_star = new AStar<std::vector<int>>();
  auto b_firstsearch = new BestFirstSearch<std::vector<int>>();
  auto bfs = new BFS<std::vector<int>>();
  auto dfs = new DFS<std::vector<int>>();
  auto ob_a = new ::ObjectAdapter<std::vector<int>>(a_star);
  auto ob_b = new ::ObjectAdapter<std::vector<int>>(b_firstsearch);
  auto ob_c = new ::ObjectAdapter<std::vector<int>>(bfs);
  auto ob_d = new ::ObjectAdapter<std::vector<int>>(dfs);
  std::cout << "------>A*<------\n" << ob_a->solve(matrix) << std::endl;
  std::cout << "------>BEST FIRST SEARCH<------\n" << ob_b->solve(matrix) << std::endl;
  std::cout << "------>BFS<------\n" << ob_c->solve(matrix) << std::endl;
  std::cout << "------>DFS<------\n" << ob_d->solve(matrix) << std::endl;
   */
  return 0;
}

