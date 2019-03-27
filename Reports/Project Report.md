# Lisp Interpreter
### Team members: Hyegi Bang, Abigail Fry and Athmika Senthilkumar

## Project Vision
For the project, we created a minimal LISP interpreter in C. Our MVP was tp be able to accurately carryout all comparison and numerical LISP operations. For example, ```(+ 1 2 3)``` should evaluate to ```6```, ```(= 11 11)``` should evaluate to true, ```(> 1 11)``` should evaluate to false and so on. Our MVP also includes evaluating conditional expressions that take this form: ```(if (condition) (action1) (action2))```. If the given condition result true, the action1 operation would be performed and if false, ```action2``` would be operated. 
Just before the project update, we decided to pivot our stretch goal.  Originally our stretch goal was to to include additional LISP functionality like processing loops and handling logical operations.  Instead we have decided to focus on making our basic mathematical operations more robust.  We have finished addition, subtraction, multiplication, and division for multiple digits, doing a single operation.  We are interested in being able to compute something more complication like ```(+ 2(/ 8 (- 8 6)))```.  We thought this goal would build off of the work we have already done better than our original stretch goal an was one we are more interested in pursuing.
Our other stretch goal was to have the interpreter read and store variables for future operation. For example, ```(setq y 5)``` should set the value 5 to the variable ```y``` and ```(+ y 3)``` would output ```6```. 

### Learning Goal
As a team, we hope to get more comfortable with C syntax and C coding practices. We want to explore how an interpreted language like lisp functions on a system level in comparison with C  And as we work on this project, we also hope to develop good practices for coding in a team, that includes maintaining an up to date trello and using GitHub effectively. 

### Project Workflow
Majority of the work was done through pair programming during our two weekly meetings. We often coded and debugged on one 
computer. However, the typer would alter based on the situation. Trello board contains a similar work environment. Most of 
the tasks were thought during the meeting and to prevent overlapping task, one person became the scribe and added the cards.
Therefore, the github commit history and trello board doesn’t fully represent the team’s contribution. However, all work were
distributed and done equally within the teammates. 

### Resources 
The following resources were used for the project: <br/>
* Tutorialspoint: https://www.tutorialspoint.com/lisp/index.htm
* Build your own Lisp book: http://www.buildyourownlisp.com/contents
* Blog on how to create a Lisp interpreter: http://leohetsch.com/create-a-minimal-lisp-like-interpreter-in-c/
* Geeks For Geeks: https://www.geeksforgeeks.org/

## Implementation 
### Prompt 
Our prompt allows the users to enter multiple commands in one execution. We set an arbitrary maximum of a 100 commands that 
can be executed in one execution. We decided that the most intuitive way of exiting the prompt is for the user to press enter
with a blank line. This is done by applying the following condition on a while loop: ```while (1 == scanf("%[^\n]%*c", s))```.
The prompt removes the leading spaces in the commands that are entered by leveraging the isspace() function. This ensures 
that accidental spaces that are entered are ignored and commands can still be executed. 

### Parsing 

Because we wanted to improve our skills manipulating strings in C, we decided not to use external libraries and instead parsed the input manually. We included error checking to make sure that certain syntax errors are identified and the program exits.  

We have attempted to implement a tree structure as a way to parse. This allows for nested commands like this (+ (+ 3 4) 5) to be evaluated. The operators are stored as a parent and the numbers are stored as a children. If the input contains more than one operator, a subtree will be created with its own following children. However, when we integrated the with the prompt function we had, It gave us a segmentation fault and we could not track the errors. 


### Evaluation
```
typedef enum{
  FLOAT, BOOLEAN
} types;

typedef union result{
  float number;
  bool conditional;
}result;

typedef struct{
  result results;
  types units;
} outputWithUnits;

```
The Lisp commands that we choose to implement can output either a float or a Boolean value. We decided to use a union to
store our result. However, in order to format our output we needed to know the type of value that is stored in the union. 
By using an enum in a struct with our union, it allowed us to keep track of the type of value that is stored in the union. 

### Organization

Depending on the type of operation, the evaluation function is housed in a different file. As seen in the diagram below, main_evaluate.c depends on simple_operations.c and conditionals.c which in turn depend on the helper_functions.c file. 

![Diagram](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/diagram.png)


## Results
#### Simple Operations  
![op](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/op.png)

```Syntax for input ([operator] num1 num2 num3 …..)```

#### Comparison
![Conditional](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Conditional.jpg)

```Syntax for input ([operator] num1 num2)```


#### Conditional
![if](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/if.jpg)

```Syntax for input (if (test_clause) (command1) (command2))```


#### Error Checking 
The following pictures are few errors we have implemented in our project: 
![Error1](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Error1.jpg)
<br/>
<br/>
![Error2](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Error2.jpg)

## Next Steps 
* Add more robust error cases
* Implement nested parser using tree 
* Explore additional LISP functionality and implement in our project

## Project Reflection 

As a team, we were able to build upon the material covered in-class and implement it in the specific context of our project. This helped us to solidify our understanding and also gain more confidence coding in C.  It was interesting to learn about LISP and then chose specific parts of LISP to include in our interpreter.  In hindsight, we wish we would have learned more about LISP before making our MVP.  As we got deeper into the project we became more interested in making the mathematical operations be able to do nested operations. This caused us to pivot our stretch goal half-way through the project, away from implementing For Loops in Lisp.  However, we were still only able to attempt our new stretch goal and fell short of full implementation.  We also didn’t implement our reading and storing variables stretch goal.  Instead, we decided to focus on adding error checking.  Overall, the project was a good learning experience and enjoyable.

