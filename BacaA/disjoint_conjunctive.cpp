//Magdalena Maksymiuk
bool Disjoint(int set1, int set2)
{
	
	if((set1&set2))
	{
		return 0;	
	}
	else
	{
		return 1;
	}

}
bool Conjunctive ( int set1, int set2 )
{
	if((set1&set2))
	{
		return 1;	
	}
	else
	{
		return 0;
	}
}
