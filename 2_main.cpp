#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "utils.h"


// calculate value for cos(x) + sin(x)
double calculateYValue( double x ); 

// calculate and print value for cos(x) + sin(x)
void printYValue( double x ); 

// calculate values for cos(x) + sin(x)
void calculateYValues( std::vector<double>& xValVec, 
					   std::vector<double>& yValVec, int valCount );

// calculate values for sin(x) - cos(x)
void calculateThirdRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount );
 
// calculate values for sin(x) + cos(x)
void calculateForthRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount );

// calculate values for cos(x) - sin(x)
void calculateFifthRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount );

// calculate the maximum of the 3rd derivatives for xValVec
double calculateM3( std::vector<double>& xValVec, int valCount );

// calculate the maximum of the 4th derivatives for xValVec
double calculateM4( std::vector<double>& xValVec, int valCount );

// calculate the maximum of the 5th derivatives for xValVec
double calculateM5( std::vector<double>& xValVec, int valCount );

// calculate the error, when the rank is 3
double calculateR3( std::vector<double>& xValVec, int valCount );

// calculate the error, when the rank is 4
double calculateR4( std::vector<double>& xValVec, int valCount );
 
// calculate the error, when the rank is 5
double calculateR5( std::vector<double>& xValVec, int valCount );

// calculate D, where D = ||(x-x1)(x-x2)...(x-xN)||
double calculateD( std::vector<double>& xValVec, int valCount );

#define PI 3.14159265

int main()
{
	std::cout << "-------------------Please input following values--------------------------\n\n" << std::endl;
	
	int rank, valCount;
	
	//std::cout << "Rank: ";
	//std::cin >> rank;
		
	// 11111111111111111111111111111111111111111111111111
	// rank = 4;	
	// 22222222222222222222222222222222222222222222222222
	// rank = 2;	
	// 33333333333333333333333333333333333333333333333333
	// rank = 3;	
	// 44444444444444444444444444444444444444444444444444
	 rank = 3;	

    std::cout << std::setprecision(3) << " "; 
	valCount = rank + 1;

	std::vector<double> xValVec( valCount ), yValVec( valCount );

	//initValues( xValVec, valCount, "x" );

	// 111111111111111111111111111111111111111111111111111111
	// xValVec = { 0, PI / 2, PI, 3 * PI / 2, 2 * PI }; 
	// 222222222222222222222222222222222222222222222222222222
	// xValVec = { 0, PI, 2*PI }; 
	// 333333333333333333333333333333333333333333333333333333
	// xValVec = { 0, PI / 4, PI / 2, PI }; 
	// 444444444444444444444444444444444444444444444444444444
	 xValVec = { 0, 0.5*PI, 1.5*PI, 2*PI }; 

	calculateYValues( xValVec, yValVec, valCount );

	printLagrangeGenericFormula( rank );
	std::cout << "\n\n";
	printLagrangeFormula( xValVec, yValVec, rank );


    // 11111111111111111111111111111111111111111111111111111
    // calculateR5( xValVec, valCount );
    // 22222222222222222222222222222222222222222222222222222
    // calculateR3( xValVec, valCount );
    // 33333333333333333333333333333333333333333333333333333
    // calculateR4( xValVec, valCount );
    // 44444444444444444444444444444444444444444444444444444
     calculateR4( xValVec, valCount );

	//double x = 0;
	//std::cout << "\n\nx: " << std::endl;
	//std::cin >> x;
	double x = 5.5;
	getLagrangePolynomialValue( xValVec, yValVec, rank, x );
    printYValue( x );

     
}

double calculateYValue( double x ) 
{
    return sin(x) + cos(x);
}

void printYValue( double x )
{
    std::cout << "\n\n--------------------Calculating y value for the given x"
              << "--------------------\n\n" << "f(" << x << ") = " 
              << calculateYValue( x ) << std::endl;
}

void calculateYValues( std::vector<double>& xValVec, 
					   std::vector<double>& yValVec, int valCount )
{
	for( int i = 0; i < valCount; ++i )
	{
		double x = xValVec[i];
		yValVec[i] = calculateYValue( x );
	}
}

void calculateThirdRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount )
{
	for( int i = 0; i < valCount; ++i )
	{
		double x = xValVec[i];
		yValVec[i] = sin(x) - cos(x);
	}
}

void calculateForthRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount )
{
	for( int i = 0; i < valCount; ++i )
	{
		double x = xValVec[i];
		yValVec[i] = sin(x) + cos(x);
	}
}
 
void calculateFifthRankDerivatives( std::vector<double>& xValVec, 
					                std::vector<double>& yValVec, int valCount )
{
	for( int i = 0; i < valCount; ++i )
	{
		double x = xValVec[i];
		yValVec[i] = cos(x) - sin(x);
	}
}

double calculateM3( std::vector<double>& xValVec, int valCount )
{
    std::vector<double> yValVec( valCount ); 
    
    calculateThirdRankDerivatives( xValVec, yValVec, valCount );
    
    return findMax( yValVec );
}

double calculateM4( std::vector<double>& xValVec, int valCount )
{
    std::vector<double> yValVec( valCount ); 
    
    calculateForthRankDerivatives( xValVec, yValVec, valCount );
    
    return findMax( yValVec );
}

double calculateM5( std::vector<double>& xValVec, int valCount )
{
    std::vector<double> yValVec( valCount ); 
    
    calculateFifthRankDerivatives( xValVec, yValVec, valCount );
    
    return findMax( yValVec );
}

double calculateD( std::vector<double>& xValVec, int valCount )
{
    std::cout << "\n\n--------------------calculating D" << valCount 
              << "--------------------\n\n";

    double max = std::numeric_limits<double>::lowest();

    for( int i = 0; i < valCount - 1; ++i )
    {
        double xMid = ( xValVec[i] + xValVec[i + 1] ) / 2,
               answer = 1;

        std::cout << "a" << i << " = ";
        for( int j = 0; j < valCount; ++j )
        {
            std::cout << "(" << xMid << " - " << xValVec[j] << ")";
            answer *= ( xMid - xValVec[j] );
            if( j != valCount - 1 )
                std::cout << "*";
            else 
                std::cout << " = " << answer << std::endl;
        }

        if( std::abs( answer ) > max )
            max = std::abs( answer );
    }

    return max;
}

double calculateR3( std::vector<double>& xValVec, int valCount )
{
    double M3 = calculateM3( xValVec, valCount ),
           D3 = calculateD( xValVec, valCount ),
           fact3 = calcFactorial( 3 ),
           R3 = M3 * D3 / fact3;
    
    std::cout << "\n\n--------------------Calculating R3 -------------------\n\n";
    std::cout << "M3: " << M3 << "\nD3: " << D3 << "\nR3 = M3 * D3 / 3! = " << R3 << "\n" << std::endl; 
   
    return M3 * D3 / fact3;
}

double calculateR4( std::vector<double>& xValVec, int valCount )
{
    double M4 = calculateM4( xValVec, valCount ),
           D4 = calculateD( xValVec, valCount ),
           fact4 = calcFactorial( 4 ),
           R4 = M4 * D4 / fact4;
    
    std::cout << "\n\n--------------------Calculating R4 -------------------\n\n";
    std::cout << "M4: " << M4 << "\nD4: " << D4 << "\nR4 = M4 * D4 / 4! = " << R4 << "\n" << std::endl; 
   
    return M4 * D4 / fact4;
}

double calculateR5( std::vector<double>& xValVec, int valCount )
{
    double M5 = calculateM5( xValVec, valCount ),
           D5 = calculateD( xValVec, valCount ),
           fact5 = calcFactorial( 5 ),
           R5 = M5 * D5 / fact5;
    
    std::cout << "\n\n--------------------Calculating R5 -------------------\n\n";
    std::cout << "M5: " << M5 << "\nD5: " << D5 << "\nR5 = M5 * D5 / 5! = " << R5 << "\n" << std::endl; 

   
    return M5 * D5 / fact5;
}
