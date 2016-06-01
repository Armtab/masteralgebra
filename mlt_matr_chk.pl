#!/usr/bin/perl

$ans = `cat $ARGV[0]` ;
$ans =~ /\%произведение=/;
$matr = $';
#print $matr;

$matr =~ s/\%//g;
$matr =~ s/ //g;

$ret = 0;

$usr_ans = `cat $ARGV[1]` ;

$usr_ans =~ /C=/;
$usr_matr = $';

$usr_matr =~ s/ //g;

if($usr_matr == " "){
        print "<br><font color=red>Вы не ввели матрицу</font>";
	exit($ret);
}
if($usr_matr !=  $matr){
        print "<br><font color=red>Ответ неправильный</font>";
	exit($ret);
}
if($usr_matr == $matr){
         print "<br><font color=green>Ответ правильный</font>";
        $ret +=3;
}
exit($ret);



