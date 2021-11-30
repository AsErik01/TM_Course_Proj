#include <string>
#include <vector>

// find maximum value of the vector
double findMax( const std::vector<double>& valVec );

// calculate the factorial of number
int calcFactorial( int n );

// initialize values of the array $valName with $valCount elements
void initValues( std::vector<double>& valArr, int valCount, std::string valName );

// print Lagrange's interpolation generic formula, when rank is $rank
void printLagrangeGenericFormula( int rank );

// print Lagrange's interpolation formula for specific {x} and {y} values
void printLagrangeFormula( const std::vector<double>& xValArr, 
						   const std::vector<double>& yValArr, int rank );

// calculate the value of the outcome Lagrange's polynomial, when the value of x is $x
double getLagrangePolynomialValue( const std::vector<double>& xValArr, 
								 const std::vector<double>& yValArr, 
								 int rank, double x );

// print Newton's interpolation generic formula, when rank is $TODO 
void printNewtonGenericFormula( int count );

// print first values of each row of values 
// from the table of divided differences
void printValuesFromTable( std::vector< std::vector<double> >& tableValues,
						   int count );

// print Newton's interpolation formula for specific {x} and {y} values
void printNewtonFormula( const std::vector< std::vector<double> >& tableValues,
						  int rank );

// calculate the value of the outcome Newton's polynomial, when the value of x is $x
double getNewtonPolynomialValue( const std::vector< std::vector<double> >& tableValues,
								 int rank, double x );

// calculate the table of divided differences
void initTable( std::vector< std::vector<double> >& tableValues,
				const std::vector<double>& xValVec, 
				const std::vector<double>& yValVec, int count );

// print the calculated table of divided differences
void printDividedDiffTable( std::vector< std::vector<double> >& tableValues );

// calculate and print the table of divided differences
void divDiffTable( const std::vector<double>& xValVec, 
				   const std::vector<double>& yValVec, int count );
