echo "Enter the first number"
read a
echo "Enter the second number"
read b
if [ $a -gt $b ];
then
	echo "First number $a is greater"
else
	echo "Second number $b is greater"
fi
