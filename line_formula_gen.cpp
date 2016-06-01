#include "mymatr.h"
#include "mytex.h"
#include <math.h>
#include "myqvect.h"


myVector line_eqn (myVector n, myVector A, int normal=1){
  myVector l_eqn(3) ;
  l_eqn[0] = (normal) ? n[0] : (-1)*n[1] ;
  l_eqn[1] = (normal) ? n[1] : n[0] ;
  l_eqn[2] = -(l_eqn[0]*A[0]+l_eqn[1]*A[1]) ;  
  l_eqn = ( l_eqn[0]<0 || (l_eqn[0]==0 && l_eqn[1]<0) ) ? (myScalar)(-1)*l_eqn : l_eqn ;
  l_eqn.socr() ;
  return l_eqn ;
}

void tex_line_eqn (myVector line, ostream& out=cout) {
  string sign ;
  if (line[0]!=0) {
	if (line[0]!=1) out << line[0] ;
	out << "x" ;
	sign="~+~" ;
  }
  else 	sign="" ;
  
  if (line[1]!=0) {
  	out << ( (line[1]>0) ? sign : "~-~" ) ;
	if (abs(line[1])!=1) out << abs(line[1]) ;
	out << "y" ;
  }
  
  if (line[2]!=0) {
  	out << ( (line[2]>0) ? "~+~" : "~-~" ) ;
	out << abs(line[2]) ;
  }
  out << "~=~0" ;
}

myVector v_prod (myVector v, myVector w) {
  myVector pr(3) ;
  pr[0] = v[1]*w[2]-v[2]*w[1] ;
  pr[1] = v[2]*w[0]-v[0]*w[2] ;
  pr[2] = v[0]*w[1]-v[1]*w[0] ;
  return pr ;
}


int main () {
  
  myMatrix data (3, 2) ;
  myMatrix vect (2, 2) ;
  int prob_type;
  std::cin>>prob_type;
  do {
	myMatrix tmp ("rand", 3, 2) ;
	vect[0] = tmp[1]-tmp[0] ;
	vect[1] = tmp[2]-tmp[0] ;
	data = tmp ;
  } while (vect.rk() != 2) ;
  
  myMatrix vect1=vect ;
  vect[0].socr() ;
  vect[1].socr() ;
  
  myVector a = myrand(3)*vect[0] ;
  myVector b(2), bb= myrand(3)*vect[1] ;
  
  b[0]=-bb[1] ; b[1]=bb[0] ;
    
cout << "Даны два вектора $\\vec{a},~\\vec{b}$ и две точки $M_1,~M_2$ на плоскости.\n"
  << "Написать общeе уравнениe (с целочисленными коэффициентами) ";
  if(prob_type == 0){
     cout << "прямой $l_0~=~M_1M_2$\n";
     cout << "\n\n\\begin{tabular} {ll}\n"
	<< "$M_1~=~" ; tex_vect(data[1]); 
     cout << "$ & $M_2~=~" ; tex_vect(data[2]) ;
}
else if (prob_type == 1){
	 cout << "прямой $l_0$ проходящей через точку $M_1$\n"
 	 << "с направляющим вектором $\\vec{a}$\n";
	cout << "\n\n\\begin{tabular} {ll}\n"
	 << "$M_1~=~" ; tex_vect(data[1]) ;
	cout << "$ & $\\vec{a}~=~" ; tex_vect(a) ;
}
else if (prob_type == 2){
	cout<< "прямой $l_0$ проходящей через точку $M_2$\n"
  	<< "с нормальным вектором $\\vec{b}$. \n\n";
	cout << "\n\n\\begin{tabular} {ll}\n";
	cout << "$M_2~=~" ; tex_vect(data[2]) ;
	cout << "$ & $\\vec{b}~=~" ; tex_vect(b) ;
}
// cout << "\n\n\\begin{tabular} {ll}\n"
//  << "$M_1~=~" ; tex_vect(data[1]) ;
//cout << "$ & $\\vec{a}~=~" ; tex_vect(a) ;
//cout << "$ \\\\ $M_2~=~" ; tex_vect(data[2]) ;
//cout << "$ & $\\vec{b}~=~" ; tex_vect(b) ;
 cout << "$\\\\\n \\end {tabular}\n";


	cerr << "Ответ:\n\n" ;
	myMatrix l(5,3) ;
	
	myMatrix m_out2(1,2) ;
	myMatrix m_out3(1,3) ;

  l[0] = line_eqn (data[2]-data[1], data[1], 0) ;
  l[1] = line_eqn (vect[0], data[1], 0) ;
  l[2] = line_eqn (vect[1], data[2], 0) ;
 
  if(prob_type == 0){
  	cerr << "$l_0~:~$"	; tex_line_eqn(l[0], cerr) ; cerr << "\n\n" ;
	m_out3[0]=l[0] ;
        comment_matrix(m_out3,"l0") ;
  } 
  else if (prob_type ==1){	
  	cerr << "$l_0~:~$"	; tex_line_eqn(l[1], cerr) ; cerr << "\n\n" ;
	m_out3[0]=l[1] ;
	comment_matrix(m_out3,"l0") ;
  }else if (prob_type ==3){
  	cerr << "$l_0~:~$"	; tex_line_eqn(l[2], cerr) ; cerr << "\n\n" ;
	comment_matrix(m_out3,"l0") ;
  }
 // if(prob_type == 0){
  //	m_out3[0]=l[0] ;
  //	comment_matrix(m_out3,"l0") ;
//  }else if(prob_type ==1){
//  	m_out3[0]=l[1] ;
//  	comment_matrix(m_out3,"l0") ;
//  }else if(prob_type ==2){
//  	m_out3[0]=l[2] ;
//  	comment_matrix(m_out3,"l0") ;
//  } 
  return 0 ;
}


