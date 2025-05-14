# cpp_template

A modern C++ project template using CMake, Catch2 for unit testing, and support for FetchContent-based dependencies (like `quant_config`). Designed for educational and quantitative finance projects.

---

## 🔧 Using This Template (Executable Mode)

### ▶️ Running the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/PaxtonTerryDev/cpp_template.git
   cd cpp_template
   ```

2. Create a build directory:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the binary:
   ```bash
   ./cpp_template
   ```

### 🧪 Running Tests

Tests are written using Catch2 and live in the `tests/` directory.

To run:
```bash
./unit_tests
```

---

## 📦 Project Layout

```
cpp_template/
├── CMakeLists.txt        # Main CMake configuration
├── include/              # Public headers
│   └── my_project/       # Example project namespace
├── src/                  # Implementation files
├── tests/                # Catch2 unit tests
├── main.cpp              # Entry point (for executable mode)
```

---

## 🧱 Switching to a Library Project

If you'd like to turn this project into a **reusable library**, make the following changes:

### 1. Replace the `add_executable` block:
```cmake
add_library(cpp_template_lib
    src/my_project/test_class.cpp
    include/my_project/test_class.h
)

target_include_directories(cpp_template_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
```

### 2. (Optional) Add a separate demo executable:
```cmake
add_executable(demo main.cpp)
target_link_libraries(demo PRIVATE cpp_template_lib)
```

### 3. Update tests to link against the library:
```cmake
target_link_libraries(unit_tests PRIVATE cpp_template_lib Catch2::Catch2WithMain)
```

Now `cpp_template` acts as a reusable module you can import into larger quant projects.

---

## 🧠 Tip

If you're using your personal `quant-config` library, be sure to:

```cmake
FetchContent_Declare(
  quant_config
  GIT_REPOSITORY https://github.com/PaxtonTerryDev/quant-config
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(quant_config)

target_link_libraries(cpp_template_lib PUBLIC quant_config)
```

---

## 📚 Part of the [Quantitative Developer Roadmap](quant_roadmap.md)

This project supports long-term modular development of quant libraries like:

- Numerical Methods
- Matrix Algebra
- Brownian Motion
- Monte Carlo Pricing
- Backtesting Engines
