# CIS25-Projects

cs25_P01_README
===============

Author: Jimmy Hsu

Project Objective: Shop-Sim with a Side of Stocks
--------------------------------------------------
The original objective of this project was to create a simple business tycoon simulator where user would be in the role of a business manager. The program was to utilize randomized consumer demand and stock prices, and the central gameplay loop would be focused around optimizing the best times to buy and sell goods. A simple text-based ui would allow the user to interact with the game's systems.

Project Code:
---------------


Project Reflection:
-----------------------

- from the start, the idea was to make a business sim with stocks on the side
- had to cut scope down due to time constraints
	+ customers class and shop-sim aspect of the game had to be cut
	+ leftover popularity parameter in Business classes is thus redundant code now

- had trouble making different classes interact with each other
	+ mainly in allowing the Business class to buy and sell Stock objects
	| while still keeping track of it's inventory of stocks

- additionally, there was trouble passing class objects to custom fuctions in the program
	+ encountered "the object has type qualifiers that are not compatible with the member function" error
	+ custom fuctions could not access get methods from passed objects for unknown reason
	| thus, could not get Business net worth calculations or Business info display functions to work

- had trouble creating Business array attribute initialization for constructor
	+ ended up omitting a default intializing array and just creating array data in main()
	+ also scrapped the inclusion of arrays of Stocks in Business class due to this issue,
	| which is why the BuyStock and SellStock functions have to take in a Stock object as a
	| parameter to check against the Business object's listings in its items[] array