#!/usr/bin/perl

$ans = `cat $ARGV[0]` ;
$ans =~ /\%определитель/;
$det = $';
$det =~ s/ //;
$det =~ s/://;



$usr_ans = `cat $ARGV[1]`;
$usr_ans =~ /det=/;
$usr_det = $';

$usr_det =~ s/ //g;


$ret = 0 ;

if ($usr_det == "") {
  print "<br><font color=red>Вы не ввели значение определителя</font>";
}
elsif ($det != $usr_det) {
  print "<br><font color=red>Неверно вычислен определитель</font>" ;
}
else {
  print "<br><font color=green> Определитель вычислен верно</font>" ;
  $ret += 1 ;
}

exit ($ret) ;

