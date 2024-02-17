//To Be Modified
#include "objPos.h"
#include "objPosTree.h"
#include "objPosTreeModel.h"

#include <cstdlib>
#include <ctime>

#define COUNT 20
#define LARGE_COUNT 50
#define TOTAL_ASSERT_COUNT 146
#define TOTAL_TEST_CASES 8

#include <iostream>
using namespace std;

objPosBST *TreeUnderTest;
objPosBSTModel *TreeModel;
int successCount;
int passCount;

void createNewTrees();
void clearTrees();
objPos generateRandomPos();
objPos generateRandomPosNumAbove100();

bool assert_equal(int, int);
bool assert_equal(char, char);
bool assert_equal(bool, bool);

// **** Enable This Flag for Verbose Tree Printout for Debugging **** //
// **** Enable This Flag for Verbose Tree Printout for Debugging **** //
bool verboseMode = false;
// **** Enable This Flag for Verbose Tree Printout for Debugging **** //
// **** Enable This Flag for Verbose Tree Printout for Debugging **** //




//////////////////////////////////////////
//////////////////////////////////////////
////////   CONSTRUCTOR TESTERS   /////////
//////////////////////////////////////////
//////////////////////////////////////////

/// Required Methods:  
//  Constructor, Destructor, deleteTree(), IsEmpty(), IsInTree()

/// Total Assertion Counts: 2

// 1 assertion count
void testConstructorIsEmpty() {
	
	bool result = true;
	cout << "TEST: testConstructorIsEmpty" << endl;

	createNewTrees();
	bool expected = true;
	bool actual = TreeUnderTest->isEmptyTree();	

	result = result & assert_equal(expected, actual);
	clearTrees();
	if(result) passCount++;
}

// 1 assertion count
void testConstructorIsInTreeEmpty() {
	
	bool result = true;
	cout << "TEST: testConstructorIsInTreeEmpty" << endl;

	createNewTrees();
	objPos target = generateRandomPos();
	bool expected = false;
	bool actual = TreeUnderTest->isInTree(target);	
	
	result = result & assert_equal(expected, actual);
	clearTrees();
	if(result) passCount++;
}



/////////////////////////////////////
/////////////////////////////////////
////////   INSERT TESTERS   /////////
/////////////////////////////////////
/////////////////////////////////////

// Required Methods:
// insert(), isLeaf(), printTree()

// 20 assertion counts
void testInsert20IsLeafCheckPrintTree() {

	bool result = true;

	cout << "TEST: testInsert20IsLeafCheckPrintTree" << endl;
	objPos itemArray[COUNT];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}

	if(verboseMode)
	{
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	for(int i = 0; i < COUNT; i++)
	{
		actual = TreeUnderTest->isLeaf(itemArray[i]);
		expected = TreeModel->isLeaf(itemArray[i]);

		result = result & assert_equal(expected, actual);
	}
			
	clearTrees();
	if(result) passCount++;
}

// 50 assertion counts
void testInsert50IsLeafCheckPrintTree() {

	bool result = true;

	cout << "TEST: testInsert50IsLeafCheckPrintTree" << endl;
	objPos itemArray[LARGE_COUNT];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < LARGE_COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}
	
	if(verboseMode)
	{
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	for(int i = 0; i < LARGE_COUNT; i++)
	{
		actual = TreeUnderTest->isLeaf(itemArray[i]);
		expected = TreeModel->isLeaf(itemArray[i]);

		result = result & assert_equal(expected, actual);
	}
			
	clearTrees();
	if(result) passCount++;
}

/////////////////////////////////////
/////////////////////////////////////
////////   REMOVE TESTERS   /////////
/////////////////////////////////////
/////////////////////////////////////

// Required Methods:
// remove(), isInTree()

