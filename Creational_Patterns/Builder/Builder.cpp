// Builder is a creational design pattern, which allows constructing complex obj step by step.
// Usage exmaple: The builder pattern is a well-known pattern in C++ world especially when you need to create an obj with lots of possible configuration options.
// Identification: The builder pattern can be recognized in a class, which has a single creation method and several methods to configure the resulting obj.
//                          Builder methods often support chaining (for example, someBuilder->setValueA(1)->setValueB(2)->create()).

// Conceptual Exmaple:
//        * What classes does it consist of?
//        * What roles do these classes play?
//        * In what way the elements of the pattern are related?

/**
 * It makes sense to use the Builder pattern only when your products are quite complex and require extensive configuration.
 * 
 * Unlike in other creational patterns, different concrete builders can produce unrelated products. 
 * In other words, results of various builders may not always follow the same interface.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Product1 {
    public:
        std::vector<std::string> parts_;

        void ListParts() const {
            std::cout << "Product parts: ";
            for (size_t i = 0; i < parts_.size(); i++) {
                if (parts_[i] == parts_.back()) {
                    std:: cout << parts_[i];
                } else {
                    std::cout << parts_[i] << ", ";
                }
            }
            std::cout << "\n\n";
        }
};

/**
 * The Builder interface specifies methods for creating the different parts of the Product objects.
 */
class Builder {
    public:
        virtual ~Builder() {}
        virtual void ProducePartA() const = 0;
        virtual void ProducePartB() const = 0;
        virtual void ProducePartC() const = 0;
};

/**
 * The Concrete Builder classes follow the Builder interface and provide specific implementations of the building steps.
 * Your program may have several variations of Buidlers, implemented differently.
*/
class ConcreteBuilder1 : public Builder {
    private:
        Product1* product;

        /**
         * A fresh builder instance should contain a blank product obj, which is used in further assembly.
        */
       public:

       ConcreteBuilder1() {
        this->Reset();
       }

       ~ConcreteBuilder1() {
           delete product;
       }

       void Reset() {
        this->product = new Product1();
       }
       /**
        * All production steps work with the same product instance.
       */

      void ProducePartA() const override {
        this->product->parts_.push_back("PartA1");
      }

      void ProducePartB() const override {
        this->product->parts_.push_back("PartB1");
      }

      void ProducePartC() const override {
        this->product->parts_.push_back("PartC1");
      }

       /**
     * Concrete Builders are supposed to provide their own methods for
     * retrieving results. That's because various types of builders may create
     * entirely different products that don't follow the same interface.
     * Therefore, such methods cannot be declared in the base Builder interface
     * (at least in a statically typed programming language). Note that PHP is a
     * dynamically typed language and this method CAN be in the base interface.
     * However, we won't declare it there for the sake of clarity.
     *
     * Usually, after returning the end result to the client, a builder instance
     * is expected to be ready to start producing another product. That's why
     * it's a usual practice to call the reset method at the end of the
     * `getProduct` method body. However, this behavior is not mandatory, and
     * you can make your builders wait for an explicit reset call from the
     * client code before disposing of the previous result.
     */

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsable to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */
    Product1* GetProduct() {
        Product1* result = this->product;
        this->Reset();
        return result;
    }
};

/**
 * The Director is only responsible for executing the building steps in a particular sequence.
 * It is helpful when producing products according to a specific order or configuration.
 * Strictly speaking, the Director classs is optional, since the client can control builders directly.
 */
class Director {
    /**
     * @var Builder
    */
   private:
    Builder* builder;

    /**
     * The Director works with any builder instance that the client code passes to it.
     * This way, the client code may change the final type of the newly assembled product.
     */
    public:

    void set_builder(Builder* builder) {
        this->builder=builder;
    }

    /**
     * The Director can construct several product variations using the same building steps.
    */
   void BuildMinimalViableProduct() {
       this->builder->ProducePartA();
   }

   void BuildFullFeaturedProduct() {
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
   }
};

/**
 * The client code creates a builder obj, passes it to the director and then initiates the construction process.
 * THe end result is retrived from the builder obj.
 */
/**
 * I used raw pointers for simplicity however you may prefer to use smart pointers here
*/
void ClientCode(Director& director) {
    ConcreteBuilder1* builder = new ConcreteBuilder1();
    director.set_builder(builder);
    std::cout << "Standard basic product: " << std::endl;
    director.BuildMinimalViableProduct();

    Product1* p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Standard full featured product: " << std::endl;
    director.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    std::cout << "Custom product: " << std::endl;
    builder->ProducePartA();
    builder->ProducePartC();
    p = builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
}

int main() {
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}