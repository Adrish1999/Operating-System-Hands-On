if [ $# = 0 ];
then 
	echo "No arguments specified, specify arguments in the order - Input Base<space>Number<space>Output Base"
	exit
fi

number=$2

if [ "$1" = "-b" ];
then    
    inType='2'
elif [ "$1" = "-o" ];
then    
    inType=8   
elif [ "$1" = "-d" ];
then    
    inType=10
elif [ "$1" = "-h" ];
then   
    inType=16
fi


if [ "$3" = "-b" ]; 
then    
    outType='2'
elif [ "$3" = "-o" ];
then    
    outType=8   
elif [ "$3" = "-d" ];
then    
    outType='10'
elif [ "$3" = "-h" ];
then    
    outType=16
fi


result=$(echo "obase=$outType;ibase=$inType;$number" | bc)
echo $result



: '

Output:


sh Base_Conversion.sh -d 12 -b
1100

'
