#include "include/Matrix.h"
#include "include/MatrixIO.h"
#include <complex>
#include <iomanip>

using namespace Numeric_lib;
using namespace std;

int sq(int x)
{	
	if(x<0) throw runtime_error("no square root");
	return sqrt(x);
}

int main()
{
	cout << "char size: " 		<< sizeof(char) 	<< '\n';
	cout << "short size: " 		<< sizeof(short) 	<< '\n';
	cout << "int size: " 		<< sizeof(int) 		<< '\n';
	cout << "long size: " 		<< sizeof(long) 	<< '\n';
	cout << "float size: " 		<< sizeof(float) 	<< '\n';
	cout << "double size: "		<< sizeof(double) 	<< '\n';
	cout << "int* size: " 		<< sizeof(int*) 	<< '\n';
	cout << "double* size: " 	<< sizeof(double*) 	<< '\n';

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10); 
	Matrix<int,3> e(10,10,10);

	cout << "a Matrix size: " << sizeof(a) << '\n';
	cout << "b Matrix size: " << sizeof(b) << '\n';
	cout << "c Matrix size: " << sizeof(c) << '\n';
	cout << "d Matrix size: " << sizeof(d) << '\n';
	cout << "e Matrix size: " << sizeof(e) << '\n';

	//3
	cout << "a Matrix size: " << a.size() << '\n';
	cout << "b Matrix size: " << b.size() << '\n';
	cout << "c Matrix size: " << c.size() << '\n';
	cout << "d Matrix size: " << d.size() << '\n';
	cout << "e Matrix size: " << e.size() << '\n';

	//4
	int test;

	cout << "Enter an intiger!\n";
	cin >> test;
	cout << sq(test) << '\n';

	//5
	Matrix<double> md(10);

	cout << "Enter ten doubles\n";
	for(int i = 0; i < md.size(); ++i)
		cin >> md[i];
	cout << "Your matrix => " << md << '\n';

	//6
	int m; int n;
	Matrix<int,2> table(n,m);

	cout << "Enter an m and n integer\n";
	cin >> m; cin >> n;

	for(Index i = 0; i < table.dim1(); ++i){
		for (Index j = 0; j < table.dim2(); ++j){
			table(i, j) = (i+1)*(j+1);
			cout << setw(3) << table(i,j);
		}
		cout << '\n';
	}

	//7
	Matrix<complex<double>> mc(10);
	complex<double> cp;
	complex<double> sum;

	cout << "Enter 10 complex nums like (Real,Imaginary): ";
	for (int i = 0; i < 10; ++i){
		cin >> cp;
		if(!cin)
			throw runtime_error("Problem reading complex number!");
		mc[i] = cp;
	}

	cout << "Complex matrix: " << mc << '\n';
	for (Index i = 0; i < mc.size(); ++i){
		sum += mc[i];
	}
	cout << "Sum: " << sum << '\n';

	//8
	Matrix<int,2> m23 (2,3);

	cout << "Enter 6 integers for a 2x3 Matrix:\n";
    for (int i = 0; i < m23.dim1(); ++i)
        for (int j = 0; j < m23.dim2(); ++j)
            cin >> m23[i][j];
    cout << "Your matrix -> "<< m23 << '\n';

	return 0;
}