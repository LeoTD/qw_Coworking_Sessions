Sure Davy. Well, this is probably more than you were really asking for, but to understand pointers you have to understand memory and once I started writing I got a bit carried away... Oh well. Hope this helps.

Lets start with the basic description. Like you said, a `char*` is a pointer to a character, and a `char**` is a pointer to a pointer to a character. But, let's unpack that. A pointer (to anything) is really just a memory address. Specifically, a pointer is a variable that stores the memory address of some other variable. When we dereference a pointer, we are telling our program to go to the memory address we've stored and give us the value that was stored at that memory address.

The reason our pointers have types is so that our program knows how to interpret the value at the memory address we've stored.

So, back to the original question. What is a `char*`? It's the memory address of a character value. What is a `char**`? It's the memory address of some other pointer, in this case of type `char*`.

Now, let's talk about a common usage. A `char*` isn't often used to point to a single character. It's usually used to point to the beginning of a sequence of characters. This works because C provides simple syntax for moving through memory. 