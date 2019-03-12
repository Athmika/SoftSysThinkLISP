# Think Lisp : Interpreter Language
### Hyegi Bang, Athmika Senthilkumar, Abigail Fry

## Project Goals

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Our MVP for this project is to create a minimal lisp interpreter in C. Our MVP should be able to accurately carryout all
comparison and numerical lisp operations. For example, (+ 1 2 3) should evaluate to 6, (= 11 11) should evaluate to true,
(> 1 11) should evaluate to false and so on. The interpreter should read and store variables. For example, (setq y 5) should
set the value 5 to the variable y.  Our MVP should also be able to evaluate conditional expressions that take this form: 
(if (condition) (action1) (action2)).\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Since working on our MVP, we have decided to pivot our stretch goal.  Originally our stretch goal was to to include additional
lisp functionality like processing loops and handling logical operations.  Instead we have decided to focus on making our 
basic mathematical operations more robust.  We have finished addition, subtraction, multiplication, and division for multiple
digits, doing a single operation.  We are interested in being able to compute something more complication like (+ 2(/ 8 (- 8 6))).We think this goal build off of the work we have already done better than our original stretch goal and is one that we 
are more interested in pursuing. 
 
## Learning Goals 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Our learning goals include getting ourselves comfortable with writing and debugging code in C. 
We would like to go beyond the singular examples and implement codes that build upon itself.   We also hope to better 
understanding of interpreter language through LISP and translate that knowledge into C.  We want to implement good coding 
practices (i.e. comments, organization, architecture).

## Progress and Resources
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; To get started, we began by gaining a better understanding of LISP convention. We read about 
prefix notation, the syntax for basic mathematical operations, and how to do conditionals which are part 
of our MVP implementation.  We read the tutorials outlined in the previous report that go over the mechanics behind 
implementing basic LISP interpreters. Then we split up the work individually to work on the prompt, parser and evaluator. 
The prompt takes in multiple lines of Lisp commands. The parser executes arithmetic expressions.The evaluator uses the
results of parser to compute nested expressions. The prompt and parser have been successfully implemented. 

The following resources were used for the project: 
+ Tutorialspoint: https://www.tutorialspoint.com/lisp/index.htm
+ Build your own Lisp book: http://www.buildyourownlisp.com/contents
+ Blog on how to create a Lisp interpreter: http://leohetsch.com/create-a-minimal-lisp-like-interpreter-in-c/
+ Geeks For Geeks: https://www.geeksforgeeks.org/

 
## Current State
* Include robust error checking to stop the user from evaluating expressions with syntax errors -- Abby 
  * Success: Return matching error statements for all failure cases
* Finish the implementation of the if statement -- Athmika 
  * Return correct value based on conditional
* Comment the code and improve the code organization -- Hyegi 
  * Make the code readable
* Debug evaluate to ensure that nested expressions are accurately computed -- Team 
  * Always return accurate value with more than one operator

    
