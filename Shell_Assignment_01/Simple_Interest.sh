#!/bin/bash
echo -n "Enter the principal amount: "
read p
echo -n "Enter the rate of interest: "
read r
echo -n "Enter the number of years: "
read t
interest=$(echo $p $r $t | awk '{ printf "%f", ($1 * $2 * $3)/100 }')
echo "Simple interest : $interest"
