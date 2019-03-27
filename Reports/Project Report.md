# Lisp Interpreter
### Team members: Hyegi Bang, Abigail Fry and Athmika Senthilkumar

## Project Vision
For the project, we will be creating a minimal lisp interpreter in C. Our MVP should be able to accurately carryout all 
comparison and numerical lisp operations. For example, ```(+ 1 2 3)``` should evaluate to ```6```, ```(= 11 11)``` should evaluate to true, 
```(> 1 11)``` should evaluate to false and so on. Our MVP should also be able to evaluate conditional expressions that take this 
form: ```(if (condition) (action1) (action2))```. If the given condition result true, the ```action1``` operation would be performed and 
if false, ```action2``` would be operated. 

Since working on our MVP, we have decided to pivot our stretch goal.  Originally our stretch goal was to to include additional
lisp functionality like processing loops and handling logical operations.  Instead we have decided to focus on making our basic
mathematical operations more robust.  We have finished addition, subtraction, multiplication, and division for multiple digits,
doing a single operation.  We are interested in being able to compute something more complication like ```(+ 2(/ 8 (- 8 6)))```.
We think this goal build off of the work we have already done better than our original stretch goal and is one that we are
more interested in pursuing.

### Learning Goal
As a team, we hope to get more comfortable with C syntax and C coding practices. We want to explore how an interpreted language
like lisp functions on a system level in comparison with C  And as we work on this project, we also hope to develop good
practices for coding in a team, that includes maintaining an up to date trello and using GitHub effectively. 

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


## Results
#### Simple Operations  
![SimpleOp](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/simpleop.jpg)

#### Comparison
![Conditional](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Conditional.jpg)

#### Conditional
![if](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/if.jpg)

#### Error Checking
![Error1](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Error1.jpg)
![Error2](https://github.com/Athmika/SoftSysThinkLISP/blob/master/images/Error2.jpg)

## Next Steps 
* Add more robust error cases
* Implement nested evaluation 
* 

## Project Reflection 
