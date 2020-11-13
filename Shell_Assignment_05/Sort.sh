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
