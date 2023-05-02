# Sprite sorting and culling

## Sprite sorting

  By default, when we try to render a bunch of sprites they are rendered according to the order in which they appear in the code, that is, that the sprite that has been rendered first appears beneath the one that has been rendered later on. This can be a problem if we want a character to be able to hide behind a tree without it looking like if the character had just climbed it.
  
   To solve that issue we have to treat the game as if it had a third dimension that determines how close to the screen it is, this is known as the z axis.
   
   There are a few ways in which this could be done. One of them is sorting according to y. This method is as simple as converting the y value into the order that the  sprites will be rendered in. Another really common one is sorting layers, pretty self eplanatory. You can also mix both aproaches.
   
   To implement this, you can use various methods, one way is to use a series of arrays representing each layer, but I will just use a priority queue.
   
 ### priority queue:
 
   A priority queue, as you may know, is a queue that is ordered according to the priority of the elements. By default the ones with higher priority will get out first.
   
   We will use the one that is available by default in the standard library with #include <queue>.
   
   It is defined like this:
   
   template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

  where T is the type of element, Container is the container that contains the elements and Compare is the condition to sort the elements. For the element it is probably a good idea to create a class that is the element that will be stored in the vector, this class will contain all the information needed to render it plus the sorting layer. For the condition we will create a class that overloads the operator () with the condition that we want to use, in my case it will be the layer and the y position, return true to make the element on the left more important, false to make the element on the right more important, the most important elements are the ones that are drawn first and therfore on the back.
  
  Then we have to add the functions AddElementToQueue and DrawQueue. Draw should be in render update and Add element to queue in the entities that you want to sort.
   
  ### references for the sorting:
   
   https://discourse.libsdl.org/t/z-order/16357/4
   
   https://www.gamedev.net/forums/topic/707079-sprites-draw-order-sorting-for-top-down-2d-game-with-floors-and-bridges/
   
   https://en.cppreference.com/w/cpp/container/priority_queue
   
   https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
   
   
   ## improvements
   
   make sorting affect maps
   
   make the culling affect logic and physics
