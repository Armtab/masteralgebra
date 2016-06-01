#!/usr/bin/perl

$ans = `cat $ARGV[0]` ;
$ans =~ /\%определитель/;
$det = $';

$det =~ /\%о/;
$det = $`;
$det =~ s/://;
$det =~ s/\s//g;

#det is ok 
#print $ans;

$ans =~ /A=/;
$matrix = $';

$matrix =~ s/\s//;
$matrix =~ s/\%//g;
$matrix =~ s/\n//g;

#print $det;
#print $matrix;

@arr = split / /, $matrix;

$ret = 0;

$usr_ans = `cat $ARGV[1]` ;
$usr_ans =~ /rvs=/;
$usr_ans =$';


#print $usr_ans;
#here we have ann array of elems, but wery bad form

@usr_arr = split / /, $usr_ans;
$size = @arr;

foreach(@arr){
	print $_;
}
