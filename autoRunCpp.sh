
# This script will find out the number for which algorithm takes more then 1 second.
num=1
limit=1    # Seconds

while true
do
    SECONDS=0
    ./a.out $num
    duration=$SECONDS
    if(($duration >= $limit))
    then
        break
    fi
    num=`expr $num + 1`
done



echo "$num : For this value alog took more than $limit second"