echo "Enter number of integers"
read n
i=0
echo "Enter the numbers"
read a
min=$a
max=$a
n=`expr $n - 1`
while [ $i -lt $n ]
do
	read a
	if [ $a -lt $min ]
	then
		min=$a
	fi
	if [ $a -gt $max ]
	then
		max=$a
	fi
	i=`expr $i + 1`
done
echo "Maximum number : $max"
echo "Minimum number : $min"



'''
Output

$ sh Max_Min.sh
Enter number of integers
5
Enter the numbers
34
6
-8
12
-10
Maximum number : 34
Minimum number : -10
'''
