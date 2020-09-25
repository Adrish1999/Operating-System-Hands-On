echo "Enter a text: "
read text
w=`echo $text | wc -w`
w=`expr $w`
c=`echo $text | wc -c`
c=`expr $c - 1`
s=0 
alpha=0 
j=` ` 
n=1

while [ $n -le $c ] 
do 
	ch=`echo $text | cut -c $n` 
	if [ $ch -eq $j ]; 
	then 
		s=`expr $s + 1` 
	fi
 
	case $ch in 
		[A-Z])	alpha=`expr $alpha + 1`;;
 		[a-z])	alpha=`expr $alpha + 1`;;
	esac
 
	n=`expr $n + 1`
done
 
special=`expr $c - $s - $alpha`

echo "Number of words : $w"
echo "Number of characters : $c"
echo "Number of white spaces : $s"
echo "Number of special symbols : $special"
