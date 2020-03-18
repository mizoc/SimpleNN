/*
 * Author:mizoc<yaesuft729@gmail.com>
 * License:MIT
 * Simplest Neural Network in C++
*/

#include <time.h>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <random>
using namespace std;

inline double sigmoid(double x) { return 1 / (1 + exp(-x)); }
inline double sigmoid_diff(double x) { return sigmoid(x) * (1 - sigmoid(x)); }
double forward(double*, double*);

int main() {
  int epoch = 10000;
  double lr = 0.01;
  int i, l, k;
  double w[3], y, error;
  double train_x[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  double train_y[3] = {0, 0.4, 1};

  cout << "w=";
  for (i = 0; i < 3; i++) {
    // srand((unsigned int)time(NULL));
    w[i] = (double)rand() / RAND_MAX;
    cout << w[i] << " ";
  }
  cout << endl;

  cout << "====Before Learning====" << endl;
    for (i = 0; i < 3; i++) {
      cout << "predict: " << forward(train_x[i], w)
           << " ,correct: " << train_y[i] << endl;
    }

  for (k = 0; k < epoch; k++) {
    for (i = 0; i < 3; i++) {
      y = forward(train_x[i], w);
      for (l = 0; l < 3; l++) {
        // cout << w[l] << endl;
        error = y - train_y[i];
        w[l] -= lr * error * sigmoid_diff(train_x[i][l]) * train_x[i][l];
      }
    }
  }

  cout << "====After Learning====" << endl;
  for (i = 0; i < 3; i++) {
    cout << "predict: " << forward(train_x[i], w) << " ,correct: " << train_y[i]
         << endl;
  }

  return 0;
}

double forward(double* px, double* pw) {
  double u = 0;
  for (auto k = 0; k < 3; k++) {
    u += px[k] * pw[k];
  }
  return sigmoid(u);
}
