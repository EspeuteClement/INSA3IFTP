for i in Test*
do
	cd $i
	echo "Génération du $i :"
	cat genererNouveauTest.sh
	./genererNouveauTest.sh
	cd ..
done