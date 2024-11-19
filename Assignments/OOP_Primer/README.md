## A04

- Name: Dominique Hawkins
- Date: 06 Dec. 2024
- Class: 2143 OOP

# Abstract Classes and Interfaces

### Definition

# Abstraction

### Definition
It is the process of hiding or abstracting away complex details of a system or
software component to make it easier to use and understand. One common form is data abstraction,
which involves creating abstract data types that encapsulate data and related operations, and hiding the implementation details from the user.

# Access Modifiers (Public, Private, Protected)

### Definition

# Attributes/Properties

### Definition
Attributes, or properties, are defined as part of a class and are used to represent the state or characteristics of an object.

# Class Variable

## Definition
A class variable, also known as a static data member, is a variable that is shared
among all instances or objects of a class. Unlike instance variables,
which have a separate copy for each object, a class variable has only one copy that is shared by all objects of the class.

# Classes and Objects

### Definition
A class is a user-defined data type that encapsulates data and functions into 
a single unit. An object is an instance of a class that encapsulates data and behaviors related to that data.

# Collections and Iterators

### Definition

# Composition

### Definition
composition is a design technique where a class contains one or more
objects of other classes as member variables. This means that the class "composes" or is made up of other classes.

# Constructors and Destructors

### Definition
A constructor is a special method that is automatically called when an object of a class is created.
They have the same name as the class and are defined within the class.
They do not have a return type and cannot be called directly like regular methods.
A destructor is to clean up any resources that the object may have allocated during its lifetime.
The destructor for a class is automatically called when the object is destroyed or goes out of scope. Its syntax is 
represented by a (~).

# Design Patterns (e.g., Singleton, Factory, Observer)

### Definition

# Encapsulation

### Definition
An object-oriented programming concept that refers to the ability of an object to hide its
internal state, data, and implementation details from other objects.

# Exception Handling

### Definition

# File I/O in OOP

### Definition

# Friends

### Definition
A friend class can access private and protected members of other classes in which it is declared as a friend. 
To declare a class as a friend of another class, the friend keyword is used in the class declaration of the class that is being granted access.

# Generics and Templates

### Definition

# Inheritance

### Definition
Inheritance is were the existing class is known as the base or parent class, while the new class is known as the derived or child class. The child class inherits properties and behaviors from its parent class, allowing it to reuse and extend the parent's functionality.
Inheritance is typically used to model an "is-a" relationship between classes.
For example, a car "is-a" vehicle, so a Car class can inherit from a Vehicle class, which may already contain properties and methods relevant to all vehicles. The Car class can then add its own properties and methods specific to cars.

# Instance Variable

### Definition
An instance variable is a variable that belongs to an instance of a class, also known as an object. Each instance of a class has its own set of instance variables, which can have different values for each object.

# Member Variable

### Definition
Member variables are created when the method, constructor or block, is entered and the variable will be destroyed once it exits the method, constructor, or block.

# Memory Management (Garbage Collection, Pointers)

### Definition

# Method Overloading

### Definition

# Method

### Definition
A method is a function or procedure associated with an object or class. It is used to define the behavior of an object or class and can be called by other parts of the program or by other objects.

# Multiple Inheritance

### Definition
 It allows a class to inherit properties and behavior from more than one parent class. With multiple inheritance, a subclass can inherit from multiple base classes and have access to all of their methods and attributes.

# Multithreading in OOP (time permitting)

### Definition

# Object Relationships (Association, Aggregation, Composition)

### Definition

# Object-Oriented Design Principles

### Definition

# Operator Overloading

### Definition
It allows the same operator to be used with different types of operands or to have different meanings depending on the context. In C++, you can overload an operator, such as + (addition) or * (multiplication), to perform a specific task when applied to a user-defined class or data type.

# Overloading

### Definition

# Polymorphism

### Definition
It's a concept that allows objects of different classes to be treated as if they are objects of the same class.

# Public/Private/Protected

### Definition
A public member can be accessed from anywhere in the program, including outside the class in which it is declared.
A private member can only be accessed from within the class in which it is declared. It cannot be accessed from outside the class or from derived classes.
A protected member can be accessed from within the class in which it is declared, as well as from derived classes.
It cannot be accessed from outside the class or from unrelated classes.

# SOLID Principles

### Definition

# Static (Methods and Variables)

### Definition
The static keyword is used to create entities for the lifetime during that program that is independent of any particular object of the class or function invocation.

# Testing in OOP (Unit Testing, Test-Driven Development)

### Definition

# UML Diagrams and Modeling

### Definition

# Virtual

### Definition
 A virtual function is a function that can be overridden in derived classes. When a virtual function is called through a base class pointer or reference, the actual function called is determined at runtime based on the type of the object pointed to or referred to, not on the type of the pointer or reference.
