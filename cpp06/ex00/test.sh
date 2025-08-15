#!/bin/bash
# filepath: /home/arnau/42/cpps/cpp06/ex00/test.sh

echo "=== Testing ScalarConverter ==="
echo

# Compilar
make re
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

# Función para testear
test_case() {
    echo "Testing: $1"
    ./Converter "$1"
    echo "---"
}

echo "=== CHAR TESTS ==="
test_case "'a'"
test_case "'Z'"
test_case "'0'"

echo "=== INT TESTS ==="
test_case "0"
test_case "42"
test_case "-42"
test_case "127"

echo "=== FLOAT TESTS ==="
test_case "42.0f"
test_case "-4.2f"
test_case ".42f"
test_case "0.0f"
test_case "nanf"
test_case "+inff"
test_case "-inff"

echo "=== DOUBLE TESTS ==="
test_case "42.0"
test_case "-4.2"
test_case ".42"
test_case "nan"
test_case "+inf"
test_case "-inf"

echo "=== INVALID TESTS ==="
test_case "abc"
test_case "42."
test_case "'ab'"

echo "=== OVERFLOW TESTS ==="
test_case "2147483648"
test_case "-2147483649"

echo "=== Tests completed ==="