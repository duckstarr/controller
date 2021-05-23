[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**controller**
====

A C++ library created for control systems, estimation and optimization in robotics. This library is equipped with various controllers and state estimators that is used to model dynamic systems and solve optimal control problems that arises in the field of robotics and automation.

**Requirements**
====

- [C++17](https://en.cppreference.com/w/cpp/17)
- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download) C++ API

**Installing 'controller' Package**
====

#### CMAKE Install
```
mkdir build
cd build
cmake ..
cmake --build . --target install
```

**TODO**
====
- Implement global planning algorithms (i.e., RRT*, A*).
- Dockerize & make ROS compatible.
- CI/CD
- Open to suggestions.

**Related Wiki**
====

- [Linear Quatratic Regulator](https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic_regulator)
- [Linear–quadratic–Gaussian control](https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic%E2%80%93Gaussian_control)
- [Model predictive control](https://en.wikipedia.org/wiki/Model_predictive_control)
- [PID Controller](https://en.wikipedia.org/wiki/PID_controller)
- [Algebraic Riccati equation](https://en.wikipedia.org/wiki/Algebraic_Riccati_equation)
- [Signal Processing](https://en.wikipedia.org/wiki/Filter_(signal_processing))
- [Dijkstra's Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)
- [Depth-first Search](https://en.wikipedia.org/wiki/Depth-first_search#:~:text=Depth%2Dfirst%20search%20(DFS),along%20each%20branch%20before%20backtracking.)