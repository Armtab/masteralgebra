#!/usr/bin/perl

$ans = `cat $ARGV[0]` ;
#print $ans;
$ans =~ /\%/ ;
$ans = $' ;
$ans =~ y/\n\t\r\%\+ /      /s ;
$ans =~ s/ +/ /g ;

 
$ans =~ /l0=/ ; $l0 = $' ; @l0 = split " ", $l0 ;
#print $ans;
$usr_ans = `cat $ARGV[1]` ;
$usr_ans =~ y/\n\t\r\%\+ /      /s ;
$usr_ans =~ s/ //g ;

#print $usr_ans;

$usr_ans =~ /l0=/ ; $usr_l0 = $' ; @usr_l0 = _convert ($usr_l0);


$ret=0 ;
if ($usr_l0 eq "") {
  print "<br><font color=red>Вы не ввели уравнение прямой <i>l<sub>0</sub></i> </font>"
}
elsif (_compare(\@l0,\@usr_l0)==0) {
  print "<br><font color=red>Неверно вычислено уравнение прямой <i>l<sub>0</sub></i></font>" ;
}
elsif (_compare(\@l0,\@usr_l0)==1) {
  print "<br><font color=green> уравнение прямой <i>l<sub>0</sub></i> вычислено верно</font>" ;
  $ret += 10 ;
}
 

exit ($ret) ;

sub _convert ($) {
  my $rest=$_[0] ;

  $rest =~ y/\n\t\r\+ / /s ;
  $rest =~ s/ //g ;

  if ($rest=~/x/)  {
	$res[0]=$`; $rest=$';
	if($res[0] eq "") {$res[0]=1} ;
	if($res[0] eq "-") {$res[0]=-1} ;
  } 
  else {$res[0]=0} ;
  if ($rest=~/y/) {
	$res[1]=$`; $rest=$' ;
	if($res[1] eq "" ) {$res[1]=1} ;
	if($res[1] eq "-") {$res[1]=-1} ;	
  } 
  else {$res[1]=0};
  $rest=~/=/ ; $res[2]=$` ;
  return @res ;  
}

sub _compare  {
  *v = @_[0] ;
  *w = @_[1] ;
  if	( $v[0]*$w[1]-$v[1]*$w[0]==0 && $v[0]*$w[2]-$v[2]*$w[0]==0 
		  && ($v[0]!=0 || $v[1]!=0) && ($w[0]!=0 || $w[1]!=0) ) {
	return 1 ;
  }
  else {return 0} 
}

