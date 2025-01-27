
#include "../../headers/utils.h"


bool vrb_txt_valid(t_info_texture *txt)
{
    if(!txt->ceiling ||!txt -> floor)
            return(false);
    if(!txt ->direct_east  ||!txt ->direct_north  || !txt->direct_south)
            return(false);
    if(!txt ->direct_west)
            return(false);
}