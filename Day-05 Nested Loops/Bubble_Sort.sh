echo "Enter the value of n :"
read n
echo "Enter $n numbers :"
i=0
   
while [ $i -lt $n ] 
do
    read arr[$i] 
    i=`expr $i + 1` 
done

echo "The numbers sorted in descending order are :"
for ((i = 0; i<$n; i++))  
do  
    for((j = 0; j<$n-i-1; j++)) 
    do
      
        if [ ${arr[j]} -lt ${arr[$((j+1))]} ] 
        then
            temp=${arr[j]} 
            arr[$j]=${arr[$((j+1))]}   
            arr[$((j+1))]=$temp 
        fi
    done
done
echo ${arr[*]} 



: '
Output


$ sh Sort.sh
Enter the value of n :
5
Enter 5 numbers :
19
30
3
45
2
The numbers sorted in descending order are :
45 30 19 3 2


'
