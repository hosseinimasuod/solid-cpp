#include <iostream>
#include <fstream>
#include <string>
#include <memory> // For std::unique_ptr

// Define PI
#define PI 3.14159265358979323846  

// Single Responsibility Principle (SRP)
class FileLogger {
public:
    void log(const std::string& message) {
        std::ofstream logFile("application.log", std::ios::app);
        if (logFile.is_open()) {
            logFile << message << std::endl;
            logFile.close();
        } else {
            std::cerr << "Error: Could not open log file." << std::endl;
        }
    }
};

// Open/Closed Principle (OCP)
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default; // Important for polymorphism
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override { return width * height; }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea() const override { return PI * radius * radius; } // Use PI
};

// Liskov Substitution Principle (LSP)
void printShapeArea(const Shape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
}

// Interface Segregation Principle (ISP)  - Using abstract classes
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class Storable {
public:
    virtual void store() const = 0;
    virtual ~Storable() = default;
};

class Document : public Printable, public Storable {
public:
    void print() const override {  // Correct override
        std::cout << "Printing document..." << std::endl;
    }
    void store() const override { // Correct override
        std::cout << "Storing document..." << std::endl;
    }
};

// Dependency Inversion Principle (DIP)
class DataRepository {
public:
    virtual void save(const std::string& data) = 0;
    virtual std::string load() const = 0;
    virtual ~DataRepository() = default;
};

class FileDataRepository : public DataRepository {
public:
    void save(const std::string& data) override {
        std::ofstream file("data.txt");
        if (file.is_open()) {
            file << data;
            file.close();
        }
    }
    std::string load() const override {
        std::ifstream file("data.txt");
        std::string data;
        if (file.is_open()) {
            std::getline(file, data);
            file.close();
        }
        return data;
    }
};

class DataProcessor {
private:
    DataRepository& repository;

public:
    DataProcessor(DataRepository& repo) : repository(repo) {}

    void processAndSave(const std::string& data) {
        std::string processedData = data + " (processed)";
        repository.save(processedData);
    }
};

int main() {
    FileLogger logger;
    logger.log("Application started.");

    Rectangle rect(5, 10);
    Circle circ(7);

    printShapeArea(rect);
    printShapeArea(circ);

    std::unique_ptr<DataRepository> fileRepo = std::make_unique<FileDataRepository>();
    DataProcessor processor(*fileRepo);
    processor.processAndSave("Initial data");

    Document doc;
    doc.print();
    doc.store();

    return 0;
}