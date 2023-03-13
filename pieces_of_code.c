//Is index -> month, number or day (0, 1, 2, 3 -> none)
int index_category(int index){
    if(index < 0)
        return 3;

    if(index < 13){
        if(index != 7)
            return 0;
        else
            return 3;
    }
    
    if(index < 45)
        return 1;
    
    if(index > 48 && index < 53)
        return 3;
    
    if(index < 56)
        return 2;

    return 3;
}

//Assign index to date returns category of assignement
int assign_to_date(int index, date *date_obj){
    int c1 = index_category(index);

    if (c1 == 3)
        return 0;

    if (c1 == 0){
        if (index < 6)
            date_obj->month = index + 1;
        else
            date_obj->month = index;
    }else if (c1 == 1)
        date_obj->number = index - 13;
    else if (c1 == 2){
        if (index < 49)
            date_obj->day = index - 44;
        else
            date_obj->day = index - 52;
    }
    return 1;
}