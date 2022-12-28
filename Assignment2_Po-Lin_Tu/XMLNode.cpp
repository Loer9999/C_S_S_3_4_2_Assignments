#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "XMLNode.h"


std::vector<std::string> XMLNode::Split(const std::string& specifiedString, const char& delimiter) const
{
    std::vector<std::string> splitStrings;

    // Locate the first substring.
    int start = 0;
    int end = specifiedString.find(delimiter);
    
    // Obtain the substring if the delimiter can be found.
    while (end != std::string::npos)
    {
        std::string substring = specifiedString.substr(start, end - start);
        splitStrings.push_back(substring);

        // Locate the next subtring.
        start = end + 1;
        end = specifiedString.find(delimiter, start);
    }
    // Obtain the substring if there is no delimiter.
    std::string substring = specifiedString.substr(start, specifiedString.length() - start);
    splitStrings.push_back(substring);

    return splitStrings;
}


void XMLNode::ParseFileHelper(std::string& line, const bool& read)
{
    // Check if the utmost node in the line should be read.
    if (read)
    {
        // Obtain the starting tag of the XMLNode.
        int startOfTag = 1;
        int endOfTag = line.find(">");
        std::string startingTag = line.substr(startOfTag, endOfTag - startOfTag);

        // Extract substrings, which are the node name and the properties, from the startingTag.
        std::vector<std::string> substrings;
        substrings = Split(startingTag, ' ');
    
        for (std::string element: substrings)
        {
            // Separate the property names and the values of the properties in the substrings.
            std::vector<std::string> separatedProp = Split(element, '=');

            // If the substring cannot be split, the substring is the node name.
            if (separatedProp.size() < 2)
            {
                name = separatedProp[0];
            }
            else
            {
                properties.insert(std::pair<std::string, std::string>(separatedProp[0], separatedProp[1]));                         
            }
        }

        // Obtain the line after the starting tag.
        int afterStartTag = endOfTag + 1;
        line = line.substr(afterStartTag, line.length() - afterStartTag);
    }

    // Check if there is at least one child node.
    if (line[0] == '<' && line[1] != '/')
    {
        // Create a child node and obtain the line after the child node.
        XMLNode* childNode = new XMLNode();
        childNode -> ParseFileHelper(line, true);
        children.push_back(childNode);
        
        // Create the rest of the children.
        ParseFileHelper(line, false);
    }
    else
    {
        content = line.substr(0, line.find("<"));
    }

    // Obtain the line after the ending tag.
    int afterEndTag = line.find("<") + name.length() + 3;
    if (read && afterEndTag < line.length())
    {
        line = line.substr(afterEndTag, line.length() - afterEndTag);
    }
}


void XMLNode::WritePropHelper(std::ostream& output, std::map<std::string, std::string>::iterator ite,
                              const std::vector<std::string>& formatIndicator)
{
    if (ite != properties.end())
    {
        // Write the property in the specified format.
        output << formatIndicator[5] << (ite -> first) << formatIndicator[6] << (ite -> second) << formatIndicator[7];
        WritePropHelper(output, ++ite, formatIndicator);
    }
}


void XMLNode::OutputHelper(std::ostream& output, int index, const bool& write, 
                           const std::vector<std::string>& formatIndicator)
{
    // Check if this XMLNode should be written.
    if (write)
    {
        // Readability?
        // Write the starting tag.
        output << formatIndicator[3] << name << formatIndicator[4];
        WritePropHelper(output, properties.begin(), formatIndicator);
        output << formatIndicator[8];
    }

    // Check if there is child node to write.
    if (index < children.size())
    {
        bool writeChild;
        // For the FindByNodeType method, the child node should be written only when it has the specified name.
        if (formatIndicator[0] == "FindByNodeType" && formatIndicator[1] != children[index] -> name)
        {
            writeChild = false;
        }
        // For the FindByProperty method, the child node should be written only when it has the specified property
        // and value.
        else if (formatIndicator[0] == "FindByProperty" && 
                (children[index] -> properties.find(formatIndicator[1]) == children[index] -> properties.end() ||
                 formatIndicator[2] != children[index] -> properties[formatIndicator[1]]))
        {
            writeChild = false;
        }
        else
        {
            writeChild = true;
        }

        // Write (or not write) the child node of this XMLNode.
        children[index] -> OutputHelper(output, 0, writeChild, formatIndicator);

        // Write the rest of the children without writing this XMLNode.
        OutputHelper(output, ++index, false, formatIndicator);
    }

    if (write)
    {
        // Write the content.
        if (content.length() != 0)
        {
            // Do not write "Content: " to the screen if there is no content.
            output << formatIndicator[9];
        }
        output << content << formatIndicator[10];
        if (formatIndicator[0] == "WriteFile")
        {
            // Write the ending tag to the file.
            output << name << formatIndicator[11];
        }
    }
}


void XMLNode::deleteHelper(int index)
{
    // Check if there is child node.
    if (index < children.size())
    {
        // Delete the child node (and the children of the child node).
        delete children[index];

        deleteHelper(++index);
    }
}


XMLNode::XMLNode() : name(""), content("")
{
    properties = std::map<std::string, std::string>();
    children = std::vector<XMLNode*>();
}


XMLNode::XMLNode(const std::string& fileName)
{
    ParseFile(fileName);
}


XMLNode::~XMLNode()
{
    deleteHelper(0);
}


void XMLNode::ParseFile(const std::string& fileName)
{
    name = "";
    content = "";
    properties.clear();
    children.clear();
    std::ifstream inFile;
    inFile.open(fileName);
    
    // Check if the file exists.
    if (!inFile.is_open())
    {
        throw "Error";
    }
    else
    {
        // Read the only line in the file.
        std::string line;
        getline(inFile, line);
        
        if (line.length() > 0)
        {
            // Take the line as this XMLNode and its children.
            ParseFileHelper(line, true);
        }
        inFile.close();
    }
}


void XMLNode::WriteFile(const std::string& fileName)
{
    std::vector<std::string> formatIndicator = {"WriteFile", "", "", "<", "", " ", "=", "", ">", "", "</", ">"};
    std::ofstream outFile;
    outFile.open(fileName);
    OutputHelper(outFile, 0, true, formatIndicator);
    outFile << "\n";
    outFile.close();
}


void XMLNode::FindByNodeType(const std::string& nodeName)
{
    std::vector<std::string> formatIndicator = {"FindByNodeType", nodeName, "", "Node: ", "\n", "\t", ": ", "\n", 
                                                "", "Content: ", "\n", ""};
    std::cout << "FindByNodeType: \n\n";
    OutputHelper(std::cout, 0, false, formatIndicator);
    std::cout << "---------------------------------------------------\n";
}


void XMLNode::FindByProperty(const std::string& propertyName, const std::string& value)
{
    std::vector<std::string> formatIndicator = {"FindByProperty", propertyName, value, "Node: ", "\n", "\t", ": ", "\n", 
                                                "", "Content: ", "\n", ""};
    std::cout << "FindByProperty: \n\n";
    OutputHelper(std::cout, 0, false, formatIndicator);
    std::cout << "---------------------------------------------------\n";
}


void XMLNode::PrettyPrintDocument()
{
    std::cout << "PrettyPrintDocument: \n\n";
    std::vector<std::string> formatIndicator = {"PrettyPrint", "", "", "Node: ", "\n", "\t", ": ", "\n", 
                                                "", "Content: ", "\n", ""};
    OutputHelper(std::cout, 0, true, formatIndicator);
    std::cout << "---------------------------------------------------\n";
}