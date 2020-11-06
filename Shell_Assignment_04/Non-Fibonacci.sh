echo "Enter the limit n"
read n

a=0
b=1

if [ $n -eq $a ]
then
	echo "No non-fibonacci terms upto $a"
elif [ $n -eq $b ]
then
	echo "No non-fibonacci terms upto $b"
else
	echo "The non-fibonacci terms upto $n are :"
	
	while true
	do
		c=`expr $a + $b`
		i=`expr $a + 1`
		if [ $b -le $n ]
		then
			while [ $i -lt $b ]
			do
				echo "$i"
				i=`expr $i + 1`
			done
		else
			break
		fi
		a=$b
		b=$c
	done
fi







: '
Output


$ sh Non-Fibonacci.sh
Enter the limit n
21
The non-fibonacci terms upto 21 are :
4
6
7
9
10
11
12
14
15
16
17
18
19
20
'
