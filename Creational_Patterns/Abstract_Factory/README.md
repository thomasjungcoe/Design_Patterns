ABSTRACT FACTORY

Intent
    Abstract Factory is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.

    ex.) furniture online store
            customers want to buy matching furnitures such as chair, sofa, and coffee talbe. (Art Deco, Victorian, Modern style)
    
    You do'nt want to change existing code when adding new products or families of products to the program.
        Furniture vendors update their catalogs very often, and you wouln't want to change the core code each time it happens.

Solution
    * The first thing the ABstract Factory pattern suggests is to explicitly declare interfaces for each distint product of the product family (chair, sofa, or coffee).
        Then make a call variants of products follow these interfaces.
    * Declare the Abstract Factory -- an interface with a list of creation methods for all products that are part of the product family (createChair, creatSofa, and createCoffeTable).
        These methods must return abstract product types represented by the interfaces we extracted previously (Chair, Sofa, CofeeTable and so on).
    * For each variabt of a product family, we create a separate factory class of a particular kind.
        ex.) ModernFurnitureFactory can only create ModernChair, ModernSofa, and ModernCoffeeTable objects.

Applicability
    Use the Abstract Factory when your needs to work with various families of related products, but you don't want it to depend on the concrete classes of those products
        -- they might be unkonwn beforehand or you simply want to allow for future extensiblity.

    Consider implementing the Abstract Factory when you have a class with a set of Factory Methods that blur its primary responsiblity.
        -- In a well-designed program each class is responsible only for on thing. When a class deals with multiple product types, it may be worth extracting its factory methods into 
            a stand-alone factory class or a full-blown Abstract Factory implementation.

How to Implement
    1.) Map out a matrix of distinct product types vs variants of these products.

    2.) Declare abstract product interfaces for all product types. Then make all concrete product classes implement these interfaces.

    3.) Declare the abstract factory interface with a set of creation methods for all abstract products.

    4.) Implment a set of concrete factory classes, one of each product variant

    5.) Create factory initialization code somewhere in the app. It shoul instantiate one of the concrete factory classes, depending on the application configuration or the current environment.
        Pass this factory object to all classes that construct products.

    6.) Scan through the code and find all direct acalls to product constructors. Replace them with calls to the appropriate creation method on the factory object.

Pros and Cons
    + You can be sure that the products you're getting from a factory are compatible with each other.
    + You avoid tight coupling between concrete products and client code.
    + Single Responsibility Principle. You can extract the product creation code into one place, making the code easier to support
    + One/Closed Principle. You can introduce new variants of products without breaking existing client code.

    - The code may become more complicated than it should be, since a lot of new interfaces and classes are introduced along with the pattern.

Relation with Other Patterns
    * Many designs start by using Factory Method(less complicated and more customizable via subclasses) and evolve towards 'Abstract Factory', 'Prototype', or 'Builder' (more flexible, but more complicated)

    * 'Builder' focuses on constructing complex obj step by step. 'Abstract Factory' specializes in creating families of related obj. 
        'Abstract Factory' returns the product immediately whereas 'Builder' lets you run some additional constrcution steps before fetching the product.
    
    * 'Abstract Factory' classes are often based on a set of Factory Methods, but you can also use "Prototype" to compose the methods on these classes.

    * You can use 'Abstract Factory' along with 'Bridge'. This pairing is useful when some abstractions defined by 'Bridge' can only work with specific implementations.
        'ABstract Factory' can encapsulate these relations and hide the complexity from the client code.

    * Abstract Factories, Builders, and Prototypes can all be implemented as Singetons.