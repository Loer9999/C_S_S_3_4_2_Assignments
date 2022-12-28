#include <fstream>
#include <string>
#include <iostream>
#include "cpu.h"

void CPU::NextCommand(const std::string& command)
{
    // Add the value onto the stack if the next command is "PSH".
    if (command == "PSH")
    {
        int value;
        value = std::stoi(loadedProgram.front());
        loadedProgram.pop();
        stack.push(value);
    }
    // Throw an error if the next command is not "PSH" and the CPU does not have at least two values
    // on the stack.
    else if (stack.size() < 2)
    {
        std::cerr << "The CPU does not have enough values on the stack to run the next line." 
                  << std::endl;
        throw "Error";
    }
    else
    {
        // Pop the two topmost values from the stack.
        int value1 = stack.pop();
        int value2 = stack.pop();

        // Add the two topmost values.
        if (command == "ADD")
        {
            stack.push(value1 + value2);
        }
        // Multiply the two topmost values.
        else if (command == "MULT")
        {
            stack.push(value1 * value2);
        }
        // Subtract the first value from the second value.
        else if (command == "SUB")
        {
            stack.push(value2 - value1);
        }
        // Divide the second value by the first value.
        else if (command == "DIV")
        {
            if (value1 == 0)
            {
                std::cerr << "The CPU cannot divide a value by 0." << std::endl;
                throw "Error";
            }
            else
            {
                stack.push(value2 / value1);
            }
        }
        // Compare the first value with the second value.
        else if (command == "CMP")
        {
            if (value1 > value2)
            {
                stack.push(1);
            }
            else if (value1 == value2)
            {
                stack.push(0);
            }
            else
            {
                stack.push(-1);
            }
        }
        // Throw an error if this CPU does not support the language.
        else
        {
        std::cerr << "This CPU does not support the language of the next line." << std::endl;
            throw "Error";
        }
    }
}


void CPU::LoadProgram(const std::string& filename)
{
    // Clear this CPU.
    stack.clear();
    while (!loadedProgram.empty())
    {
        loadedProgram.pop();
    }

    // Open the specified file.
    std::ifstream inFile;
    inFile.open(filename);

    // Throw an error if the CPU cannot successfully open the specified file.
    if (!inFile.is_open())
    {
        std::cerr << "The CPU cannot successfully load the specified file." << std::endl;
        throw "Error";
    }

    // Load the program in the specified file into this CPU.
    while (!inFile.eof())
    {
        std::string temp;
        inFile >> temp;
        loadedProgram.push(temp);
    }
    inFile.close();
}


int CPU::Run()
{
    // Run the next line until the program has no more lines to run.
    while (Next() == 0)
    {

    }
    
    // Throw an error if this CPU has more than one integer on its stack.
    if (stack.size() > 1)
    {
        std::cerr << "The CPU has more than one integer on its stack after running the program." << std::endl;
        throw "Error";
    }
    return stack.peek();
}


int CPU::Next()
{
    // Return -1 if the program has no more lines to run.
    if (loadedProgram.empty())
    {
        return -1;
    }
    
    // Read the command in the next line in the program.
    std::string command;
    command = loadedProgram.front();
    loadedProgram.pop();

    // Execute the next command if it is not an empty entry.
    if (command != "")
    {
        NextCommand(command);
    }
    // The next line is run.
    return 0;
}


std::ostream& operator<<(std::ostream& output, const CPU& aCPU)
{
    // Write the stack through the ostream object.
    output << aCPU.stack;
    return output;
}