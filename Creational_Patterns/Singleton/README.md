Singleton

    Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access to this instance.

Problem

    The Singleton pattern solves two problems at the same time, violating the 'Single Responsibility Principle'.

    1. Ensure that a class has just a single instance.
        Why would anyone want to control how many instances a class has? 
            The most common reason for this is to control access to some shared resources.
                ex.) a database or a file

    2. Provide a global access point to that instance.
        Global variables that are used to store some essential objects are very handy but unsafe since any code can potentially overwrite the contents of those
            variables and crash the app.

Solution

    All implemtations of the Singleton have these two steps in common:
    * Make the default contrctor private, to prevent other objects from using the "new" operator with the Singleton class.
    * Create a static creation method that acts as a constructor.
        Under the hood, this method calls the private constructor to create an object and saves it in a static field. 
        All following calls to this method return the cached object.

Applicabilty

    Use the Singleton pattern when a class in your program should have just a single instance avilable to all clients;
        ex.) a single database obj shared by different parts of the program.
            - The Singleton pattern disables all other means of creating objects of a clas sexcept for the special creation method. 
    
    Use the Singleton pattern when you need stricter control over global variables.
        - Unlike global vraibles, the Singleton pattern guarantees that there's just one instance of a class. Nothing, except for the Singleton 
            class itself, can replace the cached instance.

How to Implement
    
    1.) Add a private static field to the class for storing the singleton intance.
    
    2.) Declare a public static fcreation method for getting the singleton isntance.

    3.) Implement "lazy initialization" inside the static method. It should create a new object on its first call and put it into the staic field.
            The method should always return that instance on all subsequent calls.

    4.) Make the constructor of the class private. The staic method of the class will still be able to call the constructor, but not the other obj.

    5.) Go over the client code and replace all direct calls to the singleton's constructor with calls to its static creation method.

Pros vs Cons

    + You can be sure that a class has only a single instance.
    + You gain a global access point to that instance.
    + The singleton obj is initialized only when it's requested for the first time.

    - Violates the Single Responsibility Principle. The pattern sovles two problems at the time.
    - The single pattern can mask bvad design, for instance, when the component of the program know too much about each other.
    - The pattern requires special treatemnt in a multithreaded environemnt so that multiple threads won't create a singleton obj several times.
    - It may be difficult to unit test the client code of the Singleton bc many test frameowrks rely on inheritance when producting mock obj.
        Since the construcotr of the singleton class is private and overriding static method is impossible in most languages, 
            you will need to think of a create way to mock the singleton. Or just don't warite the tests. OR don't use the Singleton pattern.

Relations with Other Patterns
* A Facasde class can often be transformed into a Singleton since a single facade obj is sufficient in most cases.
* FLyweight would resemble Singleton if you somehow managed to reduce all shared states of the obj to just one flywiehgt obj. 
    but there are two fundamental differnce between these patterns.
    1.) There should be only one Singleton instance, whereas a Flyweight class can have multiple instances with different instrinsic sstates.
    2.) The Singleton obj can be mutable. Flyweight obj are immutable.
* Abstract Factories, Buidlers and Prototypes can all be implemtned as Singletons.

