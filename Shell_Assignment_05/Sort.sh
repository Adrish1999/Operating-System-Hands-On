echo "Enter the value of n :"
read n
echo "Enter $n numbers :"
i=1
> numbers.txt
while [ $i -le $n ]
do
	read a
	echo $a >> numbers.txt
	i=`expr $i + 1`
done
echo "The numbers sorted in descending order are :"
sort -nr numbers.txt




: '
Output


$ sh Sort.sh
Enter the value of n :
10
Enter 10 numbers :
6
32
15
80
23
55
11
76
43
20
The numbers sorted in descending order are :
80
76
55
43
32
23
20
15
11
6
'
