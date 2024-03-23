//Magdalena Maksymiuk

void Print2(int num, char* set,  int k)
{
    int i=31-k;
    int z;
    
    
        int x=1<<(i); //bit ktory sprawdzamy czy jest w zbiorze num
        //std::cout<<x<<std::endl;
        
            if(i==31)
            {
                 if((num&x)!=0)
                 {
                    (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                   
            }
            else if(i==30)
            {
                if((num&x)!=0)
                 {
                    (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                   
            }
            else if(i==29)
            {
                    if((num&x)!=0)
                 {
                    (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                   
            }
            else if(i==28)
            {
                if((num&x)!=0)
                 {
                    (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==27)
            {
                    if((num&x)!=0)
                 {
                    (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                
            }
            else if(i==26)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==25)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                
                    //z=num^i;
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==24)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==23)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==22)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==21)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==20)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==19)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==18)
            {
             if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }   
            }
            else if(i==17)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==16)
            {
                if((num&x)!=0)
                 {
                        (*set)='1';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                
            }
            else if(i==15)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==14)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==13)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==12)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==11)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==10)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==9)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==8)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='1';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==7)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==6)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==5)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==4)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='1';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
                
            }
            else if(i==3)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==2)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='1';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==1)
            {
                if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='1'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
            else if(i==0)
            {
                 if((num&x)!=0)
                 {
                        (*set)='0';  
                    (*(set+1))='0';  
                    (*(set+2))='0';  
                    (*(set+3))='0';  
                    (*(set+4))='0'; 
                    (*(set+5))=' '; 
                    Print2(num,(set+6),k+=1);
                 }
                 else
                 {
                     Print2(num,set,k+=1);
                 }
            }
           else
            {
                 (*(set))='\0';
            }
    
}
void Print(int num, char* set)
{
    //unsigned int num2 = num;
    if(num==0)
    {
        (*set)='e';
        (*(set+1))='m';
        (*(set+2))='p';
        (*(set+3))='t';
        (*(set+4))='y';
        (*(set+5))='\0';
    }
    else 
    {
        int i=0;
        Print2(num,set,i);
    }
   
}