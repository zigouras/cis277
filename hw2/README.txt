Nico Zigouras
CIS 277 Spring 2016
HW 1
Jan 30, 2016


3.2 Polygon primitive: Cube
See scene/cube.cpp.  The head of the character uses the cube I created.

3.3 Character

The main program will render the character.

See the Character class for setting up and rendering the Character.  The SceneGraphTraverseAndDraw class handles the recursive transformation of a scene.

3.4 Documentation

See the Character::initBody method where you can manipulate the transformation of any body part.

I found it difficult to transform the scene more than once in a program execution and have it work.  I altered Node to store the transformation but I still had trouble.  I think the relative transformations to the parent need to be stored in the Node once and kept unchanged, e.g. the head's relative sx is always 2; it is always twice the size of the body in the x direction.  With the current implementation of Node, the coordinates change each time you transform it so you lose the initial relative transformation to its parent.  So it works if you transform it once but if you transform it again it is broken.

For help on matrix multiplication and determinants I used:
http://www.intmath.com/matrices-determinants/matrix-determinant-intro.php


Questions:

1.  Then you could specify only a subset of the transformation coordinates and fall back on the defaults for the rest rather than having to specify all or none.

2.  You could get a null pointer exception.

3.  A pointer is variable that holds the address of an object.  A reference similarly indirectly addresses an object and can be thought of as an alias to an object.  Pointers can be reassigned while references cannot.  If one variable is a reference to another, and you change the value of the reference, the value of the variable will change.  If you have a pointer to a variable and you reassign it and set the value of the pointer to something else, the original value will not change.  Java objects are like C++ pointers.

4.  The first example is used for operator overloading of the [] operator in the vec4 class and ensures that the contents of the vector are not changed during the function call.  The second must be used during method chaining so you can do something to the value that is returned in the second method in the chain.