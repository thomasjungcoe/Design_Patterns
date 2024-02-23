Prototype

    Prototype is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.

    Problem

        obj copying but some obj's fields may be private and not visible from outside of the obj itself.
        Also, since you have to know the obj that you are copying from, your program becomes dependent on that class.
        Furthermore, sometimes you only know the interface that the obj follows, but not its concrete class, when for example,
            a parameter in a method accepts any objects that follow some interface.

    Solution

        The Prototype pattern delegates the cloning process to the actual objects that are being cloned. The pattern delcares a 
            common interface for all objects that support cloning. This interface lets you clone an obj without coupling your code
            to the class of that object. -> such interface contains just a single "clone" method.
        
        The implementation of the "clone" method is very simliar in all classes.
            The method creates an obj of the current class and carries over all of the field values of the old object into the new one.
            You can even access private fields of other objects that belong to the same class.

        An obj that supports cloning is called a "prototype". When your obj have dozens of fields and hundreds of possible configurations,
            cloning them might serve as an alternative to subclassing.

    Applicability
        Use the Prototype pattern when your code shouldn't depend on the concrete classes of objects that you need to copy
        
        Use the pattern when you want to reduce the number of subclasses that only differ in the way they initialize their respective objects.

     How to Implement
        1. Create the prototype interface and declare the "clone" method in it. Or just add the method to all classes of an existing class hierarchy, if you have one
        
        2. A prototype class must define the alternative construtor that accepts an object of that class as an arg. 
            The constructor must copy the values of all fields defined in the class from the passed obj into the newly created instance.

        3. The cloning method usually consists of just one line: running a "new" operator with the prototypical version of the contructor. Note, that every class
            must explicitly override the cloning method and use its own class name along with the "new" oerator. Otherwise, the cloning method may produce an
            obj of a parent class.
        
        4. Optionally create a centralized registry to store a catalog of frequently used prototypes. (with static method for fetching the prototype)


    Pros and Cons
        + You can clone obj w/o coupling to their concrete classes
        + You can get rid of repeated initilization code in favor of cloning pre-built prototypes.
        + You can produce complex obj more conveniently
        + You get an alternative to inheritance when dealing with configuration presets for complex objs

        - Cloning complex obj that have circular refernces might be very tricky.

    Relations with Other Patterns
        * Many designs start by using Factory Method (less compli and more cust. via subclasses) and evolve towards Abs Factory, Prototyupe, or Builder (more flexible, but more complicated).
        * Abs Factory classes ar emore based on a set of Factory Methods, but you can also use Prototype to compose the methods on these classes.
        * Prototype can help when you need to save copies of Commands into history.
        * Designs that make heavy use of Composite and Decorator can often benefit from using Prototype.
            Applying the pattern lets you clone complex structures instead of re-constructingh them from scratch.
        * Prototype isn't based on inheritance, so it doesn't have its drawbacks. On the other hand, Prototyperequires a complicated initialzation of the cloned obj. Factory Method is 
            based on inheritance but doesn't require an initialization step.
        * Sometimes Prototype can be a simpler alternative to Memento. This works if the object, the state of which you want to store in the history, is fairly straightforward and 
            doesn’t have links to external resources, or the links are easy to re-establish.
        * Abstract Factories, Builders and Prototypes can all be implemented as Singletons.