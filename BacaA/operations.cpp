//Magdalena Maksymiuk

void Union(int set1, int set2, int* union_set)
{
    (*union_set)=(set1 | set2);
}

void Intersection(int set1, int set2, int* intersection_set)
{
 (*intersection_set)=(set1&set2);
}


void Difference (int set1, int set2, int* diff_set)
{
 	int inter=(set1 & set2);
	(*diff_set)=(set1 ^ inter);
}

void Complement(int set, int* comp_set)
{
    (*comp_set)=(~set);
}

void Symmetric(int set1, int set2, int* symmetric_set)
{
	int sum = (set1 | set2);
	int inter =( set1 & set2);
	 
	(*symmetric_set)=(sum^inter);
}



