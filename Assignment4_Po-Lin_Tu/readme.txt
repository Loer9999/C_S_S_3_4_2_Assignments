In LedgerDriver.cpp, I made the first letter of each method name lowercase for consistency.
That is, I converted "Settle()" to "settle()", "InTheBlack()" to "inTheBlack()", etc.

In test.sh, I removed Node.cpp from compilation. That is, the Node class is a template and
Node.cpp cannot be compiled.