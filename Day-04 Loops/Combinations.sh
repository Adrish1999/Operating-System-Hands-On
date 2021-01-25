echo "Enter 3 numbers"
read num1
read num2
read num3

echo "All possible combinations of $num1 , $num2 and $num3 are :"

for i in $num1 $num2 $num3
do
	for j in $num1 $num2 $num3
	do
		for k in $num1 $num2 $num3
		do
			echo "$i$j$k"
		done
	done
done






: '
Output


$ sh Combinations.sh
Enter 3 numbers
5
4
6
All possible combinations of 5 , 4 and 6 are :
555
554
556
545
544
546
565
564
566
455
454
456
445
444
446
465
464
466
655
654
656
645
644
646
665
664
666
'
