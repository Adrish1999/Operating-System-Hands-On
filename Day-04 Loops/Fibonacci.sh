echo "Enter the limit n"
read n

a=0
b=1
echo "The Fibonacci terms upto $n are :"
echo "$a"
echo "$b"
c=`expr $a + $b`
while true
do
	c=`expr $a + $b`
	if [ $c -le $n ]
	then
		echo "$c"
	else
		break
	fi
	a=$b
	b=$c
done







: '
Output


$ sh Fibonacci.sh
Enter the limit n
20
The Fibonacci terms upto 20 are :
0
1
1
2
3
5
8
13
'
