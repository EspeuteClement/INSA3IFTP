EXEC=../sources/out/executable.out

echo -----------------------------------------------------------
echo Tests pour le binome B408: $EXEC
echo -----------------------------------------------------------

nTestCount=0
nSuccesfulTests=0
nStrResult="$EXEC "

file1=add.1
file2=add.2
file3=testOPT
file4=viciousTests

echo $file1
let "nTestCount=$nTestCount+1"
./$EXEC < $file1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB $file1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo $file2
let "nTestCount=$nTestCount+1"
./$EXEC < $file2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB $file2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo $file3
let "nTestCount=$nTestCount+1"
./$EXEC < $file3.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB $file3.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo $file4
let "nTestCount=$nTestCount+1"
./$EXEC < $file4.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB $file4.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo -----------------------------------------------------------
echo RESULTS
echo -----------------------------------------------------------
echo Results: $nSuccesfulTests/$nTestCount
echo CSVLine: $nStrResult
echo $nStrResult >> results.txt
