#include <iostream>
#include "utils.h"

int main()
{
	std::cout << "-------------------Please input following values--------------------------\n\n" << std::endl;
	
	int rank, valCount;
	
	//std::cout << "Rank: ";
	//std::cin >> rank;
	rank = 7;	
	valCount = rank + 1;

	std::vector<double> xValVec( valCount ), yValVec( valCount );

	//initValues( xValVec, valCount, "x" );
	//initValues( yValVec, valCount, "y" );
	xValVec = { 2.01, 2.51, 3.01, 3.51, 4.01, 4.51, 5.01, 5.51 };
	yValVec = { 1.12, 1.29, 1.04, 1.81, 1.58, 2.02, 2.25, 1.82 };

	printLagrangeGenericFormula( rank );
	std::cout << "\n\n";
	printLagrangeFormula( xValVec, yValVec, rank );
	
	std::vector< std::vector<double> > tableValues( valCount + 2 );
		
	initTable( tableValues, xValVec, yValVec, valCount );
	printDividedDiffTable( tableValues );

	printNewtonGenericFormula( rank );
	printValuesFromTable( tableValues, valCount );
	printNewtonFormula( tableValues, rank );

	double x = 0;
	
	//std::cout << "\n\nx: " << std::endl;
	//std::cin >> x;
	x = 5.02;

	getLagrangePolynomialValue( xValVec, yValVec, rank, x ),
	getNewtonPolynomialValue( tableValues, rank, x );

    std::cout << q << "\t" << j;
}
