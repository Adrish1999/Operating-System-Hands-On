echo -n "Enter the principal amount: "
read p
echo -n "Enter the rate of interest: "
read r
echo -n "Enter the number of years: "
read t
interest = $(echo "($p * $r * $t)/100"|bc)
echo "Simple interest: " $interest
