# CIS25-Project-1

Author: Jimmy Hsu

Project: Stock Simulator

Recording: [Video Overview Here](https://youtu.be/pGow0ZIj3-s)

## Project Objective

The original objective of this project was to create a simple business tycoon simulator where user would be in the role of a business manager. The program was to utilize randomized consumer demand and stock prices, and the central gameplay loop would be focused around optimizing the best times to buy and sell goods. A simple text-based ui would allow the user to interact with the game's systems.

## Project Takeaways

- From the start, the project idea was to make a business sim with stocks on the side; unfortunately, I had to cut the scope of the project down due to time constraints
	+ The customer class and shop-sim aspect of the game had to be cut from the project
	+ The leftover popularity parameter in Business classes is now thus redundant code now

- I had trouble making different classes interact with each other, mainly in allowing the Business class to buy and sell Stock objects while still keeping track of it's inventory of stocks

- Additionally, I had trouble passing class objects to custom fuctions in the program
	+ I encountered "the object has type qualifiers that are not compatible with the member function" error
	+ My custom fuctions could not access get methods from passed objects for unknown reasons thus, could not get Business net worth calculations or Business info display functions to work

- I had trouble creating Business array attribute initialization for constructor
	+ I ended up omitting a default intializing array and just creating array data in main()
	+ I also scrapped the inclusion of arrays of Stocks in Business class due to this issue, which is why the BuyStock and SellStock functions have to take in a Stock object as a parameter to check against the Business object's listings in its items[] array

### Program Screenshot: 
<img width="860" alt="image" src="https://github.com/user-attachments/assets/1599d428-ef33-4bd0-87d0-142848b5543f">
<img width="858" alt="image" src="https://github.com/user-attachments/assets/6fef69bc-ac0d-46de-b0b6-cf2061486b68">
