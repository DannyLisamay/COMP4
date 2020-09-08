/**********************************************************************
 *  readme.txt template                                                   
 *  Guitar Hero: GuitarString implementation and SFML audio output
 **********************************************************************/

Name: Danny Lisamay 
Partner: Dheera Vuppala



Hours to complete assignment: Between 4-6 hours 

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In this assignment we implemented  the Karplus-Strong guitar string simulation. 
To do this we created the GuitarString class and modified the GuitarHeroLite.cpp. 
There were 37 ‘notes’ / “different keys” that we could play to make different sounds.
Each of these notes had a different frequency. We were able to “create” a different
frequency by incrementing the value of the frequency for every new note. Then, based 
on the key that was pressed a different audio sound was played. 

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes! We succesfully completed the whole assignment. GuitarString is fully working, 
including emptying the ringbuffer when it’s fully by dequeueing each item. Additionally 
all 37 keys play a different sound and we did not use a 37 case switch statement. 
We know that they are working because when we run our code and enter different keys,
 we can hear different sounds + the GuitarString code passed the unit test cases! 

  /**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)? Successfully or not? As a pair, or individually? If you completed the AutoGuitar, what does it play? 
 **********************************************************************/
We completed the lambda function extra credit as a pair. 
Lambda function: code snippet shown below: 
while(ptrRB->isFull()==false) { 
         auto random = []() {
        return (rand() % 32767) - 32767; 
    };
        ptrRB->enqueue((sf::Int16)random()); 
    }

/**********************************************************************
 *  Does your GuitarString implementation pass the unit tests? Indicate yes or no, and explain how you know that it does or does not? 
 **********************************************************************/
Yes! It does pass the BOOST Unit Test cases in the GTest.cpp file that was provided for us. 
Evidence provided in as a .png in build folder.


The statement: Running 1 Test case…. ***No errors detected after running GStest.o prove that GuitarString passed the unit test cases. 

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

I worked with Dheera as partners. 
/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
The biggest problem we encountered was that initally only when we tested our code to make
sure that different sounds were playing for A and C, only A or C was playing but not both. 
Later we found out that this had to do with the fact that in the makeSamplesFromString function 
we weren’s passing the GuitarString object in as a reference but by value. This created many errors. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

We threw an excpetion if the SoundBuffer vector wasn’t able to load the Samples, and printed an
 error message that SoundBuffer failed to load from samples. Additionally, we have exceptions in 
 the RingBuffer class if we try to enqueue on a full ring, dequeue/peek  on an empty ring. 

For time, our RB implementation is O(1) because it’s all in constant time. There are no loops, 
and since we add to the back of a fixed size array, we never have to traverse or search for any element. 
Enqueue, dequeue, and peek functions are all O(1). 

The space complexity is O(n) because the circular array is a fixed size and is not dynamically allocated.
