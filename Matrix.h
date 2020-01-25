
#ifndef MATRIX_H_
#define MATRIX_H_
#include "Searchable.h"
#include <vector>

class Matrix : public Searchable<std::vector<int>> {
 public:
  Matrix(int testMat[5][5]);
  Matrix(int size, State<std::vector<int>> *initial_state, State<std::vector<int>> *goal_state);
  void addCell(State<std::vector<int>> *state);
  State<std::vector<int>>* getInitialState() override;
  void setGoalState(State<std::vector<int>>* state);
  void setInitialState(State<std::vector<int>>* state);
  bool isGoalState(State<std::vector<int>>* curState) override;
  std::vector<State<std::vector<int>>> getAllPossibleStates(State<std::vector<int>>* curState) override;
 private:
  int size;
  State<std::vector<int>>* initialState;
  State<std::vector<int>>* goalState;
  State<std::vector<int>>** matrix;
  bool validateCell(int row, int column);
};

#endif //MATRIX_H_
