echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Before swapping , the two numbers are: "
echo "First: $a , Second: $b"
a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`
echo "After swapping , the two numbers are: "
echo "First: $a , Second: $b"