// 20 assertion calls
void testInsert20Remove10IsInTreeCheckPrintTree() {

	bool result = true;
	int randIndex = 0;

	cout << "TEST: testInsert20Remove10IsInTreeCheckPrintTree" << endl;
	objPos itemArray[COUNT];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}

	if(verboseMode)
	{
		cout << "Before Removals" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}

	for(int i = 0; i < COUNT / 2; i++)
	{
		randIndex = rand() % COUNT;
		TreeUnderTest->remove(itemArray[randIndex]);
		TreeModel->remove(itemArray[randIndex]);
	}

	if(verboseMode)
	{
		cout << "After Removals" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	for(int i = 0; i < COUNT; i++)
	{
		actual = TreeUnderTest->isInTree(itemArray[i]);
		expected = TreeModel->isInTree(itemArray[i]);

		result = result & assert_equal(expected, actual);
	}
			
	clearTrees();
	if(result) passCount++;
}

// 50 assertion calls
void testInsert50Remove20IsInTreeCheckPrintTree() {

	bool result = true;
	int randIndex = 0;

	cout << "TEST: testInsert50Remove20IsInTreeCheckPrintTree" << endl;
	objPos itemArray[LARGE_COUNT];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < LARGE_COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}

	if(verboseMode)
	{
		cout << "Before Removals" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();	
	}

	for(int i = 0; i < COUNT; i++)
	{
		randIndex = rand() % LARGE_COUNT;
		TreeUnderTest->remove(itemArray[randIndex]);
		TreeModel->remove(itemArray[randIndex]);
	}

	if(verboseMode)
	{
		cout << "After Removals" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	for(int i = 0; i < LARGE_COUNT; i++)
	{
		actual = TreeUnderTest->isInTree(itemArray[i]);
		expected = TreeModel->isInTree(itemArray[i]);

		result = result & assert_equal(expected, actual);
	}
			
	clearTrees();
	if(result) passCount++;
}


///////////////////////////////////////////
///////////////////////////////////////////
////////   FIND GREATER TESTERS   /////////
///////////////////////////////////////////
///////////////////////////////////////////

// Required Methods:
// findGreater()

// 2 assertion calls
void testInsert20Insert10FindGreaterCheckPrintTree() {

	bool result = true;

	cout << "TEST: testInsert20Insert10FindGreaterCheckPrintTree" << endl;
	objPos itemArray[COUNT];
	objPos itemArrayAdditional[COUNT/2];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}

	if(verboseMode)
	{
		cout << "Before Inserting Large Numbers" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();	
	}

	cout << "Find Whether Any Nodes have objPos.number > 100" << endl;
	expected = TreeModel->findGreater(100);
	actual = TreeUnderTest->findGreater(100);
	result = result & assert_equal(expected, actual);

	for(int i = 0; i < COUNT / 2; i++)
	{
		itemArrayAdditional[i] = generateRandomPos();
		TreeUnderTest->insert(itemArrayAdditional[i]);
		TreeModel->insert(itemArrayAdditional[i]);
	}

	if(verboseMode)
	{
		cout << "After Inserting Large Numbers" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	cout << "Find Whether Any Nodes have objPos.number > 100" << endl;
	expected = TreeModel->findGreater(100);
	actual = TreeUnderTest->findGreater(100);
	result = result & assert_equal(expected, actual);
			
	clearTrees();
	if(result) passCount++;
}

