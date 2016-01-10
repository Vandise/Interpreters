# Interpreters
This is an implementation of an interpreted, dynamically typed, pure object-oriented programming language. This is by no means a production ready programming language and the sole purpose for its creation is for learning purposes.


## Concepts
In this language everything is an object, even primitive data types such as integers, and these objects have methods. All objects implement an object called Object in the runtime, which gives access to functions such as *print*.

The last executed statement of any line/context is always the return statement.

### Context (Scope)
Objects and control structures have a context (scope) in which local and instance variables are accessible. By default an application is in the *Main* scope, meaning you can use the keyword *self* and get the main *Object* returned.

```
self
=> <Object 0x.......>
```

### Functions (Methods)
Functions and methods are also bound to scope. Because all object inherit from *Object*, all core functions like *print* are accessible. User defined functions like the following will also be accessible in all contexts.

```
func add(num1, num2)
  num1 + num2
end

add(1,2)
=> 3

self.add(3,4)
=> 7

```

Every method call is simply a message sent to an object instance. In the previous example we created a function/method called *add* which, by default, gets bound to the Main object (context). When interpreted, a method call looks like the following:

```
object->call("+",[1,2])
```

### Lambdas (Anonymous Functions)
Lambda function objects are defined with the following syntax:
```
l = -> do |param_1, param_2|
  print(param_1,param_2)
end

print(l.class_name)
=> Lambda

l.call("string",1)
=> string
=> 1
```
Lambdas can also be called anonymously
```
(-> do |greeting,name|
  print(greeting+" "+name)
end).call("Hello","Bob")
=> Hello Bob
```

And passed as a callback parameter
```
// method
func callable_param(callable)
  callable.call("Hello","Bob")
end

// lambda definition
greet = -> do |greeting,name|
  print(greeting+" "+name)
end

callable_param(greet)
=> Hello Bob
```

### Arrays
Arrays are partially implemented and can store/intermix any data-types:
```
array = [1,2,"three",(5<4), nil]
=> <Array 0x00...>
array.size
=> 5
```
Elements can be called via the *index* method. Note arrays are 0-based!
```
array.index(0)
=> 1

// shorthand
array[4]
=> nil
```
Arrays can be iterated with a basic lambda function passed to the *each* method
```
array.each -> do |element|
  print(element)
end
=> 1
=> 2
...
```

### User Defined Classes
All class names must begin with a capital letter in order to be put into the runtime. A simple person class can be constructed like the following:
```
class Person

  func greet(name)
    print("Hello " + name)
  end

end

Person.greet("Ben")
```

#### Constructors
To construct a new instance of an object, simply call the *new* method on the object you wish to instantiate.
```
me = Person.new
=> <Person 0x....>
```
The new method makes a call to a user-defined method *construct* like the following:
```
class Person
  func construct()
    print("Person Constructed")
  end
end

me = Person.new
=> Person Constructed
=> <Person 0x....>
```

### Accessing class methods
Currently all user-defined class methods have a public, static scope and can be called by directly invoking the class, or through an instance variable which will allow you to store state.
```
Person.greet("Ben")
=> Hello Ben

x = Person

x.greet("Frank")
=> Hello Frank
```

#### Instance Variables
Instance variables are denoted with the @ prefix.
```
class Person
  func construct(first_name,last_name)
    @first_name = first_name
    @last_name = last_name
  end

  func full_name()
    @first_name + " " + @last_name
  end

  func set_first_name(value)
    @first_name = value
  end
end

person = Person.new("Ben", "Anderson)
print(person.full_name)
=> "Ben Anderson"

person.set_first_name("Mr")
print(person.full_name)
=> "Mr Anderson"
```

#### Inheritance
Inheritance is specified in the class definition, separated by a colon ":"
```
// Person : Object is implied
class Person

  func greet(name)
    print("Hello " + name)
  end

end

class User : Person
  func login(name)
    greet(name)
  end
end

User.login("Billy")
=> "Hello Billy"
```

### Control Structures
None Currently Available

### Core Classes / Methods Inheritance Order
Note: Implemented for concepts only.
- Class
- > Object
    - print 
- > Main 
  - Integer
    - +
    - -
    - *
    - /
    - >
    - <
  - String
    - +
    - *
  - True
  - False
  - Nil
  - Self
  - Lambda
  - Array
    - size
    - each

### Runtime
User-defined code is useless unless it has a runtime to execute in. The Core classes are readily available in the runtime for the user to use. It is also where we define all core methods to these classes.

### Defining Core Methods
Core methods are simply structures that implement a *call* method. Most custom methods will only need to inherit from the Method structure, custom operation methods against integer must inherit from *OperatorMethod* struct. 

For example if we wanted to implement the division operator method, we'd do the following:

file: runtime/integer.hpp (Contains methods defined for integers)
```
// inherit operator method perform, which accepts two arguments
// based off of the specified template type (this case int)
struct IntDivOp : OperatorMethod<int>
{
  // EVERY interpreted output returns a pointer to a Runtime::Object
  Runtime::Object* perform(int receiver, int argument)
  {
    // ValueObject automatically assigns its type (int)
    // and inherits from the appropriate runtime class -- this case Integer
    return new Runtime::ValueObject(receiver / argument);
  }
};

// define a reference for us to use in the runtime bootstrapper
IntDivOp         int_divide_method;
```

file: bootstrap.cpp (binds methods to core classes)
```
// addMethod accepts two parameters:
//  a string for the operator(method)
//  a reference to the method stucture (in which case all class instances point to a single structure)

intClass->addMethod(std::string("/"),&int_divide_method);
```

## Compiling
Note: This requires the boost library.
```
cd interpreters/
make clean
make
make compile
./bin/wc test/some_file.src
```
