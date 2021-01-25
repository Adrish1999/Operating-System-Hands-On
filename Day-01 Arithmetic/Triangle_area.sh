echo "Enter the base of the triangle: "
read base
echo "Enter the height of the triangle: "
read height
area=$(echo $base $height | awk '{ printf "%f", ($1 * $2)/2 }')
echo "Area of the triangle: $area"
