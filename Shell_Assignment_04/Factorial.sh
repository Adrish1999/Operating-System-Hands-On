echo -n "Enter a number: "
read number

factorial=1
a=0

if [ $number -lt $a ]
then
	echo "Factorial of $number is not possible"
elif [ $number -eq $a ]
then
	echo "Factorial of $number is $factorial"
else
	for(( i=1; i<=number; i++ ))
	do
  	factorial=$[ $factorial * $i ]
	done

	echo "The factorial of $number is $factorial"
fi





: '
Output


$ sh Factorial.sh
Enter a number: 8
The factorial of 8 is 40320
'
