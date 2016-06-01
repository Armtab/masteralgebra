#include "mymatr.h"
#include "mytex.h"

int main () {
rand_t nxn, diap1, diap2, max_det ;
cin >> nxn >> diap1 >> diap2 >> max_det;
nxn = (nxn) ? nxn : 3 ;
    //if (nxn ==0) nxn = 3
if (nxn == -1) nxn=rand()%3 + 2 ;
    //if(n==-1) nxn = {2,3,4}
diap1 = (diap1) ? diap1 : -7 ;
    //if(diap1 ==0) diap1 = -7
diap2 = (diap2) ? diap2 : 7 ;
    //if(diap2 == 0)diap2 = 7;
max_det = (max_det) ? max_det : 5 ;
    //if(max_det == 0) max_det = 5;
    //xleft == 0 or 1


	myMatrix A(nxn, nxn) ;
    //n*n matrix
	myScalar det ;
    //int det

	do {
		A.gen_rand(diap1, diap2) ;
        //generate matrix a with nums in diapazone (diap1, diap2)
		det = A.det1();
        //get the A matrix det
	} while ( ! ( det != 0 && abs(det) < max_det ) ) ;
    //as soon as det != 0 and det is lower than fixed num

	//myMatrix B(nxn, nxn) ;
	//myMatrix X("rand", nxn, nxn, diap1, diap2) ;

	//	B = (xleft) ? X*A : A*X ;

	cout << "Найти oбратную матрицу:\n$$\n" ;
	//if (xleft) cout << "X " ;
	cout << "A = ";
	tex_matrix(A) ;// ****this goes for texlife****
	//const char *sign = (xleft) ? " = " : "X = " ;
	//cout << sign ;
	//tex_matrix(B) ;
	cout << "$$\n" ;

	//comment_matrix (X,"X") ;
	myMatrix D=A.rvs() ;
	cout << "%определитель: " << det << endl ;
	comment_matrix (D ,"обратная к A") ;

	cerr << "Ответ:\n$$\n" ;
	cerr<< "обратная матрица А ";
	//cerr << "X = " ;
	//tex_matrix(X, cerr) ;
	cerr << "\\quad A^{-1} = \\frac{1}{" << D[0].idenom << "}" ;
	tex_matrix(D, cerr) ;
	cerr << "$$\n" ;
	
}

