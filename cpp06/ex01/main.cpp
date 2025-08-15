#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    Data originalData;
    originalData.id = 42;
    
    Data* originalPtr = &originalData;
    
    uintptr_t serialized = Serializer::serialize(originalPtr);
    Data* deserializedPtr = Serializer::deserialize(serialized);
    
    std::cout << "=== TESTING SERIALIZATION ===" << std::endl;
    std::cout << "Original ptr:     " << originalPtr << std::endl;
    std::cout << "Serialized:       " << serialized << std::endl;
    std::cout << "Deserialized ptr: " << deserializedPtr << std::endl;
    std::cout << "Are equal? " << (originalPtr == deserializedPtr ? "YES" : "NO") << std::endl;
    
    if (originalPtr == deserializedPtr) {
        std::cout << "\n=== DATA VERIFICATION ===" << std::endl;
        std::cout << "Original data:     " << originalPtr->id << std::endl;
        std::cout << "Deserialized data: " << deserializedPtr->id << std::endl;
        std::cout << "Serialization successful!" << std::endl;
    } else {
        std::cout << "Serialization failed!" << std::endl;
    }
    
    return 0;
}