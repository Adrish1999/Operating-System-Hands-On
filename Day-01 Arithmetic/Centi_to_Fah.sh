echo "Enter temperature in degree Celsius"
read C
F=$(echo $C | awk '{ printf "%f", (($1 * 9)/5) + 32 }')
echo "$C degree Celsius = $F Fahrenheit" 
