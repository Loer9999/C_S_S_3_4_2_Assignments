#pragma once

#include <queue>
#include <string>
#include <iostream>
#include "MyStack.h"

class CPU
{
private:
   MyStack<int> stack;
   std::queue<std::string> loadedProgram;

   /** The method NextCommand understands and executes the given command.

    @pre  This CPU has enough values on the stack for this method to execute the command. The command
       is in the language that this CPU supports and does not attempt to divide a value on the stack by 0.

    @post  This method changes the data member stack based on the given command. If the command requires two 
       values on the stack to execute while the CPU does not have at least two values on the stack, this
       method throws an error. If the command is in a language that this CPU does not support, this method
       throws an error. Finally, if the command attempts to divide a value on the stack by 0, this method
       throws an error as well. 
    
    @param command  The command to execute. */
   void NextCommand(const std::string& command);

public:
   /** The method LoadProgram loads the program in the specified file into this CPU.
     
    @pre  The specified file exists in the directory.

    @post  The data member stack becomes empty; the data member loadedProgram becomes the program in the 
       specified file. If this CPU cannot open the specified file, this method throws an error.

    @param filename  The name of the file that contains the program to load. */
   void LoadProgram(const std::string& filename);


   /** The method Run runs the entire program that is loaded into this CPU and returns the result.

    @pre  The data member loadedProgram is the program to run.

    @post  The data member stack contains the result of the program; the data member loadedProgram is empty 
       (reaches the end of the program). If the stack contains more than one integer after this method runs
       the program, this method throws an error.

    @return  An integer that is the result of the program. */
   int Run();


   /** The method Next runs the next line in the program that is loaded into this CPU.

    @pre  This CPU has enough values on the stack to run the next line. The next line is in the
       language that this CPU supports and does not attempt to divide a value on the stack by 0.

    @post  This method runs the next line in the program; the data member loadedProgram pops one line 
       (advances by one line). If the next line requires two values on the stack to run while the CPU
       does not have at least two values on the stack, this method throws an error. If the next line is
       in a language that this CPU does not support, this method throws an error. Finally, if the next
       line attempts to divide a value on the stack by 0, this method throws an error as well.

    @return  0 if this method runs the next line; -1 if the program has no more lines to run. */
   int Next();


   /** The method operator<< overloads the operator <<, writing the data member stack of the specified
       CPU, which is on the right hand side of the operator <<, through an ostream object, which is on
       the left hand side of the operator <<.

    @pre  N/A.

    @post  This method writes the data member stack of the specified CPU; the CPU does not change.

    @param output  An ostream object.

    @param aCPU  The CPU whose stack is to be written.

    @return  A reference to the ostream object. */
   friend std::ostream& operator<<(std::ostream& output, const CPU& aCPU);
};