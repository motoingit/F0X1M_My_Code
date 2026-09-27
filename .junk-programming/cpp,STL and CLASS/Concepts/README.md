# FoodDeliveryOOP (No Header Files) — TCS504 Unit 1

Every OOP concept in a SINGLE self-contained .cpp file — class declared
and defined together, so beginners read one file top to bottom. One
food-delivery world: Customer, Restaurant, DeliveryPartner.

| File | Concept |
|---|---|
| 01_class_and_objects.cpp    | class = blueprint; same methods, different data |
| 02_access_modifiers.cpp     | private / protected / public |
| 03_constructors.cpp         | default, overloaded & copy constructors |
| 04_static_and_private_ctor.cpp | static member, class-belongs-to-object, private ctor (singleton) |
| 05_encapsulation.cpp        | Pillar 1: private data + guarded methods |
| 06_abstraction.cpp          | Pillar 2: interface class, pure virtual (=0) |
| 07_inheritance.cpp          | Pillar 3: base/derived, protected, is-a |
| 08_polymorphism.cpp         | Pillar 4: overloading (compile-time) + overriding (run-time) |
| 09_relationships.cpp        | association, aggregation, composition |

## Build & run any file
```
g++ 05_encapsulation.cpp -o 05 && ./05
```
Commented `// COMPILE ERROR` lines are deliberate — uncomment them in
class, let students predict, and let the compiler be the judge.
