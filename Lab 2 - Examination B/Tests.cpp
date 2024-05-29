#include "List.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>

bool TestsList() {
    std::string ds_name = "List";
    std::cout << ds_name << " TEST" << std::endl;
    std::cout << "Testing " << ds_name << " with ints" << std::endl;
    List<int> i_list;

    std::cout << "New " << ds_name << " should be empty ....";
    if (!i_list.is_empty()) {
        std::cout << " but was not" << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "Using insertFirst() with integers 10, 20, and 30....: ";
    for (int i = 1; i < 4; ++i) {
        i_list.insertFirst(i * 10);
    }
    std::cout << std::endl;

    std::string result_string;
    std::string control_string = "30,30 20,20 10,10 ";
    std::cout << "Using getFirst() and removeFirst() on " << ds_name << " until empty ..... ";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.getFirst()) + ",";
        result_string += std::to_string(i_list.removeFirst()) + " ";
    }
    if (result_string != control_string) {
        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Using insertLast() with integers 10, 20, and 30....: ";
    for (int i = 1; i < 4; ++i) {
        i_list.insertLast(i * 10);
    }
    std::cout << std::endl;

    result_string = "";
    control_string = "30,30 20,20 10,10 ";
    std::cout << "Using last and removeLast on " << ds_name << " until empty ..... ";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.getLast()) + ",";
        result_string += std::to_string(i_list.removeLast()) + " ";
    }
    if (result_string != control_string) {
        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Mixing the aforementioned functions  ......  ";
    for (int i = 1; i < 3; ++i) {
        i_list.insertFirst(i * 11);
    }
    for (int i = 3; i < 5; ++i) {
        i_list.insertLast(i * 11);
    }
    for (int i = 1; i < 3; ++i) {
        i_list.removeLast();
    }
    for (int i = 9; i < 12; ++i) {
        i_list.insertFirst(i * 11);
    }
    for (int i = 5; i < 8; ++i) {
        i_list.insertLast(i * 11);
    }

    result_string = "";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.removeFirst()) + " ";
        result_string += std::to_string(i_list.removeLast()) + " ";
    }
    control_string = "121 77 110 66 99 55 22 11 ";
    if (result_string != control_string) {
        std::cout << "expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Using insertFirst/Last and removeFirst/Last on prepopulated " << ds_name << " .... " << std::endl;
    std::cout << "  Adding 0,1,2,...,7,8,9 using insertFirst()" << std::endl;
    for (int i = 0; i < 10; ++i) {
        i_list.insertFirst(i);
    }

    std::cout << "  checking size() .. ";
    if (i_list.size() != 10) {
        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  Calling removeFirst and removeLast" << std::endl;
    i_list.removeFirst();
    i_list.removeFirst();
    i_list.removeLast();
    i_list.removeLast();
    std::cout << "  checking size() .. ";
    if (i_list.size() != 6) {
        std::cout << " expected size() == 6, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  Calling insertFirst() and insertLast." << std::endl;
    i_list.insertFirst(0);
    i_list.insertFirst(2);
    i_list.insertLast(5);
    i_list.insertLast(9);
    std::cout << "  checking size() .. ";
    if (i_list.size() != 10) {
        std::cout << " expected size() == 10, but is " << i_list.size() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "  calling getFirst() and getLast()";
    result_string = "";
    result_string += std::to_string(i_list.getFirst()) + ", ";
    result_string += std::to_string(i_list.getLast());
    control_string = "2, 9";

    if (control_string != result_string){
        std::cout << "Expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << " OK!" << std::endl;

    std::cout << "  Calling removeLast() until " << ds_name << " is empty using is_empty() .... " << std::endl;
    result_string = "";
    control_string = "9 5 2 3 4 5 6 7 0 2 ";
    while (!i_list.is_empty()) {
        result_string += std::to_string(i_list.removeLast()) + " ";
    }

    if (result_string != control_string) {
        std::cout << "Expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << std::endl;
    std::cout << "Testing " << ds_name << " with strings .... " << std::endl;
    List<std::string> s_list;

    std::cout << "Testing insertFirst() with A, B, C and D .... ";
    s_list.insertFirst("A");
    s_list.insertFirst("B");
    s_list.insertFirst("C");
    s_list.insertFirst("D");

    result_string = "";
    control_string = "DCBA";

    while (!s_list.is_empty()) {
        result_string += s_list.removeFirst();
    }
    if (result_string != control_string) {
        std::cout << " expected " << control_string << " but got " << result_string << std::endl;
        return false;
    }

    std::cout << " OK!" << std::endl << std::endl;;
    return true;
}

bool ExceptionsList() {
    std::string ds_name = "List";
    std::cout << ds_name << " EXCEPTIONS" << std::endl;
    std::cout << "Testing " << ds_name << " for exceptions" << std::endl;

    List<int> i_list;

    // Exceptions
    // first on empty
    std::cout << "using getFirst() with empty " << ds_name << " ... ";
    try {
        i_list.getFirst();
        std::cout << " expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // last on empty
    std::cout << "using getLast() with empty " << ds_name << " ... ";
    try {
        i_list.getLast();
        std::cout << " expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // removeFirst on empty
    std::cout << "using removeFirst() with empty " << ds_name << " ... ";
    try {
        i_list.removeFirst();
        std::cout << " expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }

    // removeLast on empty
    std::cout << "using removeLast() with empty " << ds_name << " ... ";
    try {
        i_list.removeLast();
        std::cout << " expected exception to be raised." << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cout << "OK!" << std::endl;
    }
    return true;
}

bool TestsStack()
{
    std::cout << "STACK TEST" << std::endl<<std::endl;
    std::cout << "Testing Stack with datatype int, using default constructor.... " << std::endl;
    Stack<int> iStack;

    std::cout << "New element should be empty .... ";
    if (!iStack.is_empty())
    {
        std::cout << " but was not" << std::endl;
        return false;
    }
    std::cout << std::endl;


    std::cout << "Pushing integers 10,20 and 30....: ";
    for (int i = 1; i <= 3; i++)
    {
        iStack.push(i * 10);
    }
    std::cout<<std::endl;

    std::string resStr;
    std::string controlStr = "30,30 20,20 10,10 ";
    std::cout << "Using peek and pop on stack until empty .....";
    while (!iStack.is_empty())
    {
        resStr+=std::to_string(iStack.peek());
        resStr+="," + std::to_string(iStack.pop()) + " ";
    }
    if (resStr != controlStr)
    { 
        std::cout <<" expected "<<controlStr << " but got  " << resStr << std::endl;
        return false;
    }
    std::cout << std::endl;

    
    std::cout << "Mixing push and pop  ......  ";
    for (int i = 1; i < 5; i++)
        iStack.push(i * 11);
    for (int i = 1; i < 3; i++)
        iStack.pop();
    for (int i = 5; i < 8; i++)
        iStack.push(i * 11);
    resStr = "";
    while (!iStack.is_empty())
        resStr += std::to_string(iStack.pop()) + " ";
    controlStr = "77 66 55 22 11 ";
    if (resStr != controlStr)
    {
        std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
        return false;
    }
    std::cout << std::endl;


    

    std::cout << "Testing Stack with datatype string .... " << std::endl;
    Stack<std::string> sStack;

    std::cout << "Testing expanding internal array pushinh A, B, C and D .... ";
    sStack.push("A");
    sStack.push("B");
    sStack.push("C");
    sStack.push("D");

    resStr = "";
    controlStr = "DCBA";

    while (!sStack.is_empty())
    {
        resStr += sStack.pop();
    }
    if (resStr != controlStr)
    {
        std::cout << " expected " << controlStr << " but got  " << resStr << std::endl;
        return false;
    }
    std::cout << std::endl;
    return true;
}

bool ExceptionsStack()
{
    Stack<int> iStack;
    std::cout << "Using peek on new empty stack ";
    try
    {
        iStack.peek();
        std::cout << ".... expected exception but exception was not thrown !" << std::endl;
        return false;
    }
    catch (std::exception e)
    {
        std::cout << "expecting exception..... ";
    }
    std::cout <<std::endl;
    
    std::cout << "Using pop on new empty stack ";
    try
    {
        iStack.pop();
        std::cout << "... expected exception but exception was not thrown !" << std::endl;
        return false;
    }
    catch (std::exception e)
    {
        std::cout << "expecting exception..... ";
    }
    std::cout << std::endl;

    iStack.push(0);
    iStack.pop();
    std::cout << "Using peek on empty stack that has previously had elements in it ";
    try
    {
        iStack.peek();
        std::cout << ".... expected exception but exception was not thrown !" << std::endl;
        return false;
    }
    catch (std::exception e)
    {
        std::cout << "expecting exception..... ";
    }
    std::cout <<std::endl;
    
    std::cout << "Using pop on empty stack that has previously had elements in it ";
    try
    {
        iStack.pop();
        std::cout << "... expected exception but exception was not thrown !" << std::endl;
        return false;
    }
    catch (std::exception e)
    {
        std::cout << "expecting exception..... ";
    }
    std::cout << std::endl;
    return true;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::cout << "Starting funcionality tests on List..." << std::endl;
	if (!TestsList())
	{
        std::cout << std::endl << "Functionality tests failed. See above." << std::endl;
        return 1;
    }
    std::cout << std::endl << "Starting exception tests on List..." << std::endl;
    if (!ExceptionsList())
    {
        std::cout << std::endl << "Exception tests failed. See above." << std::endl;
        return 1;
    }
    std::cout << std::endl << "------------------" << std::endl;
    std::cout << "Starting funcionality tests on Stack..." << std::endl;
    if (!TestsStack())
    {
        std::cout << std::endl << "Functionality tests failed. See above." << std::endl;
        return 1;
    }
    std::cout << std::endl << "Starting exception tests on Stack..." << std::endl;
    if (!ExceptionsStack())
    {
        std::cout << std::endl << "Exception tests failed. See above." << std::endl;
        return 1;
    }
    std::cout << std::endl << "All tests passed!" << std::endl << "You can now hand in your code to the instructor." << std::endl;
	return 0;
}