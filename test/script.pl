#!/bin/perl
#
# Date : 14/05/10
# Made by alexandre strzelewicz
# Login   <strzel_a@epitech.net>
# Blog : www.hemca.com
#
# Ce script est une moulinette pour le 42sh
# chmod 777 moulinette.perl
# Creez un fichier [SOURCE CMD], mettez vos commandes et sautez une ligne entre chaque
# Usage = ./moulinette.perl [SOURCE CMD]
#

if (!$ARGV[0])
{
    die "Usage = ./moulinette.perl [SOURCE CMD]\n";
}

unless (open(FILE, $ARGV[0])) {
    die "Impossible d'ouvrir le fichier\n"
}

$i = 0;
$string;
$line;

print "\nmoumou anti-astek :p\n";
@line = <FILE>;
close(FILE);

while ($str = $line[$i]) {
    chop($line[$i]);
    $cmd = "echo \"" . $line[$i] . "\" | ./42sh\n" ;
    if (!(lc($line[$i]) eq ""))
    {
	print "\n\033[34;1mTest numero " . $i . " avec la commande : \033[32;1m"
	    . $line[$i] . "\n\033[0m";
    }
    $status = system($cmd);
    if ($status == 35584)
    {
	print "\033[41;1m------- >>>>>>>>> SIGSEGV <<<<<<<<< --------\033[0m";
    }
    elsif ($status > 0)
    {
	print "\033[41;1m------- >>>>>>>>> OTHER SPE SIGNAL = " . $status . "<<<<<<<<< --------\033[0m\n";
    }
    $i = $i + 1;
}
