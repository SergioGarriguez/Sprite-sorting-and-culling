# Sprite sorting and culling

## Sprite sorting

  By default, when we try to render a bunch of sprites they are rendered according to the order in which they appear in the code, that is, that the sprite that has been rendered first appears beneath the one that has been rendered later on. This can be a problem if we want a character to be able to hide behind a tree without it looking like if the character had just climbed it or if we want to go both under and over a bridge at different moments, we definitely don't want to fly over it when the character is swiming in the water under it. This means that we have to somehow sort the sprites so that they are ordered in the way we want.
   
  ![sorting example](https://github.com/SergioGarriguez/Sprite-sorting-and-culling/blob/main/images/sorting-example.jpg)
  
  ![sorting in unity](https://github.com/SergioGarriguez/Sprite-sorting-and-culling/blob/main/images/2D-Scene-example.jpg)
  
   To solve that issue we have to treat the game as if it had a third dimension that determines how close to the screen it is, as if the game was actually 3d and had an ortographic camera that was pointing in the direction of that axis. This is known as the z axis.
   
   There are a few ways in which this could be done. One of them is sorting according to y.
   
    ![y sorting](https://github.com/SergioGarriguez/Sprite-sorting-and-culling/blob/main/images/sort-buildlings.png)
   
   This method is as simple as converting the y value into the order that the  sprites will be rendered in. Another really common one is sorting layers, pretty self eplanatory. You can also mix both aproaches as I have done for our example, or as unity does in the examle below.
   
   https://www.youtube.com/watch?v=9vBbg1-Bxcw
   
   To implement this, you can use various methods, one way is to use a series of arrays representing each layer, but I will just use a priority queue.
   
 ### priority queue:
 
   A priority queue, as you may know, is a queue that is ordered according to the priority of the elements. By default the ones with higher priority will get out first so they will be rendered first, that is, at the back. However, this condition can be customized by overloading the operator () inside of a condition class. This condition can be customized to be whatever you want so don't hesitate to change things.
   
   We will use the one that is available by default in the standard library with #include <queue>. But you should also be able to use priority queues available in other standard libraries such as eastl.
   
   It is defined like this:
   
   template<
   
    class T,
    
    class Container = std::vector<T>,
    
    class Compare = std::less<typename Container::value_type>
    
> class priority_queue;

  where T is the type of element, Container is the container that contains the elements and Compare is the condition to sort the elements.
  
  For the element it is probably a good idea to create a class that is the element that will be stored in the vector, to keep it simplethis class will contain all the information needed to render it plus the sorting layer.
  
  For the condition we will create a class that overloads the operator () with the condition that we want to use, in my case it will be the layer and the y position, return true to make the element on the left more important, false to make the element on the right more important, the most important elements are the ones that are drawn first and therfore on the back.
  
  Then we have to add the functions AddElementToQueue and DrawQueue. AddElementToQueue should be used instead of the simple draw function in the update of the entity Draw should be in render update and Add element to queue in the entities that you want to sort.
  
  Note that if you are making an isometric game you will probably need a custom comparison like in the following video:
  
  https://www.youtube.com/watch?v=yRZlVrinw9I
   
  ### references for the sorting:
   
   https://discourse.libsdl.org/t/z-order/16357/4
   
   https://www.gamedev.net/forums/topic/707079-sprites-draw-order-sorting-for-top-down-2d-game-with-floors-and-bridges/
   
   https://en.cppreference.com/w/cpp/container/priority_queue
   
   https://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
   
   ## Camera culling
   
   Rendering things that are outside the screen is not the most efficint rendering technique, you are basically using resources for something that the player is not going to see. This can greatly slow down the game if there are many objects outside the camera view, like with a stupidly big tiled map.
   
   To prevent this we have to cull the sprites that are outside the camera, that is, to detect which are outside the camera view and which are inside. This process is called camera culling.
   
   ### references for camera culling
   
   https://www.youtube.com/watch?app=desktop&v=zCaurIC49I4
   
   
   ## improvements
   
   make sorting affect maps
   
   make the culling affect logic and physics
   
