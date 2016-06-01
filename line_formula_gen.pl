#!/usr/bin/perl

if (! @ARGV) {
  print "Уравнение прямой\n" ;
}

@prog = split /\./, $0 ;
$zadacha = rand(3);
print `echo "$zadacha \n" | \.$prog[$#prog-1]` ;

