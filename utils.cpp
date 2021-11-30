#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

#include "utils.h"

// find maximum value of the vector
double findMax( const std::vector<double>& valVec )
{
    double max = std::numeric_limits<double>::lowest();
    
    for( int i = 0; i < valVec.size(); ++i )
    {
        if( valVec[i] > max )
            max = valVec[i];
    }

    return max;
}

int calcFactorial( int n )
{
    if( n == 1 )
        return 1;

    return n * calcFactorial( n - 1 );
}

void initValues( std::vector<double>& valArr, int valCount, std::string valName )
{
	for( int i = 0; i < valCount; ++i )
	{
		std::cout << valName << i << ": ";
		std::cin >> valArr[i];
	}
}


void initTable( std::vector< std::vector<double> >& tableValues,
				const std::vector<double>& xValVec, 
				const std::vector<double>& yValVec, int count )
{
	int step = 0;
	tableValues[0] = xValVec;
	tableValues[1] = yValVec;

	for( int i = 0; i <	count; ++i )
	{
		for( int j = 0; j < tableValues[i + 1].size() - 1; ++j )
		{
			size_t y1 = j + 1,
				   y2 = j,
				   x1 = i + j + 1,
				   x2 = j;

					
			double yRes = tableValues[i + 1][y1] - tableValues[i + 1][y2];
			double xRes = xValVec[x1] - xValVec[x2];

			tableValues[i+2].emplace_back( yRes / xRes );
		}
	}	
}

void printLagrangeGenericFormula( int rank )
{
	std::cout << "\n\n--------------------Lagrange's Generic Formula--------------------\n\n";
	std::cout << "L" << rank << "(x) = ";

	for( int i = 0; i < rank + 1; ++i )
	{
		std::cout << "f(x" << i + 1 << ")*";
		
		for( int j = 0; j < rank + 1; ++j )
		{
			if( j != i )
				std::cout << "(x - x" << j + 1 << ")"; 
		} 
		
		std::cout << " / ";		

		for( int j = 0; j < rank + 1; ++j )
		{
			if( j != i )
				std::cout << "(x" << i + 1 << " - x" << j + 1 << ")"; 
		} 
		
		if( i != rank + 1 )	
			std::cout << " + " << std::endl; 
	}
}

void printLagrangeFormula( const std::vector<double>& xValArr, 
						   const std::vector<double>& yValArr, int rank )
{
	std::cout << "\n\n--------------------Lagrange's Formula--------------------\n\n";
	std::cout << "L" << rank << "(x) = ";

	for( int i = 0; i <= rank; ++i )
	{
		std::cout << yValArr[i] << "*";
		
		for( int j = 0; j <= rank; ++j )
		{
			if( j != i )
				std::cout << "(x - " << xValArr[j] << ")"; 
		} 
		
		double divisor = 1;
		for( int j = 0; j <= rank; ++j )
			if( j != i )
				divisor *= ( xValArr[i] - xValArr[j] );

		std::cout << " / " << divisor << std::endl;

		if( i != rank )	
			std::cout << " + "; 
	}
}

double getLagrangePolynomialValue( const std::vector<double>& xValArr, 
								 const std::vector<double>& yValArr, 
								 int rank, double x )
{
	std::cout << "\n\n--------------------Polynomial value with Lagrange's Formula--------------------\n\n";
	std::cout << "L" << rank << "(x) = ";
	double result = 0;

	for( int i = 0; i <= rank; ++i )
	{
		double divisible = 1;
		//std::cout << i << " " << yValArr[i] << "*\n";
		std::cout << "(" << yValArr[i] << ")" << "*";
		
		for( int j = 0; j <= rank; ++j )
		{
			if( j != i )
			{
				//std::cout << i << " " << j << " " << (x - xValArr[j]) << std::endl;
				divisible *= (x - xValArr[j]);
			}
		} 
		
		double divisor = 1;
		for( int j = 0; j <= rank; ++j )
			if( j != i )
				divisor *= ( xValArr[i] - xValArr[j] );

		
		double temp = divisible / divisor;
		result += yValArr[i] * temp;
		std::cout << std::setprecision(4) << "(" << temp << ")";

		if( i != rank )	
			std::cout << " + "; 
		else
			std::cout << " = " << result << std::endl;
	}

    return result;
}

void printNewtonGenericFormula( int count )
{
	std::cout << "\n\n--------------------Newton's Generic Formula--------------------\n\n";
	std::cout << "L" << count << "(x) = ";

	for( int i = 1; i <= count + 1; ++i )
	{
		std::cout << "f(";
		if( i == 1 )
			std::cout << "x1)";
		else if( i == 2 )
			std::cout << "x1,x2)";
		else
			std::cout << "x1,...,x" << i << ")";			

		for( int j = 1; j < i; ++j )
		{
			std::cout << "(x - x" << j << ")"; 
		} 
		
		if( i != count + 1 )	
			std::cout << " + " << std::endl; 
	}
}

void printNewtonFormula( const std::vector< std::vector<double> >& tableValues,
						  int rank )
{
	std::cout << "\n\n--------------------Newton's Formula--------------------\n\n";
	std::cout << "L" << rank << "(x) = ";

	for( int i = 0; i <= rank; ++i )
	{
		std::cout << tableValues[i + 1][0];
		for( int j = 0; j < i; ++j )
		{
			std::cout << "(x - " << tableValues[0][j]  << ")"; 
		} 
		
		if( i != rank )	
			std::cout << " + " << std::endl; 
	}
	
}

void printValuesFromTable( std::vector< std::vector<double> >& tableValues,
						   int count )
{
	std::cout << "\n\n\n--------------------Values from the table of divided differences--------------------\n\n";
	for( int i = 1; i < count + 1; ++i )
	{
		std::cout << "f(";
		if( i == 1 )
			std::cout << "x1) = ";
		else if( i == 2 )
			std::cout << "x1,x2) = ";
		else
			std::cout << "x1,...,x" << i << ") = ";	

		std::cout << tableValues[i][0] << std::endl;
	}
}						   

double getNewtonPolynomialValue( const std::vector< std::vector<double> >& tableValues,
								 int rank, double x )
{
	std::cout << "\n\n--------------------Polynomial value with Newton's Formula--------------------\n\n";
	std::cout << "L" << rank << "(x) = ";
	double answer = 0;
	for( int i = 0; i <= rank; ++i )
	{
		double temp = tableValues[i + 1][0];

		for( int j = 0; j < i; ++j )
		{
			temp *= ( x - tableValues[0][j] ); 
		} 
		
		std::cout << temp;
		 
		answer += temp;

		if( i != rank )
			std::cout << " + ";
	}

	std::cout << " = " << answer << std::endl;

	return answer;
}

void printDividedDiffTable( std::vector< std::vector<double> >& tableValues )
{
	std::cout << "\n\n--------------------Table of the divided differences-------------------\n\n";
	std::cout << std::setprecision( 2 ) << std::fixed;
	for( int i = 0; i < tableValues.size(); ++i )
	{
		for( int j = 0; j < tableValues[i].size(); ++j )
		{
			std::cout << tableValues[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void divDiffTable( const std::vector<double>& xValVec, 
				   const std::vector<double>& yValVec, int count )
{
	std::vector< std::vector<double> > tableValues(count + 2);
		
	initTable( tableValues, xValVec, yValVec, count );
	printDividedDiffTable( tableValues );
}
