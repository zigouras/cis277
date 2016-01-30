Nico Zigouras CIS 277 Spring 2016 HW 1 Jan 30, 2016

See the comments in character.cpp line 144-122 on how to 
 3.2 Polygon primitive: Cube (20 points)

Your scene graph should be able to render transformed cubes, transformed cylinders, and transformed spheres. We have provided the code to build and render cylinders and spheres, but it's up to you to implement cube building, uploading, and rendering. A polygon stores the color with which it should be rendered. Refer to the Cylinder and Sphere classes for how you might choose to go about constructing your cube class.
3.3 Character (30 points)

Create and render a scene graph that uses primitives to form a creature. The code creating your creature should be easy to read and modify so we can easily adjust your graph's transformations when testing it. The creature has to have the following parts:

    Body/Torso: Where everything originates. When the body moves/rotates/scales, so should everything else.
    Head that pivots at its base.
    At least four limbs: Each limb should be broken into two parts (upper and lower) and should pivot at their joints, not at their centers. In other words, the puppet's limbs should not break apart when the lower segments are rotated. The lower limb portion should inherit the transformations of the upper limb portion.
    For all of the above, clearly label with comments where code can be changed to move body parts.

3.4 Documentation (10 points)

In a text file, explain to a naive user of your code how to interact with the classes you wrote for your scene graph and shapes. Most importantly, make sure to tell the user where they should alter your code to manipulate your creature. Finally, explain any difficulties/bugs you experienced. You should also keep a help log as you work on this assignment to document what issues you had and how you resolved them (TA help, peer help, internet help, etc.). See the course web site's OH/Help Log page for more information. Your documentation should also include answers to the questions listed in the following section.
3.5 Conceptual Questions (20 points)

    (5 pts) In the provided Node class, what would be the benefit to using initialization lists in its constructors instead of their current implementation?
    (4 pts) The provided Node constructors set any pointer member variables to NULL by default. These constructors should be setting these pointers to nullptr; why is this?
    (5 pts) Aside from syntax, is there a difference in using a reference versus using a pointer? If so, what is the difference?
    (6 pts) Below are two different accessor functions implemented for a four-dimensional vector class. They are used to get the floating point number stored at a particular index in the vector. Note the different return types of these functions as well as their const-ness. 