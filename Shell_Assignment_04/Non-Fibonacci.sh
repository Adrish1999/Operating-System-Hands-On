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
		i=`expr $a + 1`
		while [ $i -lt $b ]
		do
			echo "$i"
			i=`expr $i + 1`
		done
		c=`expr $a + $b`
		a=$b
		b=$c
		if [ $b -gt $n ]
		then
			j=`expr $a + 1`
			while [ $j -le $n ]
			do
				echo "$j"
				j=`expr $j + 1`
			done
			break
		fi
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