// 2 assertion calls
void testInsert50Insert20FindGreaterCheckPrintTree() {

	bool result = true;

	cout << "TEST: testInsert50Insert20FindGreaterCheckPrintTree" << endl;
	objPos itemArray[LARGE_COUNT];
	objPos itemArrayAdditional[COUNT];
	bool expected, actual;
	createNewTrees();

	for(int i = 0; i < LARGE_COUNT; i++)
	{
		itemArray[i] = generateRandomPos();
		TreeUnderTest->insert(itemArray[i]);
		TreeModel->insert(itemArray[i]);
	}

	if(verboseMode)
	{
		cout << "Before Inserting Large Numbers" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}

	cout << "Find Whether Any Nodes have objPos.number > 150" << endl;
	expected = TreeModel->findGreater(150);
	actual = TreeUnderTest->findGreater(150);
	result = result & assert_equal(expected, actual);

	for(int i = 0; i < COUNT; i++)
	{
		itemArrayAdditional[i] = generateRandomPos();
		TreeUnderTest->insert(itemArrayAdditional[i]);
		TreeModel->insert(itemArrayAdditional[i]);
	}

	if(verboseMode)
	{
		cout << "After Inserting Large Numbers" << endl;
		cout << "Tree Under Test:" << endl;
		TreeUnderTest->printTree();
		cout << "Tree Model:" << endl;
		TreeModel->printTree();
	}
	
	cout << "Find Whether Any Nodes have objPos.number > 150" << endl;
	expected = TreeModel->findGreater(150);
	actual = TreeUnderTest->findGreater(150);
	result = result & assert_equal(expected, actual);
			
	clearTrees();
	if(result) passCount++;
}



////////////////////////////////////////////////
////////////////////////////////////////////////
/////////////   Main Test Suite   //////////////
////////////////////////////////////////////////
////////////////////////////////////////////////


bool runAllTests(int argc, char const *argv[]) {
	
	// objPosBST Testers
	cout << "[TREE TESTER STARTED]" << endl;
    testConstructorIsEmpty();  //1
	testConstructorIsInTreeEmpty();  //1
	testInsert20IsLeafCheckPrintTree();  //20
	testInsert50IsLeafCheckPrintTree();  //50
	testInsert20Remove10IsInTreeCheckPrintTree();  //20
	testInsert50Remove20IsInTreeCheckPrintTree();  //50
	testInsert20Insert10FindGreaterCheckPrintTree(); //2
	testInsert50Insert20FindGreaterCheckPrintTree(); //2
	cout << "[TREE TESTER ENDED]" << endl << endl;

	if(successCount != TOTAL_ASSERT_COUNT) 
		return false;
	else 
		return true;
}

int main(int argc, char const *argv[]) {
  	
	srand(time(NULL));
	successCount = 0;
	passCount = 0;
	bool successCode = runAllTests(argc, argv);
	if(successCode)	cout << endl << "Passed All Tests" << endl;
	else			cout << "Failed Tests, Check Failure" << endl;	
	cout << "Assertion Score: " << successCount << " / " << TOTAL_ASSERT_COUNT << endl;	
	cout << "Test Case Score: " << passCount << " / " << TOTAL_TEST_CASES << endl;	

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}

void clearTrees()
{
	delete TreeUnderTest;
	delete TreeModel;
	TreeUnderTest = NULL;	
	TreeModel = NULL;	
}

void createNewTrees()
{
	if(TreeUnderTest != NULL || TreeModel != NULL) clearTrees();
	TreeUnderTest = new objPosBST();
	TreeModel = new objPosBSTModel();
}


objPos generateRandomPos()
{
	objPos temp;

	temp.setX(rand() % 100);
	temp.setY(rand() % 100);
	temp.setNum(rand() % 500);
	temp.setPF(rand() % 26 + 'a');
	temp.setSym(rand() % 26 + 'A');

	return temp;
}

objPos generateRandomPosNumAbove100()
{
	objPos temp;

	temp.setX(rand() % 100 + 100);
	temp.setY(rand() % 100 + 100);
	temp.setNum(rand() % 500);
	temp.setPF(rand() % 26 + 'a');
	temp.setSym(rand() % 26 + 'A');

	return temp;
}


bool assert_equal(int a, int b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;		
	}
	return result;
}

bool assert_equal(char a, char b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		cout << "\t\tExpected: " << a << ", but Actual: " << b << endl;		
	}
	return result;
}

bool assert_equal(bool a, bool b)
{
	bool result = (a == b);
	if(result)	
		successCount++;
	else
	{
		if(a)
			cout << "\t\t[ASSERTION] Expected: TRUE, but Actual: FALSE" << endl;		
		else
			cout << "\t\t[ASSERTION] Expected: FALSE, but Actual: TRUE" << endl;		
	}
	return result;
}