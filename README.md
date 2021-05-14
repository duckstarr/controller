**controller**
====

A C++ library created for control systems, estimation and optimization in robotics. This library is equipped with various controllers and state estimators that is used to model dynamic systems and solve optimal control problems that arises in the field of robotics and automation.

**Requirements**
====

- Ubuntu 16.04 or 18.04
- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page#Download) C++ API

**Usage**
====

The repository provides use case examples for each tool that is designed for this project.

- [LQR Controller](https://github.com/duckstarr/controller/blob/master/src/lqr_controller/example/lqr.cpp)
- [PID Controller](https://github.com/duckstarr/controller/blob/master/src/pid_controller/example/pid.cpp)

**Importing controller to Workspace**
====

#### CMAKE 
```
# Find package.
find_package(controller REQUIRED)

# Build.
include_directories(
  ${controller_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  ${controller_LIBRARIES}
)
```

#### Include directories
```
#include "lqr_controller.h"
#include "pid_controller.h"
```

**Related Documentations**
====

- [Linear Quatratic Regulator](https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic_regulator)
- [Linear–quadratic–Gaussian control](https://en.wikipedia.org/wiki/Linear%E2%80%93quadratic%E2%80%93Gaussian_control)
- [Model predictive control](https://en.wikipedia.org/wiki/Model_predictive_control)
- [Kalman Filter](https://en.wikipedia.org/wiki/Kalman_filter)
- [Conjugate gradient method](https://en.wikipedia.org/wiki/Conjugate_gradient_method)
- [PID Controller](https://en.wikipedia.org/wiki/PID_controller)
- [Algebraic Riccati equation](https://en.wikipedia.org/wiki/Algebraic_Riccati_equation)