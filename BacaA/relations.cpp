//Magdalena Maksymiuk
int Card(int set1)
{
    if(set1==0)
    {
        return 0;
    }
    else
    {   
        //unsigned int set = set1;
	int set=set1;
        int out=0;
        if((set&(1<<0)))
        {
            out+=1;
        }
        
        if((set&(1<<1)))
        {
            out+=1;
        }
        if((set&(1<<2)))
        {
            out+=1;
        }
        if((set&(1<<3)))
        {
            out+=1;
        }
        if((set&(1<<4)))
        {
            out+=1;
        }
        if((set&(1<<5)))
        {
            out+=1;
        }
        if((set&(1<<6)))
        {
            out+=1;
        }
        if((set&(1<<7)))
        {
            out+=1;
        }
        if((set&(1<<8)))
        {
            out+=1;
        }
        if((set&(1<<9)))
        {
            out+=1;
        }
        if((set&(1<<10)))
        {
            out+=1;
        }
        if((set&(1<<11)))
        {
            out+=1;
        }
        if((set&(1<<12)))
        {
            out+=1;
        }
        if((set&(1<<13)))
        {
            out+=1;
        }
        if((set&(1<<14)))
        {
            out+=1;
        }
        if((set&(1<<15)))
        {
            out+=1;
        }
        if((set&(1<<16)))
        {
            out+=1;
        }
        
        if((set&(1<<17)))
        {
            out+=1;
        }
        
        if((set&(1<<18)))
        {
            out+=1;
        }
        if((set&(1<<19)))
        {
            out+=1;
        }
        if((set&(1<<20)))
        {
            out+=1;
        }
        
        if((set&(1<<21)))
        {
            out+=1;
        }
        
        if((set&(1<<22)))
        {
            out+=1;
        }
        
        if((set&(1<<23)))
        {
            out+=1;
        }
        
        if((set&(1<<24)))
        {
            out+=1;
        }
        
        if((set&(1<<25)))
        {
            out+=1;
        }
        
        if((set&(1<<26)))
        {
            out+=1;
        }
        if((set&(1<<27)))
        {
            out+=1;
        }
        
        if((set&(1<<28)))
        {
            out+=1;
        }
        if((set&(1<<29)))
        {
            out+=1;
        }
        if((set&(1<<30)))
        {
            out+=1;
        }
        if((set&(1<<31)))
        {
            out+=1;
        }
        
        return out;
    }
}

bool LessThen(int set_1, int set_2)
{
	int pow1=Card(set_1);
	int pow2=Card(set_2);
	if(pow1 == pow2)
	{

		if(set_1 < set_2)
		{
			return 1;
		}
		else return 0;
	}
	else if (pow1 < pow2 )
	{
		return 1;
	}
	else
	return 0;
}

bool LessEqual(int set_1, int set_2)
{
	int pow1=Card(set_1);
	int pow2=Card(set_2);
	return((pow1<pow2) || (pow1==pow2 && set_1 <= set_2));
}

bool GreatEqual(int set_1, int set_2)
{
	return LessEqual(set_2, set_1);
}

bool GreatThen(int set_1, int set_2)
{
	return LessThen(set_2, set_1);
}