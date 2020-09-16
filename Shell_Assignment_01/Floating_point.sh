echo "Enter the first floating point number: "
read a
echo "Enter the second floating point number: "
read b
addition=$(echo $a $b | awk '{ printf "%f", ($1 + $2) }')
subtraction=$(echo $a $b | awk '{ printf "%f", ($1 - $2) }')
multiplication=$(echo $a $b | awk '{ printf "%f", ($1 * $2) }')
division=$(echo $a $b | awk '{ printf "%f", ($1 / $2) }')
echo "$a + $b = $addition"
echo "$a - $b = $subtraction"
echo "$a * $b = $multiplication"
echo "$a / $b = $division"


