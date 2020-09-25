echo "Enter the file name from where to display lines"
read filename
if [ -e $filename ];
then
	echo "Enter the starting line number: "
	read start
	echo "Enter the number of lines to display: "
	read n
	c=`expr $start + $n`
	head -n $c $filename | tail -$n
else
	echo "No such file exists"
fi
