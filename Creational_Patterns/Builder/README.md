Builder
    Builder is a creational design pattern that lets you construct complex objects step by step,
    allowing you to produce different types and representations of an object using the same construction code.

Problem
    Imagine a complex object that requires laborious, step-by-step initialization of many fields and nested objects. 
    Such initialization code is usually buried inside a monstrous constructor with lots of parameters. Or even worse: scattered all over the client code.
        ex.) House class with a bunch of params

Solutoin
    The Builder pattern suggests that you extract the object construction code out of its own class and move it to separate obj called "builder"
        ex.) HouseBuilder class
    
Director
    You can go further and extract a series of calls to the builder steps you use to contruct a product into a separate class called director. 
    The director class defines the order in which to execute the building steps, while the builder provides the implementation for those steps.
    Not a strictly neccessary; good for complex routine and also hides the details of product construction from the client code. 
    The client only needs to associate a builder with a director, lauch the constructor with the director, and get the result from the builder.

          Builder <---  Director <-- Client 
     (from builder & client) ->  Concrete builder -> Product


Applicability
    Use the Builder pattern to get rid of a "telescoping constructor".
    Use the Builder pattern when you want your code to be able to create different representations of some product (ex, stone and wooden house)
    Use the Builder to construct Composite trees or other complex objects.


How to Implement

1. Make sure that you can clearly define the common construction steps for building all available product representations.
2. Declare these steps in the base builder interface.
3. Create a concrete builder class for each of the product representations and implement their construction steps
4. Think about creating a director class. It mayh encapsulate various ways to construct a product using the same builder obj
5. The client code creates both the builder and the director objs. Before construction starts, the client must pass a builder obj to the director, 
        via parameters of the director's class constructor.
6. The construction result can be obtained directly from the director only if all product follow the same interface. 
        Otherwise, the client should fetch the result from the builder.


Pros & Cons
+ You can construct obj step-by-step, defer construction steps or run steps recursively
+ You can reuse the same construction code when building various representations of products.
+ Single Responsibility Principle. You can isolate complex construction code from the business logic of the product

- The overall complexity of the code increases since the patter n requires creating multiple new classes.


Relations with Other Patterns

* many designs start by using "Factory Method" (less complicated and more customizable via subclasses) and evolve toward "Abstract Factory, Prototype, or Builder" (more flexible, but more complicated)
* "Builder" focuses on constructing complex obj step by step. "Abstract Factory" specializes in creating families of related objs. "Abst. Factory" returns the product immediately, whereas "Builder" lets you run some additional construction step before fetching the product.
* You can use "Builder" when creating complex "Composite" trees because you can program its construction steps to work recursively.
* You can combine "Builder" with "Bridge": the director class plays the role of the abstraction, while different builders act as implementations.
* "Abstract Factories, Builders and Prototypes" can all be implemented as "Singletons".
