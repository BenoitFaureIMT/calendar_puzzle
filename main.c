//---------Grid Logic---------

//Structure to define a grid
typedef struct grid_structure{
    int w;
    int h;
    int *data[];
}grid;

//Grid for check_terminal_grid function to return
struct terminal_return_structure{
    date *date;
    int terminal; //terminal category (see readme)
};

//Function to check if a grid is terminal, returns 
//  0 -> Not terminal (more than 3 cells free)
//  1 -> positive terminal
//  2 -> negative terminal
int is_grid_terminal(grid *grid_obj, date *date_obj){
    int month_index = -1;
    int number_index = -1;
    int day_index = -1;

    int negative = 1;
    int count = 0;

    //Get if terminal - and get terminal category
    for (int i = 0; i < grid_obj->w * grid_obj->h; i++){
        int c = grid_obj->data[i];

        if (!(c == 0)){
            if(c == 1){
                if(month_index > -1)
                    negative = 2;
                else
                    month_index = i;
                
                count++;
            }else if (c == 2){
                if (number_index > -1)
                    negative = 2;
                else
                    number_index = i;
                
                count++;
            }else if (c == 3){
                if (day_index > -1)
                    negative = 2;
                else
                    day_index = i;
                
                count++;
            }
        }

        //Return not terminal
        if(count > 3)
            return 0;
    }

    //Return negative terminal
    if (negative == 2)
        return negative;

    //Make date
    date_obj->month = get_month(month_index);
    date_obj->number = get_number(number_index);
    date_obj->day = get_day(day_index);

    return 2;
}

//---------Date Logic---------

//Structure to define a date
typedef struct date_structure{
    int month; //month number
    int number;
    int day; //day number

}date;

int get_month(int index){
    if (index < 6)
        return index + 1;
    
    return index;
}

int get_number(int index){
    return index - 13;
}

int get_day(int index){
    if (index < 49)
        return index - 44;

    return index - 52;
}

//------Shape Logic-------
typedef struct shape_structure{
    int w;
    int h;
    int *data[];
}shape;

shape* get_shape(int loc){
    return (shape*)loc;
}

void make_shape_rotations(shape* shapes[], shape* new_shapes[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 4; j++){
            switch(j){
                case 1: //90 deg clockwise
                    shape *source_shape = get_shape(shapes[i]);
                    shape *n_shape = (shape*)malloc(sizeof(shape));

                    n_shape->w = source_shape->h;
                    n_shape->h = source_shape->w;

                    int ns_data[source_shape->w * source_shape->h];
                    for (int y = 0; y < n_shape->h; y++)
                        for (int x = 0; x < n_shape->w; x++)
                            ns_data[y * n_shape->w + x]  = source_shape->data[x * source_shape->h + y];

                    //n_shape->data = ns_data;
                    new_shapes[i + j] = n_shape;
                case 2: //180 deg clockwise
                    shape *source_shape = get_shape(shapes[i]);
                    shape *n_shape = (shape*)malloc(sizeof(shape));

                    n_shape->w = source_shape->w;
                    n_shape->h = source_shape->h;

                    int ns_data[source_shape->w * source_shape->h];
                    int tot_size_adjusted = source_shape->w * (source_shape->h - 1);
                    for (int y = 0; y < n_shape->h; y++)
                        for (int x = 0; x < n_shape->w; x++)
                            ns_data[y * n_shape->w + x]  = source_shape->data[tot_size_adjusted - y * source_shape->w + x];
                    
                    //n_shape->data = ns_data;
                    new_shapes[i + j] = n_shape;
                case 3: //270 deg clockwise
                    shape *source_shape = get_shape(shapes[i]);
                    shape *n_shape = (shape*)malloc(sizeof(shape));

                    n_shape->w = source_shape->h;
                    n_shape->h = source_shape->w;

                    int ns_data[source_shape->w * source_shape->h];
                    for (int y = 0; y < n_shape->h; y++)
                        for (int x = 0; x < n_shape->w; x++)
                            ns_data[y * n_shape->w + x]  = source_shape->data[x * source_shape->h + n_shape->w - y];
                    
                    //n_shape->data = ns_data;
                    new_shapes[i + j] = n_shape;
                default: //case 0 -> no rotation
                    new_shapes[i + j] = shapes[i];
            }
        }
    }
}

typedef struct shape_list_structure{ //Maybe better to do as an array instead
    shape *shape;
    shape_list *next;
}shape_list;

//--------Node logic---------
typedef struct node_structure{
    grid *grid;
    shape *shape;
    shape_list *left;
    node *parent;
}node;

typedef struct node_list_structure{
    node *node;
    node_list *next;
}node_list;

//Recursive function for node exploration
void recursive_node_exploration(node *root, node_list *next){

}

//---------Main Function---------
void main(){
    //--------Create Grid----------
    int data[56] = {
        1, 1, 1, 1, 1, 1, 0,
        1, 1, 1, 1, 1, 1, 0,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 1, 1, 1
    };
    
    //-------Generate Shapes-------
    shape *s1;
    s1->w = 2;
    s1->h = 4;
    int s1_data[8] = {
        0, 1,
        0, 1,
        0, 1,
        1, 1
    };
    // s1->data = *s1_data;

    shape *s2;
    s2->w = 3;
    s2->h = 3;
    int s2_data[9] = {
        0, 1, 0,
        0, 1, 0,
        1, 1, 1
    };
    // s2->data = *s2_data;

    shape* temp_shape_array[2] = {s1, s2};
    shape* shape_array[8];
    make_shape_rotations(temp_shape_array, shape_array, 2);

    //------Initialize node graph-------


}