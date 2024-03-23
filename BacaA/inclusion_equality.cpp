//Magdalena Maksymiuk

bool Inclusion(int set1, int set2)
{
unsigned int set11= set1;
unsigned int set22 = set2;
//zawieranie sie
if(set2==set1)
return 1;
else if(set11 <= set22)
return 1;
else 
return 0;

}

bool Equality(int set1, int set2)
{
	if(set2==set1)
	return 1;
	else 
	return 0;
}