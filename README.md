# 🚀 **Proyectos CPP de 42: Mi aprendizaje**

Los proyectos **CPP00 a CPP09** forman el bloque de introducción y profundización en C++ en 42.  
Cada uno está diseñado para que practicar y consolidar los conceptos clave del lenguaje, desde la sintaxis básica hasta la programación orientada a objetos avanzada, plantillas y algoritmos.

---

## ✨ **Lo que aprendí en los proyectos CPP**

- 🧑‍💻 **Sintaxis y fundamentos de C++:** Aprendí a escribir, compilar y ejecutar programas en C++ desde cero.
- 🏗️ **Programación orientada a objetos (OOP):** Entendí cómo diseñar y estructurar programas usando clases y objetos.
- 🧩 **Herencia, polimorfismo y encapsulamiento:** Practiqué la creación de jerarquías de clases y el uso de métodos virtuales.
- 🛠️ **Sobrecarga de operadores y funciones:** Implementé operadores personalizados y funciones especializadas.
- 📚 **Plantillas, STL y algoritmos:** Utilicé plantillas para crear código genérico y aprendí a trabajar con los containers y algoritmos de la STL.
- 🔬 **Gestión de memoria y recursos:** Gestioné memoria dinámica y recursos de forma segura y eficiente.
- 🧵 **Excepciones y manejo de errores:** Aprendí a lanzar, capturar y manejar excepciones en C++.

---

## 📦 **Resumen de cada proyecto**

### **CPP00: Primeros pasos en C++**
- **Objetivo:** Familiarizarte con la sintaxis básica, funciones, entrada/salida y manipulación de cadenas.
- **Ejemplo:** Programa `megaphone` que transforma texto a mayúsculas.

### **CPP01: Clases, objetos y memoria**
- **Objetivo:** Aprender a crear clases, constructores, destructores y gestionar memoria dinámica.
- **Ejemplo:** Clases `Zombie`, creación de hordas y gestión de punteros.

### **CPP02: Sobrecarga y operadores**
- **Objetivo:** Implementar sobrecarga de operadores, métodos especiales y conversión de tipos.
- **Ejemplo:** Clase `Fixed` para números de punto fijo, operadores aritméticos y de comparación.

### **CPP03: Herencia y polimorfismo**
- **Objetivo:** Introducir la herencia, clases derivadas, métodos virtuales y polimorfismo.
- **Ejemplo:** Clases `ClapTrap`, `ScavTrap`, `FragTrap`, `DiamondTrap` con diferentes comportamientos.

### **CPP04: Herencia múltiple y abstracción**
- **Objetivo:** Profundizar en herencia múltiple, clases abstractas y gestión de recursos.
- **Ejemplo:** Clases `Animal`, `Dog`, `Cat`, `Brain`, uso de punteros y arrays de objetos.

### **CPP05: Excepciones y operadores avanzados**
- **Objetivo:** Manejar excepciones, operadores de asignación y clases con restricciones.
- **Ejemplo:** Clase `Bureaucrat`, gestión de rangos y excepciones personalizadas.

### **CPP06: Conversión de tipos y casting**
- **Objetivo:** Trabajar con conversiones, casting dinámico y tipos abstractos.
- **Ejemplo:** Clases `ScalarConverter`, `Serializer`, uso de punteros y referencias.

### **CPP07: Plantillas y containers**
- **Objetivo:** Aprender a usar plantillas, containers personalizados y el STL.
- **Ejemplo:** Clase `Array`, funciones `swap`, `min`, `max`, gestión de arrays genéricos.

### **CPP08: Algoritmos y STL**
- **Objetivo:** Profundizar en el uso de algoritmos estándar y containers STL.
- **Ejemplo:** Clases `Span`, `MutantStack`, búsqueda y manipulación de datos en containers.

### **CPP09: Algoritmos avanzados**
- **Objetivo:** Implementar algoritmos complejos y optimizados, manipulación de datos y estructuras.
- **Ejemplo:** Algoritmo Ford-Johnson (`PmergeMe`), cálculo de expresiones (`RPN`), gestión de datos (`ExchangeBitcoin`).

---

## 🏁 **¿Cómo compilar y ejecutar?**

Cada proyecto incluye su propio **Makefile**.  
Para compilar y ejecutar, entra en el directorio del ejercicio y ejecuta:

```sh
make
./<ejecutable>
```

---

## 🏁 **Mi evolución**

A lo largo de estos proyectos, he pasado de escribir programas simples a desarrollar soluciones orientadas a objetos, eficientes y robustas.  
He aprendido a:

- Utilizar correctamente la sintaxis y las herramientas de C++.
- Aplicar los principios de la programación orientada a objetos.
- Gestionar memoria y recursos de forma segura.
- Usar el STL y crear mis propios containers y algoritmos.
- Manejar excepciones y errores de manera profesional.
- Optimizar código y comprender algoritmos avanzados.

## 📁 **Estructura típica de los proyectos**

```
cpp00/
├── ex00/
│   ├── Makefile
│   ├── megaphone.cpp
│   └── ...
├── ex01/
│   └── ...
...
cpp09/
├── ex00/
│   ├── main.cpp
│   └── ...
├── ex01/
│   └── main.cpp
│   └── ...
├── ex02/
│   ├── main.cpp
│   ├── PmergeMe.cpp
│   ├── PmergeMe.hpp
│   └── ...
```