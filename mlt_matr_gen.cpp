#include "mymatr.h"
#include "mytex.h"

int main () {
rand_t nxn, diap1, diap2, max_det ;
	myVector empty ;
cin >> nxn >> diap1 >> diap2 >> max_det;
nxn = (nxn) ? nxn : 3 ;
if (nxn == -1) nxn=rand()%3 + 2 ;
diap1 = (diap1) ? diap1 : -7 ;
diap2 = (diap2) ? diap2 : 7 ;
max_det = (max_det) ? max_det : 5 ;


	myMatrix A(nxn, nxn) ;
	myMatrix B(nxn, nxn) ;
	myScalar det1;
	myScalar det2; 
	do {
		A.gen_rand(diap1, diap2) ;
		B.gen_rand(diap1, diap2) ;
		det1 = A.det1();
		det2 = B.det1();
	} while ( ! (abs(det1) < max_det && abs(det2 < max_det) ) ) ;

	myMatrix C = A*B;
	cout << "Найти произведение матриц:\n$$\n";
	cout << "A";
	tex_matrix(A) ;
	cout << "*B";
	tex_matrix(B) ;
	cout << "$$\n" ; 

	comment_matrix (C,"произведение") ;

	cerr << "Ответ:\n$$\n" ;
	cerr << "C = " ;
	tex_matrix(C, cerr) ;
	cerr << "$$\n" ;

}

