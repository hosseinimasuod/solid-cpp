# SOLID Principles in C++

This repository demonstrates the SOLID principles of object-oriented design in C++.

## SOLID Principles Explained

### 1. Single Responsibility Principle (SRP)
- **Concept**: A class should have only one reason to change.
- **Example**: The `FileLogger` class handles only logging functionality.

### 2. Open/Closed Principle (OCP)
- **Concept**: Software entities should be open for extension but closed for modification.
- **Example**: The `Shape` base class allows adding new shapes without modifying existing code.

### 3. Liskov Substitution Principle (LSP)
- **Concept**: Objects of a superclass should be replaceable with objects of subclasses without breaking the application.
- **Example**: `printShapeArea()` works with any `Shape` subclass (Rectangle, Circle).

### 4. Interface Segregation Principle (ISP)
- **Concept**: Clients shouldn't be forced to depend on interfaces they don't use.
- **Example**: `Printable` and `Storable` are separate interfaces implemented by `Document`.

### 5. Dependency Inversion Principle (DIP)
- **Concept**: Depend on abstractions, not concretions.
- **Example**: `DataProcessor` depends on the `DataRepository` interface, not concrete implementations.

## Dependencies

This project requires a C++ compiler (e.g., g++) and standard C++ libraries.  No external libraries are strictly required for this specific example, as it relies on standard C++ features.  However, for more complex applications, you might consider using a build system like CMake to manage dependencies.

## Build Instructions

1.  **Clone the repository:**
    ```bash
    git clone git@github.com:hosseinimasuod/solid-cpp.git
    cd solid-cpp
    ```

2.  **Compile the code:**
    ```bash
    g++ -std=c++17 main.cpp -o solid_example
    ```

## Run the Code

```bash
./solid_example