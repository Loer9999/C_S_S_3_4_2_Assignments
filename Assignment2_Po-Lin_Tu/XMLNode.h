#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

class XMLNode
{
private:
   std::string name;
   std::map<std::string, std::string> properties;
   std::string content;
   std::vector<XMLNode*> children;


   /** The method Split extracts the substrings that are separated by the delimiters from the
       specified string.

    @pre  The specified string is not an empty string.

    @post  A vector that takes the substrings that are spearated by the delimiters as its
       elements exists.

    @param specifiedString  The string from which the substrings are to be extracted.

    @param delimiter  The character that separates the substrings in the string.

    @return  A vector that takes the substrings as its elements. */
   std::vector<std::string> Split(const std::string& specifiedString, const char& delimiter) const;


   /** The helper method ParseFileHelper takes one utmost node and its children in the specifeid line
       as this XMLNode and its children.

    @pre  The line is from a XML file and is not empty.

    @post  This XMLNode and its children represent one utmost node and its children in the line.
     
    @param line  The line to read.
    
    @param read  A boolean variable that indicates if the utmost node should be read. */
   void ParseFileHelper(std::string& line, const bool& read);


   /** The helper method WritePropHelper writes the properties of this XMLNode through an output object.
    
    @pre  The formatIndicator has the required elements. Specifically, this helper method uses the
       6th, 7th, and 8th elements in the vector to format the output.

    @post  This helper method writes the properties of this XMLNode through the output object. The output
       is in the format that is specified by the vector formatIndicator. The properties of this XMLNode
       remains unchanged.

    @param output  An output object. 
    
    @param ite  The iterator for the properties.

    @param formatIndicator  The vector of strings for output format. */
   void WritePropHelper(std::ostream& output, std::map<std::string, std::string>::iterator ite, 
                        const std::vector<std::string>& formatIndicator);


   /** The helper method OutputHelper writes (or not write) this XMLNode and its children through an 
       output object based on which method invokes this helper method.
    
    @pre  The formatIndicator has the required elements. Specifically, the first three elements in the
       vector indicate which method invokes this helper method and include the parameters of that method,
       and the vector has nine more elements that are used to format the output.

    @post  This helper method writes this XMLNode and its children through the output object under the
       conditions specified by the method that invokes this helper method. The output is also in the
       format that is specified by the vector formatIndicator. This XMLNode and its children remains unchanged.

    @param output  An output object.

    @param index  The index of the vector that stores the pointers to children.

    @param write  A boolean variable that indicates if this XMLNode should be written.
    
    @param formatIndicator  The vector of strings for condition checks and output format. */
   void OutputHelper(std::ostream& output, int index, const bool& write, 
                     const std::vector<std::string>& formatIndicator);

   
   /** The helper method deleteHelper deletes the children of this XMLNode.
    
    @pre  N/A.

    @post  The memory dynamically allocated for the children of this XMLNode is free.

    @param index  The index of the vector that stores the pointers to children. */
   void deleteHelper(int index);


public:
   /** The default constructor creates an empty XMLNode.

    @pre  N/A.

    @post  An empty XMLNode exists. */
   XMLNode();


   /** The parametrized constructor creates a XMLNode by reading a XML file and taking the 
       line in the XML file as the data members of the XMLNode and the children of the
       XMLNode.

    @pre  The file is a XML file and exists in the directory. The file has only one line, and the
       line is not empty.

    @post  A XMLNode whose data members and children represent the line in the XML file exists.

    @param fileName  The name of the XML file to read. */
   XMLNode(const std::string& fileName);


   /** The destructor deletes the children of this XMLNode.
    
    @pre  N/A.

    @post  The memory dynamically allocated for the children of this XMLNode is free. */
   ~XMLNode();


   /** The method ParseFile reads the line in the specified XML file into the data members and children
       of this XMLNode.
    
    @pre  The file is a XML file and exists in the directory. The file has only one line, and the
       line is not empty.

    @post  The data members and the children of this XMLNode represent the line in the XML file; if the
       data members are not empty when this method is invoked, the data members will be emptied so that
       the data members represent only the line in the specified XML file.

    @param fileName  The name of the file to read. */
   void ParseFile(const std::string& fileName);


   /** The method WriteFile writes this XMLNode and its children onto the specified file.

    @pre  This XMLNode is not empty.

    @post  The specified file contains a line that represents this XMLNode and its children; if the
       specified file does not exist, this method creates a new file with the specified name in the
       directory and writes onto this new file. This XMLNode and its children remain unchanged.

    @param fileName  The name of the file where the XMLNode is to be written. */
   void WriteFile(const std::string& fileName);


   /** The method FindByNodeType prints all the nodes who are the children of this XMLNode and have
       names that are the same as the specified node name.

    @pre  This XMLNode is not empty.

    @post  This method prints the children whose names are the same as the specified node name. This
       XMLNode and its children remain unchanged.
     
    @param nodeName  The name of the children to be printed. */
   void FindByNodeType(const std::string& nodeName);


   /** The method FindByProperty prints all the nodes who are the children of this XMLNode and have
       the specified property that has the specified value.

    @pre  This XMLNode is not empty.

    @post  This method prints the children who have the specified property and value. This XMLNode 
       and its children remain unchanged.
    
    @param propertyName  The name of the property to print.

    @param value  The value of the property to print. */
   void FindByProperty(const std::string& propertyName, const std::string& value);


   /** The method PrettyPrintDocument prints this XMLNode and its children.

    @pre  This XMLNode is not empty.

    @post  This method prints this XMLNode and its children. */
   void PrettyPrintDocument();
};