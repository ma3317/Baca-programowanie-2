//Magdalena Maksymiuk

int Cardinality(int set1)
{
    if(set1==0)
    {
        return 0;
    }
    else
    {   
        unsigned int set = set1;
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
